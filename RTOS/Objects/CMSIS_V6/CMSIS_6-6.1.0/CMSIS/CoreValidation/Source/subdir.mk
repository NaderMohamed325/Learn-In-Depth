################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CAL1Cache.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CML1Cache.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreAFunc.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreFunc.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreInstr.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreSimd.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Framework.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_GenTimer.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv7.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv8.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Report.c \
../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/cmsis_cv.c 

OBJS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CAL1Cache.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CML1Cache.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreAFunc.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreFunc.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreInstr.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreSimd.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Framework.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_GenTimer.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv7.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv8.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Report.o \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/cmsis_cv.o 

C_DEPS += \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CAL1Cache.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CML1Cache.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreAFunc.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreFunc.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreInstr.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreSimd.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Framework.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_GenTimer.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv7.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv8.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Report.d \
./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/cmsis_cv.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/%.o CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/%.su CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/%.cyclo: ../CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/%.c CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/CMSIS_V6/CMSIS_6-6.1.0/CMSIS/Core/Include" -I"C:/Users/xcite/OneDrive/Desktop/Learn in depth/Stm32/STM32F103C6_Drivers/inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Source

clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Source:
	-$(RM) ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CAL1Cache.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CAL1Cache.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CAL1Cache.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CAL1Cache.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CML1Cache.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CML1Cache.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CML1Cache.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CML1Cache.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreAFunc.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreAFunc.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreAFunc.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreAFunc.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreFunc.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreFunc.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreFunc.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreFunc.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreInstr.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreInstr.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreInstr.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreInstr.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreSimd.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreSimd.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreSimd.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_CoreSimd.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Framework.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Framework.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Framework.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Framework.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_GenTimer.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_GenTimer.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_GenTimer.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_GenTimer.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv7.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv7.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv7.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv7.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv8.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv8.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv8.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_MPU_ARMv8.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Report.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Report.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Report.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/CV_Report.su ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/cmsis_cv.cyclo ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/cmsis_cv.d ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/cmsis_cv.o ./CMSIS_V6/CMSIS_6-6.1.0/CMSIS/CoreValidation/Source/cmsis_cv.su

.PHONY: clean-CMSIS_V6-2f-CMSIS_6-2d-6-2e-1-2e-0-2f-CMSIS-2f-CoreValidation-2f-Source

