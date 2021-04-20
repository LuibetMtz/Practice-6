#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "ADC.h"
#include "GPIO.h"
#define limite 102 // 255 = 100%  102=40%

void bounce(void);
int   cont = 0;

int main(void){

	int i;
	int *ADCresult = (int*)0x4003B010; // direccion del Resultado del ADC usado (en este caso el A)
	int *PDIR_Boton = (int *)0x400FF090;//PDIR del boton

/*
	vfnpinMode('C', 1, 'I');
	while(1){
	printf("%i",*PDIR_Boton);
	}
*/
	vfnpinMode('D', 1, 'O');
	vfnpinMode('B', 18, 'O');
	vfnpinMode('B', 19, 'O');
	vfndigitalWire('D', 1, 1);
	vfndigitalWire('B', 18, 1);
	vfndigitalWire('B', 19, 1);

while(1){

	cont = 0;
	vfnpinMode('C', 1, 'O');
	vfnConfADC();
	printf("%i\n", *ADCresult);

	if(*ADCresult > limite){
		for(i=0; i < 150; i++ ){ //150 30seg de lectura del ADC,
			vfnConfADC();
			printf("%i\n", *ADCresult);
			if(*ADCresult < limite)
			break;//break if pasar al while
		}//end for lector ADC

		while(*PDIR_Boton != 0x2){		// verificar  si el boton esta encendido
			for(i=0; i<1000000; i++){  // tiempo de duracion de led encendido 1000000

					//printf("%i\n", *PDIR_Boton);
					if(*PDIR_Boton == 0x2){			//si el boton esta encendido = apagar leds Contador=6 para salir de secuencia
						cont = 6;		//apgar leds
						bounce();
						break;
					} // break for saltar al if
			}//end for leds

			if(cont != 6){
							bounce();
			}//end if end bounce
	    }//end while boton
	}//end if
}//while1
}//main

void bounce(){

	vfnpinMode('C', 1, 'I');

		switch(cont){
			case 0: //Estado 0 rojo
				vfndigitalWire('D', 1, 1);
				vfndigitalWire('B', 18, 0);
				vfndigitalWire('B', 19, 1);
				cont++; break;
			case 1: //Estado 1 verde
				vfndigitalWire('D', 1, 1);
				vfndigitalWire('B', 18, 1);
				vfndigitalWire('B', 19, 0);
				cont++; break;
			case 2://Estado 2 azul
				vfndigitalWire('D', 1, 0);
				vfndigitalWire('B', 18, 1);
				vfndigitalWire('B', 19, 1);
				cont++; break;
			case 3: //Estado 3 blanco
				vfndigitalWire('D', 1, 0);
				vfndigitalWire('B', 18, 0);
				vfndigitalWire('B', 19, 0);
				cont++; break;
			case 4: //Estado 4 azul
				vfndigitalWire('D', 1, 0);
				vfndigitalWire('B', 18, 1);
				vfndigitalWire('B', 19, 1);
				cont++; break;
			case 5:	//Estado 5 verde
				vfndigitalWire('D', 1, 1);
				vfndigitalWire('B', 18, 1);
				vfndigitalWire('B', 19, 0);
				cont = 0; break;
			case 6:
				vfndigitalWire('D', 1, 1);
				vfndigitalWire('B', 18, 1);
				vfndigitalWire('B', 19, 1);
			    break;
}}
