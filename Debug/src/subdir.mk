################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GenerateNumbers.cpp \
../src/GenerateNumbersXOR.cpp \
../src/Histograma.cpp \
../src/MonteCarloCrude.cpp \
../src/MonteCarloCrudeN.cpp \
../src/MonteCarloIntegration.cpp 

OBJS += \
./src/GenerateNumbers.o \
./src/GenerateNumbersXOR.o \
./src/Histograma.o \
./src/MonteCarloCrude.o \
./src/MonteCarloCrudeN.o \
./src/MonteCarloIntegration.o 

CPP_DEPS += \
./src/GenerateNumbers.d \
./src/GenerateNumbersXOR.d \
./src/Histograma.d \
./src/MonteCarloCrude.d \
./src/MonteCarloCrudeN.d \
./src/MonteCarloIntegration.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


