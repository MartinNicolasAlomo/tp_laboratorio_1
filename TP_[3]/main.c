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

#define ARCHIVO_CSV "data.csv"
#define ARCHIVO_BIN "data.bin"


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


int main(){
	setbuf(stdout, NULL);
	int opcionMenu=0;
	int devolucion;
	int flagCarga=1;
	int flagCambios=1;
	int opcionGuardar;

    LinkedList* listaPasajeros = ll_newLinkedList();

    devolucion=Controller_cargarUltimoId();
    if(devolucion==0){
    	puts("Ultimo id maximo cargado exitosamente.\n\n");
    }
    else if(devolucion==-1){
    	puts("La ruta del Archivo no es valida.\n\n");
    }
    else{
    	puts("Fall� la lectura del archivo.\n\n");
    }

    if(listaPasajeros!=NULL){
        do{
        	if(!ingresarEntero(&opcionMenu, MSJ_MENU_PRINCIPAL, MSJ_ERROR_OPCION, 1, 10, REINTENTOS)){
    			switch(opcionMenu){
    				case 1:
    					if(!flagCarga){
    						puts("Ya se cargaron los datos previamente, no se pueden volver a cargar.\n\n\n");
    					}
    					else{
    						devolucion = controller_loadFromText(ARCHIVO_CSV,listaPasajeros);
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
    							puts("No se pudo abrir el Archivo.\n\n\n");
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
    						devolucion = controller_loadFromBinary(ARCHIVO_BIN, listaPasajeros);
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
    						puts("Se agreg� el nuevo pasajero a la lista.\n\n");
    						flagCarga=2;
    						flagCambios=0;
    					}
    					else if(devolucion==-1){
    						puts("El puntero a LinkedList es NULL.\n\n\n");
    					}
    					else if(devolucion==-2){
    						puts("No se pudo crear el Pasajero, fall� la Funci�n Passenger_new.\n");
    					}
    					else if(devolucion==-3){
    						puts("Fall� la carga de datos.\n\n\n");
    					}
    					else if(devolucion==-4){
    						puts("No se obtuvo ninguna confirmaci�n. Volvi� al men� principal.\n\n\n");
    					}
    					else if(devolucion==-5){
    						puts("Se cancel� la operaci�n. No se agreg� el pasajero.\n\n\n");
    					}
    					else if(devolucion==-6){
    						puts("Se gener� un ID invalido.\n\n\n");
    					}
    					else if(devolucion==-7){
    						puts("No se pudieron setear los datos correctamente.\n\n\n");
    					}
    					else{
    						puts("No se pudo agregar al pasajero a la lista, fall� la funci�n ll_add.\n");
    					}
    					break;
    				case 4:
    					if(flagCarga==1){
    						puts("No hay pasajeros ingresados o cargados. Por favor, ingrese o carge pasajeros para poder operar.\n\n\n");
    					}
    					else{
    						devolucion = controller_editPassenger(listaPasajeros);
    						if(devolucion==0){
								puts("Se modificaron los datos del pasajero exitosamente.\n\n");
    							flagCambios=0;
    						}
    						else if(devolucion==-1){
        						puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
    						else if(devolucion==-2){
        						puts("No se ingres� ningun ID para modificar.\n\n\n");
    						}
    						else if(devolucion==-3){
        						puts("No se pudo encontrar el ID buscado.\n\n\n");
    						}
    						else if(devolucion==-4){
    							puts("No se pudo obtener el pasajero.\n\n\n");
    						}
    						else if(devolucion==-5){
    							puts("No se pudieron obtener los datos del pasajero.\n\n\n");
    						}
    						else if(devolucion==-6){
        			    		puts("No se ingres� una opcion correcta para modificar.\n\n\n");
    						}
    						else if(devolucion==-7){
  								puts("No se realiz� ningun cambio en los datos del pasajero.\n\n\n");
    						}
    						else if(devolucion==-8){
        						puts("No se obtuvo ninguna confirmaci�n. Volvi� al men� principal.\n\n\n");
    						}
    						else if(devolucion==-9){
        						puts("Se cancel� la operaci�n. No se modificaron los datos del pasajero.\n\n\n");
    						}
    						else {
        						puts("No se pudieron setear los datos correctamente.\n\n\n");
    						}
    					}
    					break;
    				case 5:
    					if(flagCarga==1){
    						puts("No hay pasajeros ingresados o cargados. Por favor, ingrese o carge pasajeros para poder operar.\n\n\n");
    					}
    					else{
    						devolucion = controller_removePassenger(listaPasajeros);
    						if(devolucion==0){
    					    	puts("Se elimin� el pasajero exitosamente.\n\n");
    							flagCambios=0;
    						}
    						else if(devolucion==1){
    					    	puts("Se elimin� la lista completa exitosamente.\n\n");
    							flagCambios=0;
    						}
    						else if(devolucion==-1){
        						puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
        					else if(devolucion==-2){
        			    		puts("No se encontr� un ID correcto en la lista.\n\n\n");
        					}
        					else if(devolucion==-3){
        			    		puts("Fall� la impresi�n, no se pudo mostrar la lista.\n\n\n");
        					}
        					else if(devolucion==-4){
        			    		puts("No se ingres� una opcion de eliminado correcta.\n\n\n");
        					}
        					else if(devolucion==-5){
        						puts("No se ingres� ningun ID para eliminar.\n\n\n");
        					}
        					else if(devolucion==-6){
        						puts("No se pudo encontrar el ID buscado.\n\n\n");
        					}
    						else if(devolucion==-7){
    							puts("No se pudo obtener el pasajero.\n\n\n");
    						}
        					else if(devolucion==-8){
        						puts("No se obtuvo ninguna confirmaci�n. Volvi� al men� principal.\n\n\n");
        					}
        					else if(devolucion==-9){
        						puts("Se cancel� la operaci�n. No se elimin� el pasajero.\n\n\n");
        					}
        					else if(devolucion==-10){
        						puts("Se elimin� el pasajero de memoria pero no se pudo eliminar de la lista.\n\n\n");
        					}
        					else if(devolucion==-11){
        						puts("Se cancel� la operaci�n. No se elimin� la lista.\n\n\n");
        					}
        					else{
    			        		puts("No se pudo eliminar la lista.\n\n\n");
        					}
    					}
    					break;
    				case 6:
    					if(flagCarga==1){
    						puts("No hay pasajeros ingresados o cargados. Por favor, ingrese o carge pasajeros para poder operar.\n\n\n");
    					}
    					else{
    						devolucion = controller_ListPassenger(listaPasajeros);
    						if(devolucion==0){
    					    	puts("Se imprimi� la lista de pasajeros.\n\n");
    						}
    						else if(devolucion==-1){
    							puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
    						else {
    				    		puts("La lista esta vacia, no hay pasajeros\n\n\n");
    						}
    					}
    					break;
    				case 7:
    					if(flagCarga==1){
    						puts("No hay pasajeros ingresados o cargados. Por favor, ingrese o carge pasajeros para poder operar.\n\n\n");
    					}
    					else{
    						devolucion = controller_sortPassenger(listaPasajeros);
    						if(devolucion==0){
    					    	puts("Se orden� la lista de pasajeros segun el criterio y el orden ingresados.\n\n");
    						}
    						else if(devolucion==-1){
    							puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
    						else if(devolucion==-2){
    							puts("No se ingres� un criterio por el cual ordenar la lista. Volvi� al men� principal.\n\n\n");
    						}
    						else if(devolucion==-3){
    							puts("Usted volvi� al Men� Principal.\n\n");
    						}
    						else{
    							puts("No se ingres� el orden para ordenar la lista. Volvi� al men� principal.\n\n\n");
    						}
    					}
    					break;
    				case 8:
    					if(flagCambios){
    						puts("No hay ningun cambio para guardar.\n\n\n");
    					}
    					else{
    						devolucion = controller_saveAsText(ARCHIVO_CSV, listaPasajeros);
							if(devolucion==0){
								puts("Se guardaron los cambios en modo texto exitosamente.\n\n");
    							flagCambios=1;
							}
    						else if(devolucion==-1){
    							puts("La ruta del Archivo no es valida.\n\n\n");
    						}
    						else if(devolucion==-2){
    							puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
    						else if(devolucion==-3){
    							puts("No se pudo abrir el Archivo.\n\n\n");
    						}
    						else {
    							puts("La lista est� vacia, no hay pasajeros.\n\n\n");
    						}
    						devolucion = controller_saveAsBinary(ARCHIVO_BIN, listaPasajeros);
    						if(devolucion==0){
    					    	puts("Se guardaron los cambios en modo binario exitosamente.\n\n");
    							flagCambios=1;
    						}
    						else if(devolucion==-1){
    							puts("La ruta del Archivo no es valida.\n\n\n");
    						}
    						else if(devolucion==-2){
    							puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
    						else if(devolucion==-3){
    							puts("No se pudo abrir el Archivo.\n\n\n");
    						}
    						else {
    							puts("La lista est� vacia, no hay pasajeros.\n\n\n");
    						}
    					}
    					break;
    				case 9:
    					if(flagCambios){
    						puts("No hay ningun cambio para guardar.\n\n\n");
    					}
    					else{
    						devolucion = controller_saveAsText(ARCHIVO_CSV, listaPasajeros);
							if(devolucion==0){
								puts("Se guardaron los cambios en modo texto exitosamente.\n\n");
    							flagCambios=1;
							}
    						else if(devolucion==-1){
    							puts("La ruta del Archivo no es valida.\n\n\n");
    						}
    						else if(devolucion==-2){
    							puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
    						else if(devolucion==-3){
    							puts("No se pudo abrir el Archivo.\n\n\n");
    						}
    						else {
    							puts("La lista est� vacia, no hay pasajeros.\n\n\n");
    						}
    						devolucion = controller_saveAsBinary(ARCHIVO_BIN, listaPasajeros);
    						if(devolucion==0){
    					    	puts("Se guardaron los cambios en modo binario exitosamente.\n\n");
    							flagCambios=1;
    						}
    						else if(devolucion==-1){
    							puts("La ruta del Archivo no es valida.\n\n\n");
    						}
    						else if(devolucion==-2){
    							puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
    						else if(devolucion==-3){
    							puts("No se pudo abrir el Archivo.\n\n\n");
    						}
    						else {
    							puts("La lista est� vacia, no hay pasajeros.\n\n\n");
    						}
    					}
    					break;
    				case 10:
    					if(flagCambios){
    						puts("Usted finaliz� la operaci�n.\n\n");
							puts("\n\n\nFinaliz� el programa.\n");
    						break;
    					}
    					else{
    						if(!ingresarEntero(&opcionGuardar, "\n\nHay cambios sin guardar �Desea guardar los cambios?\n1- Si, 0- No\n\n", MSJ_ERROR_OPCION, 0, 1, REINTENTOS)){
    							if(opcionGuardar){
									devolucion = controller_saveAsText(ARCHIVO_CSV, listaPasajeros);
									if(devolucion==0){
										puts("Se guardaron los cambios en modo texto exitosamente.\n");
									}
									else if(devolucion==-1){
										puts("La ruta del Archivo no es valida.\n\n\n");
									}
									else if(devolucion==-2){
										puts("El puntero a LinkedList es NULL.\n\n\n");
									}
									else if(devolucion==-3){
										puts("No se pudo abrir el Archivo.\n\n\n");
									}
									else {
										puts("La lista est� vacia, no hay pasajeros.\n\n\n");
									}
									devolucion = controller_saveAsBinary(ARCHIVO_BIN, listaPasajeros);
									if(devolucion==0){
										puts("Se guardaron los cambios en modo binario exitosamente.\n\n");
									}
									else if(devolucion==-1){
										puts("La ruta del Archivo no es valida.\n\n\n");
									}
									else if(devolucion==-2){
										puts("El puntero a LinkedList es NULL.\n\n\n");
									}
									else if(devolucion==-3){
										puts("No se pudo abrir el Archivo.\n\n\n");
									}
									else {
										puts("La lista est� vacia, no hay pasajeros.\n\n\n");
									}
    								puts("\n\n\nFinaliz� el programa.\n");
    							}
    							else{
    								puts("No se guard� ningun dato.\n\n\n");
    								puts("\n\n\nFinaliz� el programa.\n");
    								break;
    							}
    						}
    					}
    					break;
    			}
        	}
        }while(opcionMenu != 10);
    }
    return 0;
}
