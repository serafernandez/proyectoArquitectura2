#include <msp430.h>
#include "./TI_MSP_UART.h"
#include "./TI_MSP_ADC10.h"
#include <stdio.h>
#include <string.h>

#define MSP430_UART_SMCLK_FREQ SMCLK_1MHZ
#define MSP430_UART_BAUD_RATE  BAUD_RATE_9600BPS

char datoLeido;
unsigned int AD_result;
char tx_buffer[20];

void mostrarLecturaConvertida();

void main( void )
{
	// Stop watchdog timer to prevent time out reset
	WDTCTL = WDTPW + WDTHOLD;

	/* configure internal digitally control led oscillator */
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL  = CALDCO_1MHZ;

	Init_UART();
	Init_ADC10();

	ADC10AE0 |= BIT4;

	__enable_interrupt();

	sprintf(tx_buffer,"Entro\r\n");
	UART_Tx_string(tx_buffer, 0);

	while(1);
}

#pragma vector=UART_ISR_RX_VECTOR
__interrupt void ISR_UartRx(void){
    if(UART_IFG & UART_UCAxRXIFG){
    	datoLeido = UART_UCAxRXBUF;
	    if(datoLeido == 13)
		    mostrarLecturaConvertida();
    }
}

void mostrarLecturaConvertida(){
	AD_result = AD10_Convert(INCH_4);
	float resultado = ((float)AD_result/1023) * 3.3;
	sprintf(tx_buffer,"%3.2fV", AD_result, resultado);
	UART_Tx_string(tx_buffer, 0);
}
