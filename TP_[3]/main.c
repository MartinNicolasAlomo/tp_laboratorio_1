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
	int opcionMenu = 0;
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
    	puts("Falló la lectura del archivo.\n\n");
    }

    if(listaPasajeros!=NULL){
        do{
        	if(!ingresarEntero(&opcionMenu, MSJ_MENUPRINCIPAL, MSJ_ERROROPCION, 1, 10, REINTENTOS)){
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
    						puts("Se agregó el nuevo pasajero a la lista.\n\n");
    						flagCarga=2;
    						flagCambios=0;
    					}
    					else if(devolucion==-1){
    						puts("El puntero a LinkedList es NULL.\n\n\n");
    					}
    					else if(devolucion==-2){
    						puts("No se pudo crear el Pasajero, falló la Función Passenger_new.\n");
    					}
    					else if(devolucion==-3){
    						puts("Falló la carga de datos.\n\n\n");
    					}
    					else if(devolucion==-4){
    						puts("No se obtuvo ninguna confirmación. Volvió al menú principal.\n\n\n");
    					}
    					else if(devolucion==-5){
    						puts("Se canceló la operación. No se agregó el pasajero.\n\n\n");
    					}
    					else if(devolucion==-6){
    						puts("Se generó un ID invalido.\n\n\n");
    					}
    					else if(devolucion==-7){
    						puts("No se pudieron setear los datos correctamente.\n\n\n");
    					}
    					else{
    						puts("No se pudo agregar al pasajero a la lista, falló la función ll_add.\n");
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
        						puts("No se ingresó ningun ID para modificar.\n\n\n");
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
        			    		puts("No se ingresó una opcion correcta para modificar.\n\n\n");
    						}
    						else if(devolucion==-7){
  								puts("No se realizó ningun cambio en los datos del pasajero.\n\n\n");
    						}
    						else if(devolucion==-8){
        						puts("No se obtuvo ninguna confirmación. Volvió al menú principal.\n\n\n");
    						}
    						else if(devolucion==-9){
        						puts("Se canceló la operación. No se modificaron los datos del pasajero.\n\n\n");
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
    					    	puts("Se eliminó el pasajero exitosamente.\n\n");
    							flagCambios=0;
    						}
    						else if(devolucion==1){
    					    	puts("Se eliminó la lista completa exitosamente.\n\n");
    							flagCambios=0;
    						}
    						else if(devolucion==-1){
        						puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
        					else if(devolucion==-2){
        			    		puts("No se encontró un ID correcto en la lista.\n\n\n");
        					}
        					else if(devolucion==-3){
        			    		puts("Falló la impresión, no se pudo mostrar la lista.\n\n\n");
        					}
        					else if(devolucion==-4){
        			    		puts("No se ingresó una opcion de eliminado correcta.\n\n\n");
        					}
        					else if(devolucion==-5){
        						puts("No se ingresó ningun ID para eliminar.\n\n\n");
        					}
        					else if(devolucion==-6){
        						puts("No se pudo encontrar el ID buscado.\n\n\n");
        					}
    						else if(devolucion==-7){
    							puts("No se pudo obtener el pasajero.\n\n\n");
    						}
        					else if(devolucion==-8){
        						puts("No se obtuvo ninguna confirmación. Volvió al menú principal.\n\n\n");
        					}
        					else if(devolucion==-9){
        						puts("Se canceló la operación. No se eliminó el pasajero.\n\n\n");
        					}
        					else if(devolucion==-10){
        						puts("Se eliminó el pasajero de memoria pero no se pudo eliminar de la lista.\n\n\n");
        					}
        					else if(devolucion==-11){
        						puts("Se canceló la operación. No se eliminó la lista.\n\n\n");
        					}
        					else if(devolucion==-12){
    			        		puts("No se pudo eliminar la lista.\n\n\n");
        					}
        					else{
        						puts("Se eliminó de memoria pero no se pudo eliminar la lista.\n\n\n");
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
    					    	puts("Se imprimió la lista de pasajeros.\n\n");
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
    					    	puts("Se ordenó la lista de pasajeros segun el criterio y el orden ingresados.\n\n");
    						}
    						else if(devolucion==-1){
    							puts("El puntero a LinkedList es NULL.\n\n\n");
    						}
    						else if(devolucion==-2){
    							puts("No se ingresó un criterio por el cual ordenar la lista. Volvió al menú principal.\n\n\n");
    						}
    						else if(devolucion==-3){
    							puts("Usted volvió al Menú Principal.\n\n");
    						}
    						else{
    							puts("No se ingresó el orden para ordenar la lista. Volvió al menú principal.\n\n\n");
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
    							puts("La lista está vacia, no hay pasajeros.\n\n\n");
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
    							puts("La lista está vacia, no hay pasajeros.\n\n\n");
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
    							puts("La lista está vacia, no hay pasajeros.\n\n\n");
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
    							puts("La lista está vacia, no hay pasajeros.\n\n\n");
    						}
    					}
    					break;
    				case 10:
    					if(flagCambios){
    						puts("Usted finalizó la operación.\n\n");
							puts("\n\n\nFinalizó el programa.\n");
    						break;
    					}
    					else{
    						if(!ingresarEntero(&opcionGuardar, "\n\nHay cambios sin guardar ¿Desea guardar los cambios?\n1- Si, 0- No\n\n", MSJ_ERROROPCION, 0, 1, REINTENTOS)){
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
										puts("La lista está vacia, no hay pasajeros.\n\n\n");
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
										puts("La lista está vacia, no hay pasajeros.\n\n\n");
									}
    								puts("\n\n\nFinalizó el programa.\n");
    							}
    							else{
    								puts("No se guardó ningun dato.\n\n\n");
    								puts("\n\n\nFinalizó el programa.\n");
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

