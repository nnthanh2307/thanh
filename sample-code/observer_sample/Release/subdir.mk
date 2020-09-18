################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Client.cpp \
../ClientTemp.cpp \
../OptimizedWeatherData.cpp \
../WeatherData.cpp \
../main.cpp 

OBJS += \
./Client.o \
./ClientTemp.o \
./OptimizedWeatherData.o \
./WeatherData.o \
./main.o 

CPP_DEPS += \
./Client.d \
./ClientTemp.d \
./OptimizedWeatherData.d \
./WeatherData.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


