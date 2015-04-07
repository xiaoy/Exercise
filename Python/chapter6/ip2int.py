# convert ip to int relative

k_1_key = (2 ** 24)
k_2_key = (2 ** 16)
k_3_key = (2 ** 8)

ip_str = raw_input('input a ip:')
digt_list = ip_str.split('.')

if len(digt_list) != 4:
    print 'the count is wrong.'
else:
    d1 = int(digt_list[0]) * k_1_key
    d2 = int(digt_list[1]) * k_2_key
    d3 = int(digt_list[2]) * k_3_key
    d4 = int(digt_list[3])
    print(d1 + d2 + d3 + d4)

ip_int = raw_input('input digit:')
ip_int = int(ip_int)
s1 = ip_int / k_1_key
s2 = (ip_int - k_1_key * s1) / k_2_key
s3 = (ip_int - k_1_key * s1 - k_2_key * s2) / k_3_key
s4 = ip_int - s1 * k_1_key - s2 * k_2_key - s3 * k_3_key

seq = (str(s1), str(s2), str(s3), str(s4))
ip_str = '.'.join(seq)
print ip_str
