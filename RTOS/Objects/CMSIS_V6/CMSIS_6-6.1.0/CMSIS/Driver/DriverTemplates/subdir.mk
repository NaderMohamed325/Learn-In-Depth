################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_CAN.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_MAC.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_PHY.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Flash.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_GPIO.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_I2C.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_MCI.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_NAND.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SAI.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SPI.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Storage.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USART.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBD.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBH.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_WiFi.c 

OBJS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_CAN.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_MAC.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_PHY.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Flash.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_GPIO.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_I2C.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_MCI.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_NAND.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SAI.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SPI.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Storage.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USART.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBD.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBH.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_WiFi.o 

C_DEPS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_CAN.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_MAC.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_PHY.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Flash.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_GPIO.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_I2C.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_MCI.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_NAND.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SAI.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SPI.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Storage.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USART.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBD.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBH.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_WiFi.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/%.o CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/%.su CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/%.cyclo: ../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/%.c CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Include" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-Driver-2f-DriverTemplates

clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-Driver-2f-DriverTemplates:
	-$(RM) ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_CAN.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_CAN.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_CAN.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_CAN.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_MAC.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_MAC.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_MAC.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_MAC.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_PHY.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_PHY.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_PHY.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_ETH_PHY.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Flash.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Flash.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Flash.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Flash.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_GPIO.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_GPIO.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_GPIO.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_GPIO.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_I2C.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_I2C.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_I2C.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_I2C.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_MCI.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_MCI.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_MCI.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_MCI.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_NAND.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_NAND.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_NAND.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_NAND.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SAI.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SAI.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SAI.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SAI.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SPI.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SPI.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SPI.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_SPI.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Storage.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Storage.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Storage.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_Storage.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USART.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USART.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USART.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USART.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBD.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBD.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBD.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBD.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBH.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBH.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBH.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_USBH.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_WiFi.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_WiFi.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_WiFi.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Driver/DriverTemplates/Driver_WiFi.su

.PHONY: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-Driver-2f-DriverTemplates

