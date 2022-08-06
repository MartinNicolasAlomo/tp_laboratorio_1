#include "Controller.h"

static const char TXT_IDTIPO[2][LARGO_DESCRIPCION]={"DESKOP", "LAPTOP"};

int controller_loadFromText(char* path, LinkedList* pArraList){
	int retorno=-1;
	FILE* pArchivo=NULL;
	if(path!=NULL && pArraList!=NULL){
		pArchivo = fopen(path,"r");
		if(pArchivo!=NULL){
			if(!parser_PassengerFromText(pArchivo, pArraList)){
				retorno=0;
				fclose(pArchivo);
			}
			else{
				retorno=-4;
			}
		}
		else{
			retorno=-3;
		}
	}
	else if(pArraList==NULL){
		retorno=-2;
	}
    return retorno;
}


int controller_ListPassenger(LinkedList* pArrayList){
    int retorno=-1;
    int i;
    int largo;

    if(pArrayList!=NULL){
    	largo = ll_len(pArrayList);
    	if(largo>0){
    		printf("%5s %110s %15s %15s\n","ID","DESCRIPCION","PRECIO","ID DE TIPO");
			retorno=0;

    		for(i=0;i<largo;i++){
    			if(!Controller_imprimirElemento(pArrayList,i)){
    				retorno=0;
    			}
    		}
			puts("\n\n\n");
    	}
    	else{
    		retorno=-2;
    	}
    }
    return retorno;
}
//****************************************************************************************************************************************************


int Controller_imprimirElemento(LinkedList* pArrayList, int indice){
	int retorno=-1;
	eComputer auxiliar;
	eComputer* pComputadora=NULL;

	if(pArrayList!=NULL && indice>=0){
		pComputadora=(eComputer*)ll_get(pArrayList, indice);
		if(pComputadora!=NULL &&
			!Passenger_getId(pComputadora, &auxiliar.id) &&
			!Computer_getDescripcion(pComputadora, auxiliar.descripcion) &&
			!Product_getPrecio(pComputadora, &auxiliar.precio) &&
			!Computer_getTipo(pComputadora, &auxiliar.idTipo)){
			printf("%5d %110s %15.2f %15s\n",auxiliar.id,auxiliar.descripcion,auxiliar.precio,
															TXT_IDTIPO[auxiliar.idTipo-1]);
			retorno=0;
		}
		else if(pComputadora==NULL){
			puts("Falló la impresión, no se pudo obtener el pasajero.\n");
		}
		else{
			puts("Falló la impresión, no se pudo obtener los datos del pasajero correctamente.\n");
		}
	}
	else if(indice<0){
		puts("El indice es incorrecto.\n");
	}
	else{
		puts("El puntero a LinkedList es NULL.\n");
	}
	return retorno;
}
//****************************************************************************************************************************************************


int controller_sortPassenger(LinkedList* pArrayList){
	int retorno=-1;

	if(pArrayList!=NULL){
		if(!ll_sort(pArrayList, Passenger_compararPorIdTipo, 1)){
			puts("Se ordenó por ID exitosamente.\n\n");
			retorno=0;
		}
		else{
			puts("No se pudo ordenar por ID.\n\n\n");
		}
	}
    return retorno;
}




int controller_map(LinkedList* pArrayList){
	int retorno=-1;

	if(pArrayList!=NULL){
		if(!ll_map(pArrayList, Passenger_compararPrecios)){
			puts("Se ordenó por ID exitosamente.\n\n");
			retorno=0;
		}
		else{
			puts("No se pudo ordenar por ID.\n\n\n");
		}
	}
    return retorno;
}




int controller_saveAsText(char* path , LinkedList* pArrayList){
    int retorno=-1;
    FILE* pArchivo;
    eComputer* pComputadora=NULL;
	int i;
    int largo;
	int auxId;
	char auxDescripcion[LARGO_DESCRIPCION];
	float auxPrecio;
	int auxIdTipo;

    if(path!=NULL && pArrayList!=NULL){
		pArchivo = fopen(path,"w");
    	largo = ll_len(pArrayList);
		if(pArchivo!=NULL && largo>0){
			fprintf(pArchivo, "id,Descipcion,Precio,IdTipo\n");
			for(i=0;i<largo;i++){
				pComputadora=(eComputer*)ll_get(pArrayList, i);
				if(pComputadora!=NULL &&
					!Passenger_getId(pComputadora, &auxId) &&
					!Computer_getDescripcion(pComputadora, auxDescripcion) &&
					!Product_getPrecio(pComputadora, &auxPrecio) &&
					!Computer_getTipo(pComputadora, &auxIdTipo)){
					fprintf(pArchivo,"%d,%s,%.2f,%d\n",auxId,auxDescripcion,auxPrecio,auxIdTipo);
				}
				else if(pComputadora==NULL){
					puts("No se pudieron guardar los cambios, no se pudo obtener el pasajero.\n");
				}
				else{
					puts("No se pudieron guardar los cambios, no se pudieron obtener los datos pasajero.\n");
				}
			}
			fclose(pArchivo);
			retorno=0;
		}
		else if(pArchivo==NULL){
			retorno=-3;
		}
		else{
			retorno=-4;
		}
    }
	else if(pArrayList==NULL){
		retorno=-2;
	}

    return retorno;
}
