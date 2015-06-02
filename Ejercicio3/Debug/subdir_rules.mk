################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
TI_MSP_ADC10.obj: ../TI_MSP_ADC10.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/serafin/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/cl430" -vmsp --abi=eabi --use_hw_mpy=none --include_path="/home/serafin/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/serafin/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/include" --advice:power=all -g --define=__MSP430F2274__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="TI_MSP_ADC10.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

TI_MSP_UART.obj: ../TI_MSP_UART.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/serafin/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/cl430" -vmsp --abi=eabi --use_hw_mpy=none --include_path="/home/serafin/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/serafin/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/include" --advice:power=all -g --define=__MSP430F2274__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="TI_MSP_UART.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/serafin/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/cl430" -vmsp --abi=eabi --use_hw_mpy=none --include_path="/home/serafin/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/serafin/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/include" --advice:power=all -g --define=__MSP430F2274__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


