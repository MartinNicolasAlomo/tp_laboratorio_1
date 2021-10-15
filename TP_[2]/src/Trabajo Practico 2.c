/*================================================================================================================================================

													 Trabajo Practico 2

											Martin Nicolas Alomo  -  Division E

 ================================================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Input.h>
#include <ArrayEmployees.h>
#define QTYEMPLOYEES 5

int main(void) {
	Employee employeeList[QTYEMPLOYEES]
	int option = 0;

	initEmployees(employeeList,QTYEMPLOYEES,-1);
	do {
		if (IngresarEntero(&option, "1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Ordenar\n6-Salir",
							"No es una opcion valida, reintentelo de nuevo\n", 1, 6, 3) == 1) {

			switch (option) {
			case 1:

				break;
			case 2:

				break;

			case 3:

				break;

			case 4:

				break;

			case 5:
				puts("Usted salió");
				break;
			}
		}
	} while (option != 5);


	return EXIT_SUCCESS;
}
