################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/clock_config.c \
../board/peripherals_edma_config_1.c \
../board/peripherals_flexcan_config_1.c \
../board/peripherals_osif_1.c \
../board/peripherals_pwm_pal_1.c \
../board/pin_mux.c 

OBJS += \
./board/clock_config.o \
./board/peripherals_edma_config_1.o \
./board/peripherals_flexcan_config_1.o \
./board/peripherals_osif_1.o \
./board/peripherals_pwm_pal_1.o \
./board/pin_mux.o 

C_DEPS += \
./board/clock_config.d \
./board/peripherals_edma_config_1.d \
./board/peripherals_flexcan_config_1.d \
./board/peripherals_osif_1.d \
./board/peripherals_pwm_pal_1.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@board/clock_config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


