################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/stm32f013c6_RCC_Driver.c \
../STM32F103C6_Drivers/stm32f103c6_EXTI_Driver.c \
../STM32F103C6_Drivers/stm32f103c6_SPI_Driver.c \
../STM32F103C6_Drivers/stm32f103c6_USART_Driver.c 

OBJS += \
./STM32F103C6_Drivers/stm32f013c6_RCC_Driver.o \
./STM32F103C6_Drivers/stm32f103c6_EXTI_Driver.o \
./STM32F103C6_Drivers/stm32f103c6_SPI_Driver.o \
./STM32F103C6_Drivers/stm32f103c6_USART_Driver.o 

C_DEPS += \
./STM32F103C6_Drivers/stm32f013c6_RCC_Driver.d \
./STM32F103C6_Drivers/stm32f103c6_EXTI_Driver.d \
./STM32F103C6_Drivers/stm32f103c6_SPI_Driver.d \
./STM32F103C6_Drivers/stm32f103c6_USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/%.o STM32F103C6_Drivers/%.su STM32F103C6_Drivers/%.cyclo: ../STM32F103C6_Drivers/%.c STM32F103C6_Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers

clean-STM32F103C6_Drivers:
	-$(RM) ./STM32F103C6_Drivers/stm32f013c6_RCC_Driver.cyclo ./STM32F103C6_Drivers/stm32f013c6_RCC_Driver.d ./STM32F103C6_Drivers/stm32f013c6_RCC_Driver.o ./STM32F103C6_Drivers/stm32f013c6_RCC_Driver.su ./STM32F103C6_Drivers/stm32f103c6_EXTI_Driver.cyclo ./STM32F103C6_Drivers/stm32f103c6_EXTI_Driver.d ./STM32F103C6_Drivers/stm32f103c6_EXTI_Driver.o ./STM32F103C6_Drivers/stm32f103c6_EXTI_Driver.su ./STM32F103C6_Drivers/stm32f103c6_SPI_Driver.cyclo ./STM32F103C6_Drivers/stm32f103c6_SPI_Driver.d ./STM32F103C6_Drivers/stm32f103c6_SPI_Driver.o ./STM32F103C6_Drivers/stm32f103c6_SPI_Driver.su ./STM32F103C6_Drivers/stm32f103c6_USART_Driver.cyclo ./STM32F103C6_Drivers/stm32f103c6_USART_Driver.d ./STM32F103C6_Drivers/stm32f103c6_USART_Driver.o ./STM32F103C6_Drivers/stm32f103c6_USART_Driver.su

.PHONY: clean-STM32F103C6_Drivers

