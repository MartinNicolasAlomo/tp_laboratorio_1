/*=================================================================================================================================================

										 	  	 	 Trabajo Practico 2

											Mart�n Nicol�s Alomo   -   Divisi�n 1-F

 ================================================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayPassenger.h"
#define	CANTEMPLEADOS 100

int main(void) {
	setbuf(stdout, NULL);
	if(!pasaj_menuPrincipal()){
		puts("Finaliz� el programa.");
	}
	else{
		puts("Hubo un fallo en el programa.");
	}
	return EXIT_SUCCESS;
}
