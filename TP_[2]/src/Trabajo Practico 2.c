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
#define	CANTEMPLEADOS 5

int main(void) {
	setbuf(stdout, NULL);
	Employee listaEmpleados[CANTEMPLEADOS];
	int opcion = 0;
	int flagAlta = 0;

	int contadorID = 0;
	char auxiliarNombre[50];
	char auxiliarApellido[50];
	float auxiliarSalario;
	int auxiliarSector;

	int indiceLugarLibre;
	int indiceResultadoBusqueda;

	//initEmployees(listaEmpleados,CANTEMPLEADOS,-1);
	do {
		if (IngresarEntero(&opcion,
				"1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Salir\n",
				"No es una opcion valida, reintentelo de nuevo\n", 1, 5, 2)
				== 1) {
			printf("opciin elegida %d", opcion);
			switch (opcion) {
				case 1:
					/*ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
					de Id. El resto de los campos se le pedirá al usuario.*/
					contadorID++;

					indiceLugarLibre = BuscarPrimerOcurrenciaPersonas(arrayPersonas,CANTPERSONAS,-1);
					if(indiceLugarLibre == -1){
						printf("No quedan espacios libres!\n");
						break;
					}

					puts("Alta\n");

					if(IngresarNombre(auxiliarNombreStr,50,"Nombre: \n","Error\n",2) == 1){
						printf("%s\n",auxiliarNombreStr);
					}
					else{
						puts("Nombre debe tener letras\n");
						break;
					}
					if(IngresarNombre(auxiliarApellidoStr,50,"Apellido: \n","Error\n",2) == 1){
						printf("%s\n",auxiliarApellidoStr);
					}
					else{
						puts("Apellido debe tener letras\n");
						break;
					}
					if(IngresarEntero(&auxiliarLegajo, "Legajo: \n", "Error\n", 1, 10, 2) == 1){
						printf("%d\n",auxiliarLegajo);
					}
					else{
						puts("Legajo debe tener numeros\n");
						break;
					}

					if(BuscarPrimerOcurrenciaPersonas(arrayPersonas,CANTPERSONAS,auxiliarLegajo) != -1){
						puts("El legajo ya existe\n");
					}
					strcpy(arrayPersonas[indiceLugarLibre].nombre,auxiliarNombreStr);
					strcpy(arrayPersonas[indiceLugarLibre].apellido,auxiliarApellidoStr);
					arrayPersonas[indiceLugarLibre].legajo = auxiliarLegajo;





























				flagAlta = 1;
					break;

				case 2:
					if(flagAlta == 1){





					}
					else{
						puts("No se ha cargado ningun empleado");
					}

					break;

				case 3:
					if(flagAlta == 1){





					}
					else{
						puts("No se ha cargado ningun empleado");
					}

					break;

				case 4:
					if(flagAlta == 1){
						puts("Informe:\n");




					}
					else{
						puts("No se ha cargado ningun empleado");
					}



					break;
				case 5:
					puts("Usted salió\n");
					break;
			}
		}
	} while (opcion != 5);

	return EXIT_SUCCESS;
}
