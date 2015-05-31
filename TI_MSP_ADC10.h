#include "msp430f2274.h"

// You MUST set the value of MSP430x2_ADC10_REF in you app definition section
// and call Init_ADC10() function in the app configuration section.
// Ensure to configure ADC10AE0 and ADC10AE1 Register in you app
// Example:

// #define MSP430x2_ADC10_REF
#define ADC10_REF_VCC       1   // Vr+ = Vcc | Vr- = Vss
#define ADC10_REF_INT_2_5V  2   // Vr+ = Internar Reference 2.5V | Vr- = Vss
#define ADC10_REF_INT_1_5V  3   // Vr+ = Internar Reference 1.5V  | Vr- = Vss
#define ADC10_REF_BUFF_EXT  4   // Vr+ = Buffered External Reference Veref+  | Vr- = Vss

#define MSP430x2_ADC10_REF ADC10_REF_VCC

//******************************************************************************
// Funcion: Init_ADC10
// Configuracion Inicial del Modulo ADC10.
//******************************************************************************
void Init_ADC10(void);
  
//******************************************************************************
// Funcion: AD10_Convert
// Dispara la conversion AD del canal indicado y espera mientras realiza la misma
//    Entrada: CH = Constante del canal de entrada (INCH_0, INCH_5, etc)
//    Salida: conversion AD (10 bit menos significativos)
//******************************************************************************
unsigned int AD10_Convert(unsigned int CH);