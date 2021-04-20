#include <stdio.h>

void vfnpinMode(char port, int pin, char io)
{
	int *pClock = (int *)0x40048038, dwClockV = 0x200;  /*Direccion de memoria del SCG y su valor de activacion*/
	int *pPCR, dwPCRV = 0x100;
	int *pPDDRA = (int *)0x400FF014;  /*Direccion de memoria del PDDR puerto A*/
	int *pPDDRB = (int *)0x400FF054;  /*Direccion de memoria del PDDR puerto B*/
	int *pPDDRC = (int *)0x400FF094;  /*Direccion de memoria del PDDR puerto C*/
	int *pPDDRD = (int *)0x400FF0D4;  /*Direccion de memoria del PDDR puerto D*/
	int *pPDDRE = (int *)0x400FF114;  /*Direccion de memoria del PDDR puerto E*/
	if(port == 'A' || port == 'B' || port == 'C' || port == 'D' || port == 'E')  /*Validacion de puerto*/
	{
		if(pin>=0 && pin <=31)  /*Validacion de pin*/
		{
			if(io == 'O' || io == 'I')  /*Validacion de configuracion*/
			{
				switch (port)
				{
					case 'A':	*pClock = (*pClock | dwClockV);  /*Enable del clock puerto A*/
								pPCR = (int *)(0x40049000 + (4 * pin));  /*Acceso a la memoria del puerto y pin seleccionado*/
								*pPCR = dwPCRV;  /*Valor que habilita el pin como GPIO*/
								if (io == 'O')
									*pPDDRA = *pPDDRA | (1 <<pin);  /*Valor para activacion del pin como output*/
								else
									*pPDDRA = *pPDDRA & ~(1<<pin);  /*Valor para activacion del pin como input*/
								break;
					case 'B':	*pClock = (*pClock | (dwClockV << 1));
								pPCR = (int *)(0x4004A000  + (4 * pin));
								*pPCR = dwPCRV;
								if (io == 'O')
									*pPDDRB = *pPDDRB | (1 <<pin);
								else
									*pPDDRB = *pPDDRB & ~(1<<pin);
								break;
					case 'C':	*pClock = (*pClock | (dwClockV << 2));
								pPCR = (int *)(0x4004B000 + (4 * pin));
								*pPCR = dwPCRV;
								if (io == 'O')
									*pPDDRC = *pPDDRC | (1 <<pin);
								else
									*pPDDRC = *pPDDRC & ~(1<<pin);
								break;
					case 'D':	*pClock = (*pClock | (dwClockV << 3));
								pPCR = (int *)(0x4004C000  + (4 * pin));
								*pPCR = dwPCRV;
								if (io == 'O')
									*pPDDRD = *pPDDRD | (1 <<pin);
								else
									*pPDDRD = *pPDDRD & ~(1<<pin);
								break;
					case 'E':	*pClock = (*pClock | (dwClockV << 4));
								pPCR = (int *)(0x4004D000 + (4 * pin));
								*pPCR = dwPCRV;
								if (io == 'O')
									*pPDDRE = *pPDDRE | (1 <<pin);
								else
									*pPDDRE = *pPDDRE & ~(1<<pin);
								break;
				}
			}
			else
				printf("\nError: configuracion no valida\n");
		}
		else
			printf("\nError: pin no valido\n");
	}
	else
		printf("\nError: puerto no valido\n");
}

void vfndigitalWire(char port, int pin, int value)
{
	int *pPDORA = (int *)0x400FF000;  /*Direccion de memoria de PDOR puerto A*/
	int *pPDORB = (int *)0x400FF040;  /*Direccion de memoria de PDOR puerto B*/
	int *pPDORC = (int *)0x400FF080;  /*Direccion de memoria de PDOR puerto C*/
	int *pPDORD = (int *)0x400FF0C0;  /*Direccion de memoria de PDOR puerto D*/
	int *pPDORE = (int *)0x400FF100;  /*Direccion de memoria de PDOR puerto E*/
	if(port == 'A' || port == 'B' || port == 'C' || port == 'D' || port == 'E')  /*Validacion de puerto*/
	{
		if(pin>=0 && pin <=31)  /*Validacion de pin*/
		{
			if(value == 1 || value == 0)  /*Validacion de valor*/
			{
				switch (port)
				{
					case 'A':	if(value == 1)
									*pPDORA = *pPDORA | (1 <<pin);  /*Asignacion de valor en PDOR*/
								else
									*pPDORA = *pPDORA & ~(1<<pin);  /*Asignacion de valor en PDOR*/
								break;
					case 'B':	if(value == 1)
									*pPDORB = *pPDORB | (1 <<pin);  /*Asignacion de valor en PDOR*/
								else
									*pPDORB = *pPDORB & ~(1<<pin);  /*Asignacion de valor en PDOR*/
								break;
					case 'C':	if(value == 1)
									*pPDORC = *pPDORC | (1 <<pin);  /*Asignacion de valor en PDOR*/
								else
									*pPDORC = *pPDORC & ~(1<<pin);  /*Asignacion de valor en PDOR*/
								break;
					case 'D':	if(value == 1)
									*pPDORD = *pPDORD | (1 <<pin);  /*Asignacion de valor en PDOR*/
								else
									*pPDORD = *pPDORD & ~(1<<pin);  /*Asignacion de valor en PDOR*/
								break;
					case 'E':	if(value == 1)
									*pPDORE = *pPDORE | (1 <<pin);  /*Asignacion de valor en PDOR*/
								else
									*pPDORE = *pPDORE & ~(1<<pin);  /*Asignacion de valor en PDOR*/
								break;
				}
			}
			else
				printf ("\nError: valor no valido\n");
		}
		else
			printf ("\nError: pin no valido\n");
	}
	else
		printf ("\nError: puerto no valido\n");
}

