################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/startup_ARMCA7.s 

C_SRCS += \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/mmu_ARMCA7.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/startup_ARMCA7.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/system_ARMCA7.c 

OBJS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/mmu_ARMCA7.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/startup_ARMCA7.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/system_ARMCA7.o 

S_DEPS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/startup_ARMCA7.d 

C_DEPS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/mmu_ARMCA7.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/startup_ARMCA7.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/system_ARMCA7.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/%.o CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/%.su CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/%.cyclo: ../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/%.c CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Include" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/%.o: ../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/%.s CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 -mcpu=cortex-m3 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Layer-2f-Target-2f-CA7-2f-RTE-2f-Device-2f-ARMCA7

clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Layer-2f-Target-2f-CA7-2f-RTE-2f-Device-2f-ARMCA7:
	-$(RM) ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/mmu_ARMCA7.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/mmu_ARMCA7.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/mmu_ARMCA7.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/mmu_ARMCA7.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/startup_ARMCA7.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/startup_ARMCA7.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/startup_ARMCA7.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/startup_ARMCA7.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/system_ARMCA7.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/system_ARMCA7.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/system_ARMCA7.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Layer/Target/CA7/RTE/Device/ARMCA7/system_ARMCA7.su

.PHONY: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Layer-2f-Target-2f-CA7-2f-RTE-2f-Device-2f-ARMCA7

