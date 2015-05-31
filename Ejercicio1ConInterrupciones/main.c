#include <msp430.h> 
#include <intrinsics.h>

/*
 * main.c
 */

#define SW1  BIT0	//P2.0
#define SW2  BIT1	//P2.1
#define LED1 BIT5	//P4.5
#define LED2 BIT6	//P4.6

int SW1EstaApretado = 0;
int SW2EstaApretado = 0;
int quedanPrendidas = 0;

void main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	P4DIR |= (LED1 + LED2);	//
	P2DIR &= ~(SW1 + SW2);
	P2REN |= (SW1 + SW2);
	P2OUT |= (SW1 + SW2);


	P2IE |= SW1;
	P1IES &= ~SW1; // LO/HI
	P1IFG &= ~SW1;

	P2IE |= SW2;
	P1IES &= ~SW2; //LO/HI
	P1IFG &= ~SW2;


	P4OUT = 0;

	__enable_interrupt();
	while (1) {
	}
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void) {

	if (P2IFG & SW1) {
		P2IFG &= ~SW1;
		if((P2IES & SW1)){
			if(SW2EstaApretado == 1){
				P4OUT &= ~LED1;
				P4OUT &= ~LED2;
				quedanPrendidas = 0;
			}else{
				SW1EstaApretado = 1;
				P4OUT |= LED1;
			}
		}else{

			SW1EstaApretado = 0;
			if(quedanPrendidas == 0)
				P4OUT &= ~LED1;
		}

	}

	if (P2IFG & SW2) {
		P2IFG &= ~SW2;
		if((P2IES & SW2)){

			if(SW1EstaApretado == 1){
				P4OUT |= LED1;
				P4OUT |= LED2;
				quedanPrendidas = 1;
			}else{
				SW2EstaApretado = 1;
				P4OUT |= LED2;
			}
		}else{
			SW2EstaApretado = 0;
			if(quedanPrendidas == 0)
				P4OUT &= ~LED2;
		}

	}


	P2IES ^= SW1;
	P2IES ^= SW2
			;


}
