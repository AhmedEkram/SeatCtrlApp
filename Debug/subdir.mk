################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Adc.c \
../Com.c \
../Dio.c \
../HMI.c \
../HeightMotor.c \
../HeightSensor.c \
../InclineMotor.c \
../InclineSensor.c \
../IoHwAbs.c \
../Os.c \
../Rte.c \
../SeatManager.c \
../SlideMotor.c \
../SlideSensor.c \
../Spi.c \
../WeightSensor.c \
../main.c \
../vfb.c 

OBJS += \
./Adc.o \
./Com.o \
./Dio.o \
./HMI.o \
./HeightMotor.o \
./HeightSensor.o \
./InclineMotor.o \
./InclineSensor.o \
./IoHwAbs.o \
./Os.o \
./Rte.o \
./SeatManager.o \
./SlideMotor.o \
./SlideSensor.o \
./Spi.o \
./WeightSensor.o \
./main.o \
./vfb.o 

C_DEPS += \
./Adc.d \
./Com.d \
./Dio.d \
./HMI.d \
./HeightMotor.d \
./HeightSensor.d \
./InclineMotor.d \
./InclineSensor.d \
./IoHwAbs.d \
./Os.d \
./Rte.d \
./SeatManager.d \
./SlideMotor.d \
./SlideSensor.d \
./Spi.d \
./WeightSensor.d \
./main.d \
./vfb.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


