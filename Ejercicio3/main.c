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
void parsearResultado(int res, int* array);

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
	    if(datoLeido == 67 || datoLeido == 99)
		    mostrarLecturaConvertida();
    }
}

void mostrarLecturaConvertida(){
	AD_result = AD10_Convert(INCH_4);
	int resultado = ((float)AD_result/1023) * 330;

	int resultadoArray[3];
	parsearResultado(resultado, resultadoArray);

	sprintf(tx_buffer,"%d.%d%dV\n\r", resultadoArray[0], resultadoArray[1], resultadoArray[2]);
	UART_Tx_string(tx_buffer, 0);
}

void parsearResultado(int res, int* array){
	array[0] = res / 100;
	res -= (array[0] * 100);
	array[1] = res / 10;
	res -= (array[1] * 10);
	array[2] = res;
}



