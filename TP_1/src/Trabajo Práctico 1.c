/*=================================================================================================================================================

										 	  	 	 Trabajo Practico 1

											Mart�n Nicol�s Alomo   -   Divisi�n F

 ================================================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Ingresos.h"
#include "Validaciones.h"
#include "Operaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	if(!menuOpcionesEmpresas()){
		puts("Finaliz� el programa.");
	}
	else{
		puts("Hubo un fallo en el programa.");
	}
	return EXIT_SUCCESS;
}
