/*=================================================================================================================================================
										 	  	 	 Trabajo Practico 1
											Martín Nicolás Alomo   -   División F
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
		puts("\n\n\n\nFinalizó el programa.");
	}
	else{
		puts("\n\n\n\nSe finalizó el programa de manera errónea.");
	}
	return EXIT_SUCCESS;
}
