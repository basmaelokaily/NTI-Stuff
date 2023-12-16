################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/src/RTOS_KERNEL_program.c \
../RTOS/src/RTOS_TMR_program.c 

OBJS += \
./RTOS/src/RTOS_KERNEL_program.o \
./RTOS/src/RTOS_TMR_program.o 

C_DEPS += \
./RTOS/src/RTOS_KERNEL_program.d \
./RTOS/src/RTOS_TMR_program.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/src/%.o: ../RTOS/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\AMIT\Desktop\WorkSpaces\eclipse\R6G6WorkSpace\RTOS_test\RTOS\inc" -I"C:\Users\AMIT\Desktop\WorkSpaces\eclipse\R6G6WorkSpace\RTOS_test\MCAL\DIO\inc" -I"C:\Users\AMIT\Desktop\WorkSpaces\eclipse\R6G6WorkSpace\RTOS_test\MCAL\GI\inc" -I"C:\Users\AMIT\Desktop\WorkSpaces\eclipse\R6G6WorkSpace\RTOS_test\UTILES_LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


