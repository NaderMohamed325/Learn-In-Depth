################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/main.c 

OBJS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/main.o 

C_DEPS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/main.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/%.o CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/%.su CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/%.cyclo: ../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/%.c CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Include" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Layer-2f-App-2f-Validation_Cortex-2d-M

clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Layer-2f-App-2f-Validation_Cortex-2d-M:
	-$(RM) ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/main.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/main.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/main.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/App/Validation_Cortex-M/main.su

.PHONY: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Layer-2f-App-2f-Validation_Cortex-2d-M

