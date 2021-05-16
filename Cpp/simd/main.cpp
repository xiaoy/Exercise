#define PICOBENCH_IMPLEMENT_WITH_MAIN 
#include "picobench.hpp"

#include <random>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <immintrin.h>

using namespace std;

#define FLOAT_NUMS 4096
#define VECTOR_NUMS FLOAT_NUMS/4
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<float> dis(1.0f, 2.0f);

float float_arr[FLOAT_NUMS];

float* get_float_arr(){
    for(size_t i = 0; i < FLOAT_NUMS; ++i)
    {
        float_arr[i] = dis(gen);
    }
    return float_arr;
}

struct Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct Vec4_AOS
{
    float* x;
    float* y;
    float* z;
    float* w;
};

float squared_dis(const Vec4& v1, const Vec4& v2)
{
    float detx = v1.x - v2.x;
    float dety = v1.y - v2.y;
    float detz = v1.z - v2.z;
    float detw = v1.w - v2.w;
    return detx * detx + dety * dety + detz * detz + detw * detw;
}

float simd_squared_dis(const Vec4& v1, const Vec4& v2)
{
    __m128 m1 = _mm_load_ps(&v1.x);
    __m128 m2 = _mm_load_ps(&v2.x);
    __m128 m = _mm_sub_ps(m1, m2);
    __m128 ret = _mm_mul_ps(m, m);
    __m128 tmp = _mm_shuffle_ps(ret, ret, _MM_SHUFFLE(0, 0, 3, 2));     // z1*z2, w1*w2, z1*z2, w1*w2    
    tmp = _mm_add_ps(tmp, ret);
    ret = _mm_shuffle_ps(tmp, tmp, _MM_SHUFFLE(0, 0, 0, 1));
    ret = _mm_add_ps(tmp, ret);
    return *(float*)&ret;
}
float dot(const Vec4& v1, const Vec4& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

void print_m128(const string& pre, const __m128& m)
{
    float arr[4];
    _mm_store_ps(arr, m);
    cout << pre << arr[0] << "," << arr[1] << "," << arr[2] << "," << arr[3] << endl;
}

float simd_dot(const Vec4& v1, const Vec4& v2)
{
    __m128 m1 = _mm_load_ps(&v1.x);
    __m128 m2 = _mm_load_ps(&v2.x);
    __m128 m = _mm_mul_ps(m1, m2);                                  // x1*x2, y1*y2, z1*z2, w1*w2
    __m128 tmp = _mm_shuffle_ps(m, m, _MM_SHUFFLE(0, 0, 3, 2));     // z1*z2, w1*w2, z1*z2, w1*w2    
    tmp = _mm_add_ps(m, tmp);                                       // x1*x2 + z1*z2, y1*yz + w1*w2, -, -
    __m128 ret = _mm_shuffle_ps(tmp, tmp, _MM_SHUFFLE(0, 0, 0, 1));
    ret = _mm_add_ps(tmp, ret);
    return *(float*)&ret;
}

void simd_fast_dot(const Vec4_AOS& v1, const Vec4_AOS& v2, Vec4* ret, size_t n)
{
    for(size_t i = 0; i < n/4; ++i)
    {
        __m128 v1x = _mm_load_ps(v1.x + i * 4);
        __m128 v2x = _mm_load_ps(v2.x + i * 4);
        __m128 vx = _mm_mul_ps(v1x, v2x);

        __m128 v1y = _mm_load_ps(v1.y + i * 4);
        __m128 v2y = _mm_load_ps(v2.y + i * 4);
        __m128 vxy = _mm_fmadd_ps(v1y, v2y, vx);

        __m128 v1z = _mm_load_ps(v1.z + i * 4);
        __m128 v2z = _mm_load_ps(v2.z + i *4);
        __m128 vxyz = _mm_fmadd_ps(v1z, v2z, vxy);

        __m128 v1w = _mm_load_ps(v1.w + i * 4);
        __m128 v2w = _mm_load_ps(v2.w + i * 4);
        __m128 vxyzw = _mm_fmadd_ps(v1w, v2w, vxyz);
        _mm_store_ps(&ret->x, vxyzw);
        ++ret;
    }
}

void simd_avx_dot(const Vec4_AOS& v1, const Vec4_AOS& v2, Vec4* ret, size_t n)
{
    for(size_t i = 0; i < n/8; ++i)
    {
        __m256 v1x = _mm256_load_ps(v1.x + i * 8);
        __m256 v2x = _mm256_load_ps(v2.x + i * 8);
        __m256 vx = _mm256_mul_ps(v1x, v2x);

        __m256 v1y = _mm256_load_ps(v1.y + i * 8);
        __m256 v2y = _mm256_load_ps(v2.y + i * 8);
        __m256 vxy = _mm256_fmadd_ps(v1y, v2y, vx);

        __m256 v1z = _mm256_load_ps(v1.z + i * 8);
        __m256 v2z = _mm256_load_ps(v2.z + i *8);
        __m256 vxyz = _mm256_fmadd_ps(v1z, v2z, vxy);

        __m256 v1w = _mm256_load_ps(v1.w + i * 8);
        __m256 v2w = _mm256_load_ps(v2.w + i * 8);
        __m256 vxyzw = _mm256_fmadd_ps(v1w, v2w, vxyz);
        _mm256_store_ps(&ret->x, vxyzw);
        ret += 2;
    }
}
void fill_vec4_arr(Vec4* v, size_t len)
{
    float* rand_arr = get_float_arr();
    for(size_t i = 0; i < len; ++i)
    {
        v[i].x = rand_arr[i * 4];
        v[i].y = rand_arr[i * 4 + 1];
        v[i].z = rand_arr[i * 4 + 2];
        v[i].w = rand_arr[i * 4 + 3];
    }
}

void fill_vec4_aos_arr(Vec4_AOS& v, Vec4* v4, size_t len)
{
    v.x = new float[len]; 
    v.y = new float[len]; 
    v.z = new float[len]; 
    v.w = new float[len]; 
    for(size_t i = 0; i < len; ++i)
    {
        v.x[i] = v4[i].x; 
        v.y[i] = v4[i].y;
        v.z[i] = v4[i].z;
        v.w[i] = v4[i].w;
    }
}

void fill_float_arr(float* f, size_t len)
{
    float* rand_float_arr = get_float_arr();
    for(size_t i = 0; i < len; ++i)
    {
        f[i] = rand_float_arr[i];
    }
}

void arr_add(float* a, float* b, int n)
{
    for(int i = 0;i < n; ++i)
    {
        a[i] += b[i];
    }
}

// n是4的倍数，a和b长度相等且都是16byte(4个float)对齐
void simd_arr_add(float* a, float* b, int n)
{
    for(int i = 0; i < n; i += 4)
    {
        __m128 v1 = _mm_load_ps(a + i);
        __m128 v2 = _mm_load_ps(b + i);
        __m128 v = _mm_add_ps(v1, v2); 
        _mm_store_ps(a + i, v);
    }
}

void print_vec4(const Vec4* v, size_t n)
{
    for(size_t i = 0; i < n; ++i)
    {
        cout << v->x << "," << v->y << "," << v->z << "," << v->w << endl;
        v++;
    }
}
void print_vec4_aos(const Vec4_AOS& v, size_t n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << v.x[i] << "," << v.y[i] << "," << v.z[i] << "," << v.w[i] << endl;
    }
}
/*
int main()
{
    Vec4 v1[VECTOR_NUMS];
    Vec4 v2[VECTOR_NUMS];
    Vec4_AOS v1_aos;
    Vec4_AOS v2_aos;
    fill_vec4_arr(v1, VECTOR_NUMS);
    fill_vec4_arr(v2, VECTOR_NUMS);
    fill_vec4_aos_arr(v1_aos, v1, VECTOR_NUMS);
    fill_vec4_aos_arr(v2_aos, v2, VECTOR_NUMS);


    cout << "v1:\n";
    print_vec4(v1, VECTOR_NUMS);
    cout << "v2:\n";
    print_vec4(v2, VECTOR_NUMS);
    cout << "v1_aos:\n";
    print_vec4_aos(v1_aos, VECTOR_NUMS);
    cout << "v2_aos:\n";
    print_vec4_aos(v2_aos, VECTOR_NUMS);

    for(size_t i = 0; i < VECTOR_NUMS; ++i)
    {
        cout << dot(v1[i], v2[i]) << std::endl;
        cout << simd_dot(v1[i], v2[i]) << std::endl;
    }

    Vec4 ret[VECTOR_NUMS/4];
    simd_fast_dot(v1_aos, v2_aos, ret, VECTOR_NUMS);
    cout << "aos_ret:\n";
    print_vec4(ret, VECTOR_NUMS/4);
    simd_avx_dot(v1_aos, v2_aos, ret, VECTOR_NUMS);
    cout << "aos_avx_ret:\n";
    print_vec4(ret, VECTOR_NUMS/4);
    
    for(size_t i = 0; i < VECTOR_NUMS; ++i)
    {
        cout << squared_dis(v1[i], v2[i]) << std::endl;
        cout << simd_squared_dis(v1[i], v2[i]) << std::endl;
    }
}
    */
float f1[FLOAT_NUMS];
float f2[FLOAT_NUMS];
Vec4 v1[VECTOR_NUMS];
Vec4 v2[VECTOR_NUMS];
Vec4_AOS v1_aos;
Vec4_AOS v2_aos;

void test_arr_add()
{
    arr_add(f1, f2, FLOAT_NUMS);
}

void test_simd_arr_add()
{
    simd_arr_add(f1, f2, FLOAT_NUMS/4);
}

void test_dot()
{
    float ret[VECTOR_NUMS];
    for(size_t i = 0; i < VECTOR_NUMS; ++i)
    {
        ret[i] = dot(v1[i], v2[i]);
    }
}

void test_simd_dot()
{
    float ret[VECTOR_NUMS];
    for(size_t i = 0; i < VECTOR_NUMS; ++i)
    {
        ret[i] = simd_dot(v1[i], v2[i]);
    }
}

void test_simd_fast_dot()
{
    Vec4 ret[VECTOR_NUMS/4];
    simd_fast_dot(v1_aos, v2_aos, ret, VECTOR_NUMS);
}

void test_simd_avx_dot()
{
    Vec4 ret[VECTOR_NUMS/4];
    simd_avx_dot(v1_aos, v2_aos, ret, VECTOR_NUMS);
}

void test_squared_dis()
{
    for(size_t i = 0; i < VECTOR_NUMS; ++i)
    {
        squared_dis(v1[i], v2[i]);
    }
}
void test_simd_squared_dis()
{
    for(size_t i = 0; i < VECTOR_NUMS; ++i)
    {
        simd_squared_dis(v1[i], v2[i]);
    }
}
/*
static void benchmark_arr_add(picobench::state& s)
{
    fill_float_arr(f1, FLOAT_NUMS);
    fill_float_arr(f2, FLOAT_NUMS);
    picobench::scope scope(s);
    for(auto _ : s)
    {
        test_arr_add();
    }
}

PICOBENCH(benchmark_arr_add);

static void benchmark_simd_arr_add(picobench::state& s)
{
    fill_float_arr(f1, FLOAT_NUMS);
    fill_float_arr(f2, FLOAT_NUMS);
    picobench::scope scope(s);
    for(auto _ : s)
    {
        test_simd_arr_add();
    }
}
PICOBENCH(benchmark_simd_arr_add);
static void benchmark_squared_dis(picobench::state& s)
{
    fill_vec4_arr(v1, VECTOR_NUMS);
    fill_vec4_arr(v2, VECTOR_NUMS);
    picobench::scope scope(s);
    for(auto _ : s)
    {
        test_squared_dis();
    }
}

PICOBENCH(benchmark_squared_dis);

static void benchmark_simd_squared_dis(picobench::state& s)
{
    fill_vec4_arr(v1, VECTOR_NUMS);
    fill_vec4_arr(v2, VECTOR_NUMS);
    picobench::scope scope(s);
    for(auto _ : s)
    {
        test_simd_squared_dis();
    }
}
PICOBENCH(benchmark_simd_squared_dis);
*/

static void benchmark_simd_sse_dot(picobench::state& s)
{
    fill_vec4_arr(v1, VECTOR_NUMS);
    fill_vec4_arr(v2, VECTOR_NUMS);
    fill_vec4_aos_arr(v1_aos, v1, VECTOR_NUMS);
    fill_vec4_aos_arr(v2_aos, v2, VECTOR_NUMS);
    picobench::scope scope(s);
    for(auto _ : s)
    {
        test_simd_fast_dot();
    }
}
PICOBENCH(benchmark_simd_sse_dot);

static void benchmark_simd_avx_dot(picobench::state& s)
{
    fill_vec4_arr(v1, VECTOR_NUMS);
    fill_vec4_arr(v2, VECTOR_NUMS);
    fill_vec4_aos_arr(v1_aos, v1, VECTOR_NUMS);
    fill_vec4_aos_arr(v2_aos, v2, VECTOR_NUMS);
    picobench::scope scope(s);
    for(auto _ : s)
    {
        test_simd_avx_dot();
    }
}
PICOBENCH(benchmark_simd_avx_dot);


static void benchmark_dot(picobench::state& s)
{
    fill_vec4_arr(v1, VECTOR_NUMS);
    fill_vec4_arr(v2, VECTOR_NUMS);
    picobench::scope scope(s);
    for(auto _ : s)
    {
        test_dot();
    }
}

PICOBENCH(benchmark_dot);

static void benchmark_simd_dot(picobench::state& s)
{
    fill_vec4_arr(v1, VECTOR_NUMS);
    fill_vec4_arr(v2, VECTOR_NUMS);
    picobench::scope scope(s);
    for(auto _ : s)
    {
        test_simd_dot();
    }
}
PICOBENCH(benchmark_simd_dot);


