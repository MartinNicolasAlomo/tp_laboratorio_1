#include "Passenger.h"
#define LARGOMsj 1000




Passenger* Passenger_new(){
	Passenger* auxPuntero=NULL;
	auxPuntero=(Passenger*) malloc(sizeof(Passenger));
	return auxPuntero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr){
	Passenger* this=NULL;
	this=Passenger_new();
	if(this!=NULL && idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL &&
		codigoVueloStr!=NULL && tipoPasajeroStr!=NULL && estadoVueloStr!=NULL){
		if(Passenger_setIdTXT(this, idStr)==-1 ||
			Passenger_setNombre(this, nombreStr)==-1 ||
			Passenger_setApellido(this, apellidoStr)==-1 ||
			Passenger_setPrecioTXT(this, precioStr)==-1 ||
			Passenger_setCodigoVuelo(this, codigoVueloStr)==-1 ||
			Passenger_setTipoPasajero(this, tipoPasajeroStr)==-1 ||
			Passenger_setEstadoVuelo(this, estadoVueloStr)==-1){
			printf("el que se elimino fue: %d  -  %s, %s",this->id,this->nombre,this->apellido);
			puts("Fallaron los Setters\n");
			Passenger_delete(this);
			this=NULL;
		}
	}
	else if(idStr==NULL || nombreStr==NULL || apellidoStr==NULL || precioStr==NULL || codigoVueloStr==NULL || tipoPasajeroStr==NULL || estadoVueloStr==NULL){
		puts("Parametros en Passanger_newParametros estan mal.\n");
	}
	else if(this==NULL){
		puts("No se pudo crear nuevo pasajero con Passanger_new.\n");
	}
	return this;
}

void Passenger_delete(Passenger* this){
	if(this!=NULL){
		free(this);
	}
}
//***********************************************************************************************


int Passenger_setId(Passenger* this,int id){
	int retorno=-1;
	if(this!=NULL && id>0){
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int Passenger_setIdTXT(Passenger* this,char id[]){
	int retorno=-1;
	if(this!=NULL && id!=NULL && esEntero(id, LARGONUMEROTXT)){
		this->id=atoi(id);
		retorno=0;
	}
	else{
		retorno=-1;
		puts("Mal parametros SET ID  TEXTO\n");
	}
	return retorno;
}

int Passenger_getIdTXT(Passenger* this,char id[]){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		sprintf(id,"%d",this->id);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre!=NULL && esNombre(nombre, LARGONOMBRE)){
		strncpy(this->nombre, nombre, LARGONOMBRE);
		retorno=0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre!=NULL){
		strncpy(nombre, this->nombre, LARGONOMBRE);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno=-1;
	if(this!=NULL && apellido!=NULL && esNombre(apellido, LARGONOMBRE)){
		strncpy(this->apellido, apellido, LARGONOMBRE);
		retorno=0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno=-1;
	if(this!=NULL && apellido!=NULL){
		strncpy(apellido, this->apellido, LARGONOMBRE);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setPrecio(Passenger* this,float precio){
	int retorno=-1;
	if(this!=NULL && precio>0){
		this->precio=precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno=-1;
	if(this!=NULL && precio>0){
		*precio=this->precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_setPrecioTXT(Passenger* this,char precio[]){
	int retorno=-1;
	float auxPrecio;
	if(this!=NULL && precio>0 && esFlotante(precio, LARGONUMEROTXT)){
		auxPrecio=atof(precio);
		if(auxPrecio>=0){
			this->precio=auxPrecio;
			retorno=0;
		}
	}
	else{
		retorno=-1;
		puts("Mal parametros SET PRECIO  TEXTO\n");
	}
	return retorno;
}

int Passenger_getPrecioTXT(Passenger* this,char precio[]){
	int retorno=-1;
	if(this!=NULL && precio!=NULL){
		sprintf(precio,"%.2f",this->precio);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno=-1;
	if(this!=NULL && codigoVuelo!=NULL && esAlfanumerico(codigoVuelo, LARGOCODIGO)){
		strncpy(this->codigoVuelo, codigoVuelo, LARGOCODIGO);
		retorno=0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno=-1;
	if(this!=NULL && codigoVuelo!=NULL){
		strncpy(codigoVuelo, this->codigoVuelo, LARGOCODIGO);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno=-1;
	if(this!=NULL && tipoPasajero!=NULL && esNombre(tipoPasajero, LARGODESCRIPCION)){
		strncpy(this->tipoPasajero, tipoPasajero, LARGODESCRIPCION);
		retorno=0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno=-1;
	if(this!=NULL && tipoPasajero!=NULL){
		strncpy(tipoPasajero, this->tipoPasajero, LARGODESCRIPCION);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo){
	int retorno=-1;
	if(this!=NULL && estadoVuelo!=NULL && esNombre(estadoVuelo, LARGODESCRIPCION)){
		strncpy(this->estadoVuelo, estadoVuelo, LARGODESCRIPCION);
		retorno=0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo){
	int retorno=-1;
	if(this!=NULL && estadoVuelo!=NULL){
		strncpy(estadoVuelo, this->estadoVuelo, LARGODESCRIPCION);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************************************************


int Passenger_cargarPasajero(Passenger* this){
	int retorno=-1;
	Passenger auxPasajero;

	/*
	 * Ingrese el tipo de pasajero: (1 EconomyClass, 2 ExecutiveClass o 3 FirstClass)\n
	 * Indique el estado de su vuelo: (1 En Horario, 2 En Vuelo, 3 Demorado o 4 Aterrizado)\n
	 *
	 * 			CORREGIR		TIPOPSADAJERO  Y  ESTADOVUELO 	A TIPO INT
	 * */


	if(!ingresarNombre(auxPasajero.nombre, LARGONOMBRE, "Ingrese el nombre:\n", "Error. No es un nombre correcto, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
		!ingresarNombre(auxPasajero.apellido, LARGONOMBRE, "Ingrese el apellido:\n", "Error. No es un apellido correcto, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
		!ingresarFlotante(&auxPasajero.precio, "Ingrese el precio del vuelo:\n", "Error. No es un precio correcto, reinténtelo de nuevo.\n\n\n", 0.1, 500000, REINTENTOS) &&
		!ingresarAlfanumerico(auxPasajero.codigoVuelo, LARGOCODIGO, "Ingrese el código del pasaje:\n", "Error. No es un código válido, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
		!ingresarDescripcion(auxPasajero.tipoPasajero, LARGODESCRIPCION, "Ingrese el tipo de pasajero: (EconomyClass, ExecutiveClass o FirstClass)\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
		!ingresarDescripcion(auxPasajero.estadoVuelo, LARGODESCRIPCION, "Indique el estado de su vuelo: (En Horario, En Vuelo, Demorado o Aterrizado)\n", "Error. No es un estado válido, reinténtelo de nuevo.\n\n\n", REINTENTOS)){
		retorno=0;
		*this=auxPasajero;
	}
	return retorno;
}



int Passenger_comparaPorId(void* primerPasajero,void* segundoPasajero){
	int retorno=-3;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	int idUno;
	int idDos;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Passenger_getId(pasajeroUno, &idUno) && !Passenger_getId(pasajeroDos, &idDos)){
			if(idUno>idDos){
				retorno=1;
			}
			else{
				if(idUno<idDos){
					retorno=-1;
				}
				else{
					retorno=0;
				}
			}
		}
		else{
			retorno=-2;
		}
	}
	return retorno;
}

int Passenger_comparaPorPrecio(void* primerPasajero,void* segundoPasajero){
	int retorno=-3;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	float precioUno;
	float precioDos;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Passenger_getPrecio(pasajeroUno, &precioUno) && !Passenger_getPrecio(pasajeroDos, &precioDos)){
			if(precioUno>precioDos){
				retorno=1;
			}
			else{
				if(precioUno<precioDos){
					retorno=-1;
				}
				else{
					retorno=0;
				}
			}
		}
		else{
			retorno=-2;
		}
	}
	return retorno;
}

int Passenger_comparaPorApellido(void* primerPasajero,void* segundoPasajero){
	int retorno=-3;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	char apellidoUno[LARGONOMBRE];
	char apellidoDos[LARGONOMBRE];
	int comparacion;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Passenger_getApellido(pasajeroUno, apellidoUno) && !Passenger_getApellido(pasajeroDos, apellidoDos)){
			comparacion = strncmp(apellidoUno,apellidoDos,LARGONOMBRE);
			if(comparacion>0){
				retorno=1;
			}
			else{
				if(comparacion<0){
					retorno=-1;
				}
				else{
					retorno=0;
				}
			}
		}
		else{
			retorno=-2;
		}
	}
	return retorno;
}

int Passenger_comparaPorCodigoVuelo(void* primerPasajero,void* segundoPasajero){
	int retorno=-3;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	char codigoVueloUno[LARGONOMBRE];
	char codigoVueloDos[LARGONOMBRE];
	int comparacion;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Passenger_getCodigoVuelo(pasajeroUno, codigoVueloUno) && !Passenger_getCodigoVuelo(pasajeroDos, codigoVueloDos)){
			comparacion = strncmp(codigoVueloUno,codigoVueloDos,LARGONOMBRE);
			if(comparacion>0){
				retorno=1;
			}
			else{
				if(comparacion<0){
					retorno=-1;
				}
				else{
					retorno=0;
				}
			}
		}
		else{
			retorno=-2;
		}
	}
	return retorno;
}
