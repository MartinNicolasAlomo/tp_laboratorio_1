#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayEmployees.h"
#define TRUE 0


int MenuEmpleados(Employee lista[], int limite){
	int opcion = 0;
		int flagAlta = 0;

		int contadorID = 0;
		char auxiliarNombre[50];
		char auxiliarApellido[50];
		float auxiliarSalario;
		int auxiliarSector;

		int indiceLugarLibre;
		//int indiceResultadoBusqueda;

		initEmployees(lista,limite);
		do {
			if (IngresarEntero(&opcion,
					"1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Salir\n",
					"No es una opcion valida, reintentelo de nuevo\n", 1, 5, 2)
					== 1) {

				printf("opcion elegida %d\n\n", opcion);
				switch (opcion) {
					case 1:
						/*ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
						de Id. El resto de los campos se le pedirá al usuario.*/


						indiceLugarLibre = BuscarPrimerOcurrenciaEmpleados(lista,limite,TRUE);
						if(indiceLugarLibre == -1){
							printf("No quedan espacios libres!\n");
							break;
						}

						if(IngresarNombre(auxiliarNombre,50,"Ingrese el nombre del empleado: \n","Error\n",2) == 1){
							printf("%s\n\n",auxiliarNombre);
						}
						else{
							puts("Nombre solo debe tener letras\n");
							break;
						}
						if(IngresarNombre(auxiliarApellido,50,"Ingrese el apellido del empleado: \n","Error\n",2) == 1){
							printf("%s\n\n",auxiliarApellido);
						}
						else{
							puts("Apellido solo debe tener letras\n");
							break;
						}
						if(IngresarFlotante(&auxiliarSalario, "Ingrese el salario del empleado: \n", "Error\n", 1, 10, 2) == 1){
							printf("%f\n\n",auxiliarSalario);
						}
						else{
							puts("Salario debe tener numeros y una coma como maximo\n");
							break;
						}
						if(IngresarEntero(&auxiliarSector, "Ingrese el sector donde trabaja: \n", "Error\n", 1, 10, 2) == 1){
							printf("%d\n\n",auxiliarSector);
						}
						else{
							puts("Sector debe tener numeros\n");
							break;
						}

						if(BuscarPrimerOcurrenciaEmpleados(lista,limite,contadorID) != TRUE){
							puts("Este ID ya existe\n");
						}
						contadorID++;
						lista[indiceLugarLibre].id= contadorID;
						printf("ID: %d\n\n",lista[indiceLugarLibre].id);
						strcpy(lista[indiceLugarLibre].name,auxiliarNombre);
						strcpy(lista[indiceLugarLibre].lastName,auxiliarApellido);
						lista[indiceLugarLibre].salary = auxiliarSalario;
						lista[indiceLugarLibre].sector = auxiliarSector;






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

return 0;
}





int initEmployees(Employee* list, int lenght){
	int i;

	if (list != NULL && lenght > 0) {
		for (i = 0; i < lenght; i++) {
			list[i].isEmpty = TRUE;
		}
	}
	return 0;
}

int BuscarPrimerOcurrenciaEmpleados(Employee lista[], int cantidadElementos,int valorInicial){
	int i;

	if (lista != NULL && cantidadElementos > 0) {
		for (i = 0; i < cantidadElementos; i++) {
			if(lista[i].isEmpty == TRUE){
				return i;
			}
		}
	}
	return -1;
}

int addEmployee(Employee* list, int lenght, int id, char name[],char lastName[],float salary,int sector){
	if (list != NULL && lenght > 0 && name != NULL && lastName != NULL){

	}

	return 1;
}

/*int findEmployeeById(Employee* list, int len,int id){

}

int removeEmployee(Employee* list, int len, int id){

}

int sortEmployees(Employee* list, int len, int order){

}

int printEmployees(Employee* list, int length){

}
*/
