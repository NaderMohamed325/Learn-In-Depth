################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/CortexMX_Os_Porting.c \
../RTOS/RTOS_FIFO.c \
../RTOS/Schedular.c 

OBJS += \
./RTOS/CortexMX_Os_Porting.o \
./RTOS/RTOS_FIFO.o \
./RTOS/Schedular.o 

C_DEPS += \
./RTOS/CortexMX_Os_Porting.d \
./RTOS/RTOS_FIFO.d \
./RTOS/Schedular.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/%.o RTOS/%.su RTOS/%.cyclo: ../RTOS/%.c RTOS/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/inc" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/GPIO" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/RTOS/Inc" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/CMSIS_V5" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/inc" -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-RTOS

clean-RTOS:
	-$(RM) ./RTOS/CortexMX_Os_Porting.cyclo ./RTOS/CortexMX_Os_Porting.d ./RTOS/CortexMX_Os_Porting.o ./RTOS/CortexMX_Os_Porting.su ./RTOS/RTOS_FIFO.cyclo ./RTOS/RTOS_FIFO.d ./RTOS/RTOS_FIFO.o ./RTOS/RTOS_FIFO.su ./RTOS/Schedular.cyclo ./RTOS/Schedular.d ./RTOS/Schedular.o ./RTOS/Schedular.su

.PHONY: clean-RTOS

