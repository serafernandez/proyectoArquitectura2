#include "msp430f2274.h"
#include "TI_MSP_ADC10.h"
#include "TI_MSP_UART.h"
#include <stdio.h>

#define LED1 BIT5	//P4.5
#define OFFSET 2500

long AD_result;

char ledPrendido = 0;

long porcentaje, tiempo, tiempoCero;

void main(void) {
	// Stop watchdog timer to prevent time out reset
	WDTCTL = WDTPW + WDTHOLD;

	P4DIR |= LED1;

	/* configure internal digitally control led oscillator */
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	Init_ADC10();

	ADC10AE0 |= BIT4;

	// Configuracion Inicial Timer A
	TACTL = (TASSEL_2 + ID_3 + MC_2);
	TACCR1 = TAR + OFFSET;
	TACCTL1 = (CM_0 + CCIS_2 + CCIE);

	__enable_interrupt();

	while (1) {
		AD_result = AD10_Convert(INCH_4);
		porcentaje = ((AD_result * 80) / 1023) + 10;
		tiempo = (porcentaje * OFFSET) / 100;
	}
}

//******************************************************************************
// Funcion: TimerA_ISR_CCR1
// ISR de CCR1-2 del Timer A
//******************************************************************************
#pragma vector = TIMERA1_VECTOR
__interrupt void TimerA_ISR_CCR1(void) {
	if (TACCTL1 & CCIFG) {

		TACCTL1 &= ~CCIFG;

		// FunciSPon de Interrupcion cada 100mseg.
		if(ledPrendido == 0){
			TACCR1 += tiempoCero;   // 12500 = 100mseg.
			P4OUT |= LED1;
			ledPrendido = 1;
			tiempoCero = tiempo;
		}else{
			TACCR1 += OFFSET - tiempoCero;   // 12500 = 100mseg.
			P4OUT &= ~LED1;
			ledPrendido = 0;
		}
	}
}

