/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Computer.h"
#include "Controller.h"
#include "Input.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validations.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#define MSJ_MENUPRINCIPAL "1. Cargar los datos desde el archivo data.csv (modo texto).\n2. Ordernar lista por idTipo.\n3. Imprimir lista.\n4. Funcion map.\n5. Generar archivo de salida\n6. Salir\n\n"
#define MSJ_ERROROPCION "No es una opción válida, reinténtelo de nuevo.\n\n\n"


int main(void){
	setbuf(stdout, NULL);
	int opcionMenu=0;
	char nombreArchivoCSV[LARGODESCRIPCION];
	int devolucion;
	int flagCarga=1;
	int flagCambios=1;

    LinkedList* listaComputadoras = ll_newLinkedList();

    if(listaComputadoras!=NULL){
        do{
        	if(!ingresarEntero(&opcionMenu, MSJ_MENUPRINCIPAL, MSJ_ERROROPCION, 1, 6, REINTENTOS)){
    			switch(opcionMenu){
    				case 1:
    					if(!flagCarga){
    						puts("Ya se cargaron los datos previamente, no se pueden volver a cargar.\n\n\n");
    					}
    					else{
    						if(!ingresarArchivoCSV(nombreArchivoCSV, LARGODESCRIPCION, "Ingrese nombre archivo CSV\n", "error", REINTENTOS)){
        						devolucion = controller_loadFromText(nombreArchivoCSV,listaComputadoras);
        						//"datos_SP.csv"
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
    						else{
    							puts("Nombre de archivo no valido.\n\n\n");
    						}
    					}
    					break;
    				case 2:
    					if(flagCarga){
    						puts("No se cargaron los datos.\n\n\n");
    					}
    					else{
    						devolucion = controller_sortPassenger(listaComputadoras);
							if(devolucion==0){
								puts("Se ordeno correctamente.\n\n\n");
							}
    					}
    					break;
    				case 3:
    					if(flagCarga){
    						puts("No se cargaron los datos.\n\n\n");
    					}
    					else{
    						devolucion = controller_ListPassenger(listaComputadoras);
							if(devolucion==0){
								puts("Se imprimio la lista correctamente.\n\n\n");
							}
    					}
    					break;
					case 4:
    					if(flagCarga){
    						puts("No se cargaron los datos.\n\n\n");
    					}
    					else{
    						devolucion=ll_map(listaComputadoras, Passenger_compararPrecios);
    						if(devolucion==0){
    							flagCambios=0;
								puts("Se uso la funcion LL_MAP la lista correctamente.\n\n\n");
    						}
    					}
						break;
					case 5:
    					if(flagCambios){
    						puts("No se genero un lista previa.\n\n\n");
    					}
    					else{
    						devolucion=controller_saveAsText("mapeado.csv", listaComputadoras);
							if(devolucion==0){
								puts("Se creó el archivo nuevo la lista correctamente.\n\n\n");
							}
    					}
						break;
					case 6:
    						puts("Usted finalizó la operación.\n\n");
							puts("\n\nFinalizó el programa.\n");
						break;
    			}
        	}
        }while(opcionMenu!=6);
    }
    return 0;
}
