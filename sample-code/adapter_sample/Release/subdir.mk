################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../client.cpp \
../console_logger.cpp \
../main.cpp \
../serial_logger.cpp \
../serial_logger_adapter.cpp 

OBJS += \
./client.o \
./console_logger.o \
./main.o \
./serial_logger.o \
./serial_logger_adapter.o 

CPP_DEPS += \
./client.d \
./console_logger.d \
./main.d \
./serial_logger.d \
./serial_logger_adapter.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


