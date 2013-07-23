ZTHREAD_INCLUDE = -I"usr/local/include/zthread"
ZTHREAD_LIB = -L"usr/local/lib" -lZThread
hello : hello.o
	g++ -o hello HelloWolrd.o  $(ZTHREAD_LIB)
hello.o:HelloWolrd.cpp
	g++ -c HelloWolrd.cpp $(ZTHREAD_INCLUDE)
