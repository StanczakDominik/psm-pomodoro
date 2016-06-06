################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../clock.c \
../i2c.c \
../lcd.c \
../main.c \
../pomodoro_common.c \
../usart.c 

OBJS += \
./clock.o \
./i2c.o \
./lcd.o \
./main.o \
./pomodoro_common.o \
./usart.o 

C_DEPS += \
./clock.d \
./i2c.d \
./lcd.d \
./main.d \
./pomodoro_common.d \
./usart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=11059200UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


