################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GI/src/GI_program.c 

OBJS += \
./MCAL/GI/src/GI_program.o 

C_DEPS += \
./MCAL/GI/src/GI_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GI/src/%.o: ../MCAL/GI/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\AMIT\Desktop\WorkSpaces\eclipse\R6G6WorkSpace\RTOS_test\RTOS\inc" -I"C:\Users\AMIT\Desktop\WorkSpaces\eclipse\R6G6WorkSpace\RTOS_test\MCAL\DIO\inc" -I"C:\Users\AMIT\Desktop\WorkSpaces\eclipse\R6G6WorkSpace\RTOS_test\MCAL\GI\inc" -I"C:\Users\AMIT\Desktop\WorkSpaces\eclipse\R6G6WorkSpace\RTOS_test\UTILES_LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


