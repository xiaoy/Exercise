################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Client.cpp \
../src/ClientHumidity.cpp \
../src/ClientTemp.cpp \
../src/Observer.cpp \
../src/Observerble.cpp \
../src/WeatherData.cpp 

OBJS += \
./src/Client.o \
./src/ClientHumidity.o \
./src/ClientTemp.o \
./src/Observer.o \
./src/Observerble.o \
./src/WeatherData.o 

CPP_DEPS += \
./src/Client.d \
./src/ClientHumidity.d \
./src/ClientTemp.d \
./src/Observer.d \
./src/Observerble.d \
./src/WeatherData.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


