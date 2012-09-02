################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Beverage.cpp \
../src/Condiment.cpp \
../src/Decorate.cpp \
../src/Espresso.cpp \
../src/Mocha.cpp 

OBJS += \
./src/Beverage.o \
./src/Condiment.o \
./src/Decorate.o \
./src/Espresso.o \
./src/Mocha.o 

CPP_DEPS += \
./src/Beverage.d \
./src/Condiment.d \
./src/Decorate.d \
./src/Espresso.d \
./src/Mocha.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


