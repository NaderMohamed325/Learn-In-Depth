################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/GPIO/stm32f103c6.c 

OBJS += \
./STM32F103C6_Drivers/GPIO/stm32f103c6.o 

C_DEPS += \
./STM32F103C6_Drivers/GPIO/stm32f103c6.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/GPIO/%.o STM32F103C6_Drivers/GPIO/%.su STM32F103C6_Drivers/GPIO/%.cyclo: ../STM32F103C6_Drivers/GPIO/%.c STM32F103C6_Drivers/GPIO/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers-2f-GPIO

clean-STM32F103C6_Drivers-2f-GPIO:
	-$(RM) ./STM32F103C6_Drivers/GPIO/stm32f103c6.cyclo ./STM32F103C6_Drivers/GPIO/stm32f103c6.d ./STM32F103C6_Drivers/GPIO/stm32f103c6.o ./STM32F103C6_Drivers/GPIO/stm32f103c6.su

.PHONY: clean-STM32F103C6_Drivers-2f-GPIO
