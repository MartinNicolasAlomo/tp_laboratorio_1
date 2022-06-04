#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Input.h"
#include "parser.h"
#include "Validations.h"
#define ARCHIVO "data.csv"



/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


/*
 * 1- Preocuparme por poder parsear el archivo en modo texto (data.csv) como video Class YouTube Davila
 	 y hacer la funcion que los recorre e imprime. pregunrrar cuantos elementos tiene la lista, si tiene tamaño X,
 	 hacer un FOR, desde 0 hasta X, y con el GET obetmenos los elementos del tipo pasajero y los vamos imprmiendo.
 	 Para eso genera auxiliar empleado par que cada elemento que se extraemos de la lista lo  guardamos en ese auxiliar
 	 y de esta manera podemos accdere a sus campos, ya que la lsita devuelve puntero a VOID, ay qeu castearlo a pasajero
 	 y guardarlo en un auxiliar punteroPasajero para acceder a los campos
 	 Una vez que pude cargar toda la lista en memoria y pude listarlos y me quedo tranuqilo que pude levatnar tod0 en mmoria


 * 2- Seguir con el alta, baja y modificacion de lo que tengo en memoria


 * 3- Una vez terminado lo anterior, me pongo a trabajar con guardar el archivo en modo texto. NO GUARDAR EN EL MISMO ARCHIVO
 	 hastq ue no estoy seguro que esta tod0 bien (guardar en data2.csv hastq eu se que el formato es correcto);


 * 4- Hacer la funcion de ORDENAR, osea, la funcion criterio y poder ordenar ATRAVES DE LL_SORT
 	 La funcion criterio recibe dos punteros a void y los compara por alguno de sus campos y termine estableciendo un orden
 	 ***Se puede order por cualquiera de sus campos*** 	CHEQUEaar
 	 LA FUNCION CRITERIO  VA EN LA BIBLIOTECA DE PASAJERO, poque establece el criterio de orden entre dos pasajeros


 * 5- La entidad pasajero ya esta creada, faltan agregar y hacer las funciones.
 	 newParametros esta planteado para ponder todos como char facilita recibir data en modo texto
 	 en la biblioteca de pasajeros, se puede agregar PASSENGER__SETIDTXT / SETPRECIOTXT
 	 Agregar parametros a newParametros segun corresponda




 * La biblioteca CONTROLLER es para poder serpara un poco mas el codigo como para que quede mas ordenado.
 	 Las cosas estan hecahas para hacerlas dentro de esa biblioteca
 	 COMPLETAR LAS FUNCIONES DE LA BIBLIOTECA
 	 HACER LLAMADOS DE LAS FUNCIONES DE CONTROLLER EN EL MAIN



 * La biblioteca PARSER tiene 2 funciones pensadad para que me queden dentro el codigoque teien que ver con desarmar
 	fuera de esa funcion abrmos el archivo, verificamos que pudimos abrirlo y llamo a la funcion parser_MODOTEXTO o Binario segun
 	y le pasamos la lista y el puntero al archivo, y dentro del codigo va el resto que tiene que ver con parsear el archivo, desarmarlo
 	Cada vez que logro parsear un pasajero

 	tAMBIEN DETERMINAR EL ID MAXIMO Y RETORNARLO SI SALIO BIEN, O -1 SI ERROR





 */




int main(){
	setbuf(stdout, NULL);
	int option = 0;
	int devolucion;
	int flagCarga=1;
	int flagCambios=1;
	int opcionDeseaGuardar;
	int opcionModoGuardado;


    LinkedList* listaPasajeros = ll_newLinkedList();

	//controller_loadFromBinary("data.csv", listaPasajeros);
    //CHEQUAR		CUANDO SE GUARDEN CAMBIOS	Y DESPUES SE VUELVAN A HACER CAMBIOS	PREGUNTAR SIEMPRE SI SE QUIEREN GUARDAR		CONTADOR
	// "..\\data.csv"

    do{
    	if(!ingresarEntero(&option, MSJ_MENUINGRESO, MSJ_ERROROPCION, 1, 10, REINTENTOS)){
			switch(option){
				case 1:

					if(!flagCarga){
						puts("Ya se cargaron los datos previamente, no se pueden volver a cargar.\n\n\n");
					}
					else{
						devolucion = controller_loadFromText(ARCHIVO,listaPasajeros);
						if(devolucion==0){
					    	puts("Archivo en modo texto cargado exitosamente.\n\n");
							flagCarga=0;
						}
						else if(devolucion==-1){
							puts("La ruta del Archivo no es valida.\n\n\n");
						}
						else if(devolucion==-2){
							puts("El puntero a LinkedList es NULL.\n\n\n");
						}
						else if(devolucion==-3){
							puts("No se pudo abrir el archivo.\n\n\n");
						}
						else {
							puts("No se pudieron parsear los Datos del Archivo.\n\n\n");
						}
					}
					break;
				case 2:
					if(!flagCarga){
						puts("Ya se cargaron los datos previamente, no se pueden volver a cargar.\n\n\n");
					}
					else{
						devolucion = controller_loadFromBinary(ARCHIVO, listaPasajeros);
						if(devolucion==0){
					    	puts("Archivo en modo binario cargado exitosamente.\n\n");
							flagCarga=0;
						}
						else if(devolucion==-1){
							puts("La ruta del Archivo no es valida.\n\n\n");
						}
						else if(devolucion==-2){
							puts("El puntero a LinkedList es NULL.\n\n\n");
						}
						else if(devolucion==-3){
							puts("No se pudo abrir el archivo.\n\n\n");
						}
						else {
							puts("No se pudieron parsear los Datos del Archivo.\n\n\n");
						}
					}
					break;
				case 3:
					devolucion = controller_addPassenger(listaPasajeros);
					if(devolucion==0){
						puts("Se agregó el nuevo pasajero a la lista.\n\n");
						flagCarga=0;
						flagCambios=0;
					}
					else if(devolucion==-1){
				//		puts("La ruta del Archivo no es valida.\n\n\n");
					}
					else if(devolucion==-2){
				//		puts("El puntero a LinkedList es NULL.\n\n\n");
					}
					else if(devolucion==-3){
				//		puts("No se pudo abrir el archivo.\n\n\n");
					}
					else {
				//		puts("No se pudieron parsear los Datos del Archivo.\n\n\n");
					}

					break;
				case 4:
					if(flagCarga){
						puts("No hay pasajeros ingresados o cargados. Por favor, ingrese o carge pasajeros para poder operar.\n\n\n");
					}
					else{
						devolucion = controller_editPassenger(listaPasajeros);
						if(devolucion==0){
					    	puts("Se modificó el pasajero exitosamente.\n\n");
							flagCambios=0;
						}
						else if(devolucion==-1){
					//		puts("La ruta del Archivo no es valida.\n\n\n");
						}
						else if(devolucion==-2){
					//		puts("El puntero a LinkedList es NULL.\n\n\n");
						}
						else if(devolucion==-3){
					//		puts("No se pudo abrir el archivo.\n\n\n");
						}
						else {
					//		puts("No se pudieron parsear los Datos del Archivo.\n\n\n");
						}
					}


					break;
				case 5:
					if(flagCarga){
						puts("No hay pasajeros ingresados o cargados. Por favor, ingrese o carge pasajeros para poder operar.\n\n\n");
					}
					else{
						devolucion = controller_removePassenger(listaPasajeros);
						if(devolucion==0){
					    	puts("Se eliminó el pasajero exitosamente.\n\n");
							flagCambios=0;
						}
						else if(devolucion==-1){
					//		puts("La ruta del Archivo no es valida.\n\n\n");
						}
						else if(devolucion==-2){
					//		puts("El puntero a LinkedList es NULL.\n\n\n");
						}
						else if(devolucion==-3){
					//		puts("No se pudo abrir el archivo.\n\n\n");
						}
						else {
					//		puts("No se pudieron parsear los Datos del Archivo.\n\n\n");
						}
					}
					break;
				case 6:
					if(flagCarga){
						puts("No hay pasajeros ingresados o cargados. Por favor, ingrese o carge pasajeros para poder operar.\n\n\n");
					}
					else{
						devolucion = controller_ListPassenger(listaPasajeros);
						if(devolucion==0){
					    	puts("Se listó la lista de pasajeros exitosamente.\n\n");
						}
						else if(devolucion==-1){
					//		puts("La ruta del Archivo no es valida.\n\n\n");
						}
						else if(devolucion==-2){
					//		puts("El puntero a LinkedList es NULL.\n\n\n");
						}
						else if(devolucion==-3){
					//		puts("No se pudo abrir el archivo.\n\n\n");
						}
						else {
					//		puts("No se pudieron parsear los Datos del Archivo.\n\n\n");
						}
					}
					break;
				case 7:
					if(flagCarga){
						puts("No hay pasajeros ingresados o cargados. Por favor, ingrese o carge pasajeros para poder operar.\n\n\n");
					}
					else{
						devolucion = controller_sortPassenger(listaPasajeros);
						if(devolucion==0){
					    	puts("Se listó la lista de pasajeros exitosamente.\n\n");
						}
						else if(devolucion==-1){
					//		puts("La ruta del Archivo no es valida.\n\n\n");
						}
						else if(devolucion==-2){
					//		puts("El puntero a LinkedList es NULL.\n\n\n");
						}
						else if(devolucion==-3){
					//		puts("No se pudo abrir el archivo.\n\n\n");
						}
						else {
					//		puts("No se pudieron parsear los Datos del Archivo.\n\n\n");
						}
					}
					break;
				case 8:
					if(flagCambios){
						puts("No hay ningun cambio para guardar.\n\n\n");
					}
					else{
						devolucion = controller_saveAsText(ARCHIVO, listaPasajeros);
						if(devolucion==0){
					    	puts("Se guardaron los cambios en modo texto exitosamente.\n\n");
							flagCambios=1;
						}
						else if(devolucion==-1){
					//		puts("La ruta del Archivo no es valida.\n\n\n");
						}
						else if(devolucion==-2){
					//		puts("El puntero a LinkedList es NULL.\n\n\n");
						}
						else if(devolucion==-3){
					//		puts("No se pudo abrir el archivo.\n\n\n");
						}
						else {
					//		puts("No se pudieron parsear los Datos del Archivo.\n\n\n");
						}
					}
					break;
				case 9:
					if(flagCambios){
						puts("No hay ningun cambio para guardar.\n\n\n");
					}
					else{
						devolucion = controller_saveAsBinary(ARCHIVO, listaPasajeros);
						if(devolucion==0){
					    	puts("Se guardaron los cambios en modo binario exitosamente.\n\n");
							flagCambios=1;
						}
						else if(devolucion==-1){
					//		puts("La ruta del Archivo no es valida.\n\n\n");
						}
						else if(devolucion==-2){
					//		puts("El puntero a LinkedList es NULL.\n\n\n");
						}
						else if(devolucion==-3){
					//		puts("No se pudo abrir el archivo.\n\n\n");
						}
						else {
					//		puts("No se pudieron parsear los Datos del Archivo.\n\n\n");
						}
					}
					break;
				case 10:
					if(flagCambios){
						puts("Usted finalizó la operación.\n\n");
						break;
					}
					else{
						if(!ingresarEntero(&opcionDeseaGuardar, "Hay cambios sin guardar ¿Desea guardar los cambios?\n1- Si, 2- No\n\n", MSJ_ERROROPCION, 1, 2, REINTENTOS)){
							if(opcionDeseaGuardar==1){
								if(!ingresarEntero(&opcionModoGuardado, "¿De qué modo lo quiere guardar?\n1- Texto, 2- Binario\n\n", MSJ_ERROROPCION, 1, 2, REINTENTOS)){
									if(opcionModoGuardado==1){
						//	CONTROLLER 	MODO TEXTO
									}
									else{
						//	CONTROLLER 	MODO BINARIO
									}
								}
								else{
								puts("No se pudo seleccionar opcion de modo\n\n\n");
								}
							}
							else{
								puts("No se guardo ningun dato\n\n\n");
								break;
							}
						}
					}
					break;
			}
    	}
    }while(option != 10);




	int edad=24;
	printf("tengo %d años\n",edad);
    puts("ANDA OK");
    return 0;
}

