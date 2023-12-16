################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := DC_ULTRASONIC_NTI
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
DC_ULTRASONIC_NTI.elf \

MAP_FILES += \
DC_ULTRASONIC_NTI.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
DC_ULTRASONIC_NTI.list \

OBJCOPY_HEX += \
DC_ULTRASONIC_NTI.hex \

OBJCOPY_BIN += \
DC_ULTRASONIC_NTI.bin \


# All Target
all: main-build

# Main-build Target
main-build: DC_ULTRASONIC_NTI.elf secondary-outputs

# Tool invocations
DC_ULTRASONIC_NTI.elf DC_ULTRASONIC_NTI.map: $(OBJS) $(USER_OBJS) F:\New\ folder\CUBE_IDE\DC_ULTRASONIC_NTI\ (5)\DC_ULTRASONIC_NTI\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "DC_ULTRASONIC_NTI.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\New folder\CUBE_IDE\DC_ULTRASONIC_NTI (5)\DC_ULTRASONIC_NTI\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="DC_ULTRASONIC_NTI.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

DC_ULTRASONIC_NTI.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "DC_ULTRASONIC_NTI.list"
	@echo 'Finished building: $@'
	@echo ' '

DC_ULTRASONIC_NTI.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "DC_ULTRASONIC_NTI.hex"
	@echo 'Finished building: $@'
	@echo ' '

DC_ULTRASONIC_NTI.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "DC_ULTRASONIC_NTI.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) DC_ULTRASONIC_NTI.bin DC_ULTRASONIC_NTI.elf DC_ULTRASONIC_NTI.hex DC_ULTRASONIC_NTI.list DC_ULTRASONIC_NTI.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
