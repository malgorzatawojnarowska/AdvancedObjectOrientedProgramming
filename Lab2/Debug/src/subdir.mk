################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EmptyException.cpp \
../src/FullException.cpp \
../src/Stack.cpp \
../src/Student.cpp \
../src/main.cpp 

OBJS += \
./src/EmptyException.o \
./src/FullException.o \
./src/Stack.o \
./src/Student.o \
./src/main.o 

CPP_DEPS += \
./src/EmptyException.d \
./src/FullException.d \
./src/Stack.d \
./src/Student.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


