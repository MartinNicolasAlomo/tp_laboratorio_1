/*=================================================================================================================================================
										 	  	 	 Trabajo Practico 1
											Mart�n Nicol�s Alomo   -   Divisi�n F
 ================================================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"
#include "Validations.h"
#include "Operations.h"

int main(void) {
	setbuf(stdout, NULL);
	if(!menuOpcionesEmpresas()){
		puts("\n\n\n\nFinaliz� el programa.");
	}
	else{
		puts("\n\n\n\nSe finaliz� el programa de manera err�nea.");
	}
	return EXIT_SUCCESS;
}
