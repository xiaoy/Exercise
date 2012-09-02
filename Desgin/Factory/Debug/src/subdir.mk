################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Factory.cpp \
../src/NyStyleChesePizza.cpp \
../src/NyStyleClamPizza.cpp \
../src/NyStylePepperoniPizza.cpp \
../src/NyStylePizzaStore.cpp \
../src/NyStyleVeggiePizza.cpp \
../src/Pizza.cpp \
../src/PizzaStore.cpp 

OBJS += \
./src/Factory.o \
./src/NyStyleChesePizza.o \
./src/NyStyleClamPizza.o \
./src/NyStylePepperoniPizza.o \
./src/NyStylePizzaStore.o \
./src/NyStyleVeggiePizza.o \
./src/Pizza.o \
./src/PizzaStore.o 

CPP_DEPS += \
./src/Factory.d \
./src/NyStyleChesePizza.d \
./src/NyStyleClamPizza.d \
./src/NyStylePepperoniPizza.d \
./src/NyStylePizzaStore.d \
./src/NyStyleVeggiePizza.d \
./src/Pizza.d \
./src/PizzaStore.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


