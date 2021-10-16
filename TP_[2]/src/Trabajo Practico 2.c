/*=================================================================================================================================================

										 	  	 	 Trabajo Practico 2

											Martín Nicolás Alomo   -   División E

 ================================================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayEmployees.h"
#define	CANTEMPLEADOS 100

int main(void) {
	setbuf(stdout, NULL);
	Employee listaEmpleados[CANTEMPLEADOS];

	MenuEmpleados(listaEmpleados,CANTEMPLEADOS);
	return EXIT_SUCCESS;
}
