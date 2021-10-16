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
	char nombreIngresado[LARGONOMBRE];
	char apellidoIngresado[LARGOAPELLIDO];
	float salarioIngresado;
	int sectorIngresado;
	int contadorID = 0;
	int clienteID;
	int indiceLibre;
	int indiceBusqueda;
	int opcionOrdenar;
	float sumaSalarios = 0;
	int contadorSalarios = 0;


	initEmployees(lista, limite);
	do {
		if (IngresarEntero(&opcion,
				"1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Salir\n",
				"No es una opcion valida, reintentelo de nuevo\n", 1, 5, 2)
				== 1) {
			switch (opcion) {

			case 1:
				indiceLibre = BuscarPrimerOcurrenciaEmpleados(lista, limite);
				if (indiceLibre == -1) {
					printf("No quedan espacios libres!\n");
					break;
				}

				contadorID++;
				clienteID = contadorID;
				if(IngresarDatos(nombreIngresado, LARGONOMBRE, apellidoIngresado, LARGOAPELLIDO, &salarioIngresado, &sectorIngresado) == 1){
					if(addEmployee(lista, limite, clienteID, nombreIngresado, apellidoIngresado, salarioIngresado, sectorIngresado) == 1){
						puts("La carga fue exitosa");
					}
					else{
						puts("No se pudo cargar los datos");
					}
				}

				sumaSalarios = sumaSalarios + salarioIngresado;
				contadorSalarios++;

				flagAlta = 1;
				break;

			case 2:
				/*MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector*/
				/*if (flagAlta == 1) {

					if (IngresarEntero(&clienteID, "Ingrese el ID del cliente a modificar: \n", "Error\n", 1, 10, 2) == 1) {
						indiceBusqueda = findEmployeeById(lista, limite, contadorID);

						if (indiceBusqueda == i && lista[id].isEmpty == FALSE) {
							while (respuesta == 's') {
								if (IngresarEntero(&opcion, "Que desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Nada mas\n",
										"No es una opcion valida, reintentelo de nuevo\n", 1, 5, 2) == 1) {
									switch (opcion) {
									case 1:
										if (IngresarNombre(auxiliarNombre, 50, "Ingrese el nombre del empleado: \n", "Error\n", 2) == 1) {
											strncpy(lista[indiceLugarLibre].name, auxiliarNombre,LARGONOMBRE);
										}
										else {
											puts("Nombre solo debe tener letras\n");
											break;
										}
									case 2:
										if (IngresarNombre(auxiliarApellido, 50, "Ingrese el apellido del empleado: \n", "Error\n", 2) == 1) {
											strncpy(lista[indiceLugarLibre].lastName, auxiliarApellido,LARGOAPELLIDO);
										}
										else {
											puts("Apellido solo debe tener letras\n");
											break;
										}
									case 3:
										if (IngresarFlotante(&auxiliarSalario, "Ingrese el salario del empleado: \n", "Error\n", 1, 200000, 2) == 1) {
											lista[indiceBusqueda].salary = auxiliarSalario;
										}
										else {
											puts("Salario debe tener numeros y una coma como maximo\n");
											break;
										}
									case 4:
										if (IngresarEntero(&auxiliarSector, "Ingrese el sector donde trabaja: \n", "Error\n", 1, 10, 2) == 1) {
											lista[indiceBusqueda].sector = auxiliarSector;
										}
										else {
											puts("Sector debe tener numeros\n");
											break;
										}
									}
								}
							if(IngresarNombre(respuesta,2,"Desea modificar otro dato?")==1){
								if(strncmp(respuesta,"s",2) == 0)

							}
							}
						}

					}
					indiceBusqueda = BuscarPrimerOcurrenciaEmpleados(lista, limite, auxiliarID);

					if (indiceBusqueda == TRUE) {
						puts("No se encuentra el ID del cliente\n");
						break;
					}



				}
				else {
					puts("Todavia no se ha cargado ningun empleado");
				}

				break;*/

			case 3:
				/*BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.*/
				if (flagAlta == 1) {
					if (IngresarEntero(&clienteID, "Ingrese el ID del cliente a dar de baja: \n", "Error\n", 1, contadorID, 2) == 1) {
						indiceBusqueda = findEmployeeById(lista, limite, clienteID);
						if (indiceBusqueda != 0){
							if(removeEmployee(lista, limite, clienteID) == 1){
								puts("Se dio de baja al cliente");
							}
						}
						else{
							puts("No se encontro el cliente");
						}
					}
				}
				else {
					puts("Todavia no se ha cargado ningun empleado");
				}

				break;

			case 4:
				/*INFORMAR:
				1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
				2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.*/
				if (flagAlta == 1) {
					if (IngresarEntero(&opcionOrdenar, "Ingrese 1 para ordenar descendente o 2 para ascendente: \n", "Error\n", 1, 2, 2) == 1){
						if(sortEmployees(lista, limite, opcionOrdenar) == 0){
							puts("No se pudo ordenar");
						}
						if(printEmployees(lista, limite) == 0){
							puts("No se pudo imprimir");
						}
					}
					if(CalcularYMostrarSalarios(lista, limite, sumaSalarios, contadorSalarios) == 0){
						puts("No se pudo informar los salarios");
					}
				} else {
					puts("Todavia no se ha cargado ningun empleado");
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

	printf("El total de los salarios ingresados es %.2f y el promedio es de %.2f.\n La cantidad de empleados que superan el salario promedio es %d\n",totalSalarios,promedio,contadorSalariosMayorPromedio);
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
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/*int MenuOpciones(int vector[], int limite, int estadoInicial, int minimo, int maximo) {
	int opcionCambio;
	float promedio;
	int flagInicial = 0;
	int flagCarga = 0;

	do {
		if (IngresarEntero(&opcionCambio,
				"Seleccione una opcion: \n\n1-Inicializar\n2-Cargar\n3-Mostrar\n4-Calcular Promedio\n5-Ordenar\n6-Salir",
				"No es una opcion valida, reintentelo de nuevo\n", 1, 6, 3)
				== 1) {

			switch (opcionCambio) {
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:
				puts("Usted salió de la calculadora\n");
				break;
			}
		}
	} while (opcion != 5);
	return 0;
}*/

int removeEmployee(Employee* list, int lenght, int id){
	int retorno = 0;
	int i;

	if (list != NULL && lenght > 0 && id >= 0) {
		retorno = 1;
		for (i = 0; i < lenght; i++) {
			if(list[i].id == id){
				list[id].isEmpty = TRUE;
				break;
			}
		}
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
		printf("ID\tNombre\tApellido\tSalario\tSector\n");

		for (i = 0; i < length; i++) {
			if (list[i].isEmpty == FALSE){
				printf("%4d %8s %8s %9.2f %4d\n\n", list[i].id, list[i].name,list[i].lastName, list[i].salary, list[i].sector);
				//printf("%4d %8s %8s %9.2f %4d\n\n",clienteID, nombreIngresado,apellidoIngresado,salarioIngresado,sectorIngresado);
			}
		}
	}
	return retorno;
}
