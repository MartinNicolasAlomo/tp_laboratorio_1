#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "ArrayEmployees.h"
#define TRUE 1
#define FALSE 0
#define LARGONOMBRE 51
#define LARGOAPELLIDO 51

int MenuEmpleados(Employee lista[], int limite) {
	int opcion = 0;
	int flagAlta = 0;
	int clienteID;
	char nombreIngresado[LARGONOMBRE];
	char apellidoIngresado[LARGOAPELLIDO];
	float salarioIngresado;
	int sectorIngresado;
	int contadorID = 0;
	int idEncontrado;
	int indiceLibre;
	int opcionOrdenar;
	float sumaSalarios = 0;
	int contadorSalarios = 0;


	initEmployees(lista, limite);
	do {
		if (IngresarEntero(&opcion,	"1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Salir\n",
						   "\nNo es una opcion valida, reintentelo de nuevo", 1, 5, 2) == 1) {
			switch (opcion) {

			case 1:
				indiceLibre = BuscarPrimerOcurrenciaEmpleados(lista, limite);
				if (indiceLibre == -1) {
					printf("\nNo quedan espacios libres!");
					break;
				}

				contadorID++;
				clienteID = contadorID;
				if(IngresarDatos(nombreIngresado, LARGONOMBRE, apellidoIngresado, LARGOAPELLIDO, &salarioIngresado, &sectorIngresado) == 1){
					if(addEmployee(lista, limite, clienteID, nombreIngresado, apellidoIngresado, salarioIngresado, sectorIngresado) == 1){
						puts("\nLa carga fue exitosa");
					}
					else{
						puts("\nNo se pudo cargar los datos");
					}
				}

				sumaSalarios = sumaSalarios + salarioIngresado;
				contadorSalarios++;

				flagAlta = 1;
				break;

			case 2:
				/*MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector*/
				if (flagAlta == 1) {
					if (IngresarEntero(&clienteID, "\nIngrese el ID del cliente que desea modificar", "\nError", 1, contadorID, 2) == 1){
						idEncontrado = findEmployeeById(lista, limite, clienteID);
					}
					if(MenuCambioDatosEmpleados(nombreIngresado, LARGONOMBRE, apellidoIngresado, LARGOAPELLIDO, &salarioIngresado, &sectorIngresado) == 1){
						if(IngresarDatos(nombreIngresado, LARGONOMBRE, apellidoIngresado, LARGOAPELLIDO, &salarioIngresado, &sectorIngresado) == 1){
							if(addEmployee(lista, limite, clienteID, nombreIngresado, apellidoIngresado, salarioIngresado, sectorIngresado) == 1){
								puts("\nLa carga fue exitosa");
							}
							else{
								puts("\nNo se pudo cargar los datos");
							}
						}
					}
				}
				else {
					puts("\nTodavia no se ha cargado ningun empleado");
				}

				break;

			case 3:
				/*BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.*/
				if (flagAlta == 1) {
					if (IngresarEntero(&contadorID, "\nIngrese el ID del cliente a dar de baja: ", "\nError", 1, contadorID, 2) == 1) {
						idEncontrado = findEmployeeById(lista, limite, contadorID);
						if(idEncontrado == contadorID){
							puts("coinciden");
						}
							if(removeEmployee(lista, limite, idEncontrado) == 1){
								puts("\nSe dio de baja al cliente");
							}

						else{
							puts("\nNo se encontro el cliente");
						}
					}
				}
				else {
					puts("\nTodavia no se ha cargado ningun empleado");
				}

				break;

			case 4:
				if (flagAlta == 1) {
					if (IngresarEntero(&opcionOrdenar, "\nIngrese 1 para ordenar descendente o 2 para ascendente: ", "\nError", 1, 2, 2) == 1){
						if(sortEmployees(lista, limite, opcionOrdenar) == 0){
							puts("\nNo se pudo ordenar");
						}
						if(printEmployees(lista, limite) == 0){
							puts("\nNo se pudo imprimir");
						}
					}
					if(CalcularYMostrarSalarios(lista, limite, sumaSalarios, contadorSalarios) == 0){
						puts("\nNo se pudo informar los salarios");
					}
				} else {
					puts("\nTodavia no se ha cargado ningun empleado");
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

int CalcularYMostrarSalarios(Employee* lista,int limite,float totalSalarios,int cantidadSalarios){
	int retorno = 0;
	int i;
	float promedio;
	int contadorSalariosMayorPromedio = 0;



	if (lista != NULL && limite > 0){
		retorno = 1;
		promedio  = totalSalarios / cantidadSalarios;
		for(i=0;i<limite;i++){
			if(lista[i].salary > promedio){
				contadorSalariosMayorPromedio++;
			}
		}
	}

	printf("\nEl total de los salarios ingresados es %.2f y el promedio es de %.2f.\n La cantidad de empleados que superan el salario promedio es %d\n",totalSalarios,promedio,contadorSalariosMayorPromedio);
	return retorno;
}

int initEmployees(Employee *list, int lenght) {
	int i;
	int retorno = 0;
	if (list != NULL && lenght > 0) {
		retorno = 1;
		for (i = 0; i < lenght; i++) {
			list[i].isEmpty = TRUE;
		}
	}
	return retorno;
}

int BuscarPrimerOcurrenciaEmpleados(Employee lista[], int cantidadElementos) {
	int i;
	int retorno = 0;
	if (lista != NULL && cantidadElementos > 0) {
		for (i = 0; i < cantidadElementos; i++) {
			if (lista[i].isEmpty == TRUE) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addEmployee(Employee *list, int lenght, int id, char name[], char lastName[], float salary, int sector) {
	int retorno = 0;
	Employee auxEmpleado;
	if (list != NULL && lenght > 0 && name != NULL && lastName != NULL) {
		retorno = 1;
		auxEmpleado.id = id;
		strcpy(auxEmpleado.name, name);
		strcpy(auxEmpleado.lastName, lastName);
		auxEmpleado.salary = salary;
		auxEmpleado.sector = sector;
		auxEmpleado.isEmpty = FALSE;
		list[id] = auxEmpleado;
	}
	else{
		puts("No se pudo cargar los datos correctamente.\n\n");
	}
	return retorno;
}

int findEmployeeById(Employee *list, int lenght, int id) {
	int i;
	int retorno = 0;
	if (list != NULL && lenght > 0 && id >= 0) {
		retorno = 1;
		for (i = 0; i < lenght; i++) {
			if(list[i].id == id){
				retorno = id;
				break;
			}
		}
	}
	return retorno;
}

int removeEmployee(Employee* list, int lenght, int id){
	int retorno = 0;
	if (list != NULL && lenght > 0 && id >= 0) {
		retorno = 1;
		list[id].id = TRUE;
	}
	return retorno;
 }

int sortEmployees(Employee *list, int lenght, int order) {
	int i;
	int flagSwap;
	int retorno = 0;
	Employee auxiliar;
	int nuevoLimite;

	if (list != NULL && lenght >= 0) {
		nuevoLimite = lenght - 1;
		if(order == 1){
			do {
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++) {
					if (strncmp(list[i].lastName,list[i + 1].lastName,LARGOAPELLIDO) > 0 ||
						(strncmp(list[i].lastName,list[i + 1].lastName,LARGOAPELLIDO) == 0 && list[i].sector > list[i + 1].sector)) {
						flagSwap = 1;
						auxiliar = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxiliar;
					}
				}
				nuevoLimite--;
			} while (flagSwap == 1);
			retorno = 1;
		}

		if(order == 2){
			do {
				flagSwap = 0;
				for (i = 0; i < nuevoLimite; i++) {
					if (strncmp(list[i].lastName,list[i + 1].lastName,LARGOAPELLIDO) < 0 ||
						(strncmp(list[i].lastName,list[i + 1].lastName,LARGOAPELLIDO) == 0 && list[i].sector < list[i + 1].sector)) {
						flagSwap = 1;
						auxiliar = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxiliar;
					}
				}
				nuevoLimite--;
			} while (flagSwap == 1);
			retorno = 1;
		}
	}
	return retorno;
}

int printEmployees(Employee *list, int length) {
	int i;
	int retorno = 0;

	if (list != NULL && length > 0) {
		retorno = 1;
		printf("  ID\tNombre\tApellido\tSalario\tSector\n");

		for (i = 0; i < length; i++) {
			if (list[i].isEmpty == FALSE){
				printf("%4d %8s %12s %9.2f %4d\n\n", list[i].id, list[i].name,list[i].lastName, list[i].salary, list[i].sector);
			}
		}
	}
	return retorno;
}
