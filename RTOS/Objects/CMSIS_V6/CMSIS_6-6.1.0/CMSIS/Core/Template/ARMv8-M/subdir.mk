################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/main_s.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/tz_context.c 

OBJS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/main_s.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/tz_context.o 

C_DEPS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/main_s.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/tz_context.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/%.o CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/%.su CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/%.cyclo: ../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/%.c CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Include" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-Core-2f-Template-2f-ARMv8-2d-M

clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-Core-2f-Template-2f-ARMv8-2d-M:
	-$(RM) ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/main_s.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/main_s.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/main_s.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/main_s.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/tz_context.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/tz_context.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/tz_context.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Template/ARMv8-M/tz_context.su

.PHONY: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-Core-2f-Template-2f-ARMv8-2d-M

