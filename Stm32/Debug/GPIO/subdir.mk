################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO/stm32f103c6_gpio.c 

OBJS += \
./GPIO/stm32f103c6_gpio.o 

C_DEPS += \
./GPIO/stm32f103c6_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO/%.o GPIO/%.su GPIO/%.cyclo: ../GPIO/%.c GPIO/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/Inc" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/GPIO/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-GPIO

clean-GPIO:
	-$(RM) ./GPIO/stm32f103c6_gpio.cyclo ./GPIO/stm32f103c6_gpio.d ./GPIO/stm32f103c6_gpio.o ./GPIO/stm32f103c6_gpio.su

.PHONY: clean-GPIO

