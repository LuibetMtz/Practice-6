void vfnConfADC(void)
{
	int *pClockPin = (int *)0x40048038;		/*Clock pin*/
	int *pClockADC = (int *)0x4004803C;		/*Clock ADC*/
	int *pPCRB0 = (int *)0x4004A000;		/*PCR del pin*/
	int *pADC_SC1A = (int *)0x4003B000;		/*Registro 1 de conf del ADC*/



	*pClockPin = 0x400;					/*Activacion clock del pin*/
	*pClockADC = 0x8000000;				/*Activacion clock del adc*/
	*pPCRB0 = *pPCRB0 & ~(0x700);		/*Activacion del pin B0 en ALT0 como ADC0*/
	*pADC_SC1A = 0x8;					/*ADCH en 01000 para AD8 input*/
	return;
}
