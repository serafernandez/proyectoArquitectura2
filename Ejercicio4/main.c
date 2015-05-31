
#include "msp430f2274.h"
#include "TI_MSP_ADC10.h"
#include <stdio.h>

unsigned int AD_result;

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  /* configure internal digitally control led oscillator */
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL  = CALDCO_1MHZ;

  Init_ADC10();

  ADC10AE0 |= BIT4;

    // Configuracion Inicial Timer A
  TACTL = (TASSEL_2 + ID_3 + MC_2);
  TACCR1 = TAR + 12500;
  TACCTL1 = (CM_0 + CCIS_2 + CCIE);

  __enable_interrupt();

  while(1){

    AD_result = AD10_Convert(INCH_4);
    printf("%u\r\n", AD_result);

  }
}

//******************************************************************************
// Funcion: TimerA_ISR_CCR1
// ISR de CCR1-2 del Timer A
//******************************************************************************
#pragma vector = TIMERA1_VECTOR
__interrupt void TimerA_ISR_CCR1(void){
  if(TACCTL1 & CCIFG){
    // Funcion de Interrupcion cada 100mseg.
    TACCR1 = TAR + 12500;   // 12500 = 100mseg.
    TACCTL1 &= ~CCIFG;





  }
}
