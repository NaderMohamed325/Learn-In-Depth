################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/startup_ARMCM0plus.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/system_ARMCM0plus.c 

OBJS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/startup_ARMCM0plus.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/system_ARMCM0plus.o 

C_DEPS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/startup_ARMCM0plus.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/system_ARMCM0plus.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/%.o CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/%.su CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/%.cyclo: ../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/%.c CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Include" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Layer-2f-Target-2f-CM0plus-2f-RTE-2f-Device-2f-ARMCM0P

clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Layer-2f-Target-2f-CM0plus-2f-RTE-2f-Device-2f-ARMCM0P:
	-$(RM) ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/startup_ARMCM0plus.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/startup_ARMCM0plus.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/startup_ARMCM0plus.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/startup_ARMCM0plus.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/system_ARMCM0plus.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/system_ARMCM0plus.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/system_ARMCM0plus.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CM0plus/RTE/Device/ARMCM0P/system_ARMCM0plus.su

.PHONY: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Layer-2f-Target-2f-CM0plus-2f-RTE-2f-Device-2f-ARMCM0P

