#include "Passenger.h"
#define LARGOMsj 1000




Passenger* Passenger_new(){
	Passenger* auxPuntero=NULL;
	auxPuntero=(Passenger*) malloc(sizeof(Passenger));
	return auxPuntero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,
									char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr){
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
			puts("Fallaron los Setters\n");
			Passenger_delete(this);
			this=NULL;
		}
	}
	else if(idStr==NULL || nombreStr==NULL || apellidoStr==NULL || precioStr==NULL ||
			codigoVueloStr==NULL || tipoPasajeroStr==NULL || estadoVueloStr==NULL){
		puts("Parametros en Passanger_newParametros estan mal.\n");
	}
	else if(this==NULL){
		puts("No se pudo crear nuevo pasajero con Passanger_new.\n");
	}
	return this;
}


/*if(!Passenger_setIdTXT(this, idStr) &&
			!Passenger_setNombre(this, nombreStr) &&
			!Passenger_setApellido(this, apellidoStr) &&
			!Passenger_setPrecioTXT(this, precioStr) &&
			!Passenger_setCodigoVuelo(this, codigoVueloStr) &&
			!Passenger_setTipoPasajero(this, tipoPasajeroStr) &&
			!Passenger_setEstadoVuelo(this, estadoVueloStr)){
			puts("Se pudieron usar BIEN los SEtterSS\n");
		}*/


/*		if(Passenger_setIdTXT(this, idStr)==-1 ||
			Passenger_setNombre(this, nombreStr)==-1 ||
			Passenger_setApellido(this, apellidoStr)==-1 ||
			Passenger_setPrecioTXT(this, precioStr)==-1 ||
			Passenger_setCodigoVuelo(this, codigoVueloStr)==-1 ||
			Passenger_setTipoPasajeroTXT(this, tipoPasajeroStr)==-1 ||
			Passenger_setEstadoVueloTXT(this, estadoVueloStr)==-1){
			puts("Fallaron los 		SETTERS\n");
			Passenger_delete(this);
			this=NULL;
		}
*/


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



int Passenger_inicializarVector(Passenger* vectorPunteros[],int limite){
	int retorno=-1;
	int i;
	if(vectorPunteros!=NULL && limite>0){
		retorno=0;
		for(i=0;i<limite;i++){
			vectorPunteros[i]=NULL;
		}
	}
	return retorno;
}


int Passenger_buscarLibre(Passenger* vectorPunteros[],int limite){
	int retorno=-1;										// PARAMETROS ESTAN MAL
	int i;
	if(vectorPunteros!=NULL && limite>0){
		retorno=-2;										//	PARAMETROS CORRECTOS PERO NO SE PUDO ENCONTRAR UN LUGAR VACIO
		for(i=0;i<limite;i++){
			if(vectorPunteros[i]==NULL){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}



/*
 * Ingrese el tipo de pasajero: (1 EconomyClass, 2 ExecutiveClass o 3 FirstClass)\n
 * Indique el estado de su vuelo: (1 En Horario, 2 En Vuelo, 3 Demorado o 4 Aterrizado)\n
 *
 * 			CORREGIR		TIPOPSADAJERO  Y  ESTADOVUELO
 * */
int Passenger_cargarPasajero(Passenger* this){
	int retorno=-1;
	Passenger auxPasajero;
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


/*int Passenger_modificarPasajero(Passenger vector[],int limite,int id){
	int retorno=-1;
	Passenger auxPasajero;
	int opcion;
	int confirmar;
	char mensajeOpcionModificar[LARGOMENSAJE];
	char mensajeOpcionError[LARGOMENSAJE];


	strncpy(mensajeOpcionError,"No es una opción válida, reinténtelo de nuevo.\n\n\n",sizeof(mensajeOpcionError));


	if(vector != NULL && id>=0 && mensajeOpcionModificar != NULL && mensajeOpcionError != NULL){

		// FIJARTE SI USAR	SETTERS O GETTERS *******************
		auxPasajero.id=vector[id].id;
		strncpy(auxPasajero.nombre,vector[id].nombre,sizeof(auxPasajero.nombre));
		strncpy(auxPasajero.apellido,vector[id].apellido,sizeof(auxPasajero.apellido));
		auxPasajero.precio=vector[id].precio;
		strncpy(auxPasajero.codigoVuelo,vector[id].codigoVuelo,sizeof(auxPasajero.codigoVuelo));
		auxPasajero.tipoPasajero=vector[id].tipoPasajero;
		auxPasajero.estadoVuelo=vector[id].estadoVuelo;


		if(!pasaj_imprimirElemento(&vector[id])){					//	CREAR FUNCION ESTA FALTA
			do{
				if(!ingresarEntero(&opcion, mensajeOpcionModificar, mensajeOpcionError, 1, 7, REINTENTOS)){
					switch(opcion){
					case 1:
						if(!ingresarNombre(auxPasajero.nombre, LARGONOMBRE, "Nuevo nombre:\n", "Error\n\n\n", REINTENTOS)){
							puts("Se modificó el nombre exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del nombre.\n\n\n");
						}
						break;
					case 2:
						if(!ingresarNombre(auxPasajero.apellido, LARGONOMBRE, "Nuevo apellido:\n", "Error\n\n\n", REINTENTOS)){
							puts("Se modificó el apellido exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del apellido.\n\n\n");
						}
						break;
					case 3:
						if(!ingresarFlotante(&auxPasajero.precio, "Nuevo precio:\n", "Error\n\n\n", 0.1, 500000, REINTENTOS)){
							puts("Se modificó el precio exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del precio.\n\n\n");
						}
						break;
					case 4:
						if(!ingresarAlfanumerico(auxPasajero.codigoVuelo, LARGOCODIGO, "Nuevo codigo de vuelo:\n", "Error\n\n\n", REINTENTOS)){
							puts("Se modificó el codigo de vuelo exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del codigo de vuelo.\n\n\n");
						}
						break;
					case 5:
						if(!ingresarEntero(&auxPasajero.tipoPasajero, "Nuevo tipo de pasajero: (1 EconomyClass, 2 ExecutiveClass o 3 FirstClass)\n", "Error\n\n\n", 1, 3, REINTENTOS)){
							puts("Se modificó el tipo de pasajero exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del tipo de pasajero.\n\n\n");
						}
						break;
					case 6:
						if(!ingresarEntero(&auxPasajero.estadoVuelo, "Nuevo estado de vuelo: (1 En Horario, 2 En Vuelo, 3 Demorado o 4 Aterrizado)\n", "Error\n\n\n", 1, 4, REINTENTOS)){
							puts("Se modificó el estado de vuelo exitosamente.\n\n");
						}
						else{
							puts("Falló la modificación del estado de vuelo.\n\n\n");
						}
						break;
					case 7:
						if(!ingresarEntero(&confirmar, "¿Está seguro/a de quiere realizar las modificaciones? (1- Si / 2- No)\n\n", "No es una opción válida, reinténtelo de nuevo.\n\n\n", 1, 2, REINTENTOS)){
							if(confirmar==1){
								retorno=0;
								vector[id]=auxPasajero;
							}
							else if(confirmar==2){
								puts("No se guardaron los cambios\n\n");
							}
						}
						else{
							puts("No se pudo confirmar.\n\n\n");
						}
						break;
					}
				}
				else{
					puts("No se pudo ingresar una opción.\n\n\n");
				}
			}while(opcion!=7);
		}
	}
	return retorno;
}
*/




int Passenger_eliminarIndiceEnVector(Passenger* vectorPunteros[],int limite,int indice){
	int retorno=-1;
	if(vectorPunteros!=NULL && indice>=0 && indice<limite && vectorPunteros[indice]!=NULL){
		retorno=0;
		Passenger_delete(vectorPunteros[indice]);
		vectorPunteros[indice]=NULL;
	}
	return retorno;
}


int Passenger_eliminarPorId(Passenger* vectorPunteros[],int limite,int id){
	int retorno=-1;
	int indiceABuscar;
	if(vectorPunteros!=NULL && limite>0 && id>=0){
		//indiceABuscar=Controller_buscarPorId(vectorPunteros, id);
		if(indiceABuscar>=0){
			if(!Passenger_eliminarIndiceEnVector(vectorPunteros, limite, indiceABuscar)){
				retorno=0;
			}
		}
	}
	return retorno;
}


int Passenger_calcularPrecioPromedioVector(Passenger* vectorPunteros[],int limite,float* promedio){
	int retorno = -1;
	int i;
	int cantidadPasajeros=0;
	float acumuladorPrecios=0;
	if(vectorPunteros!=NULL && limite>0 && promedio!=NULL){
		retorno=0;
		for(i=0;i<limite;i++){
			if(vectorPunteros[i]!=NULL){
				cantidadPasajeros++;
				acumuladorPrecios = acumuladorPrecios+vectorPunteros[i]->precio;
			}
		}
		*promedio=acumuladorPrecios/cantidadPasajeros;
	}
	return retorno;
}


int Passenger_calcularPrecioMaximaVector(Passenger* vectorPunteros[],int limite,int* indice){
	int retorno = -1;
	int i;
	int indiceMaximo;
	float precioMaximo;
	int flagMax=0;

	if(vectorPunteros!=NULL && limite>0 && indice!=NULL){
		retorno=0;
		for(i=0;i<limite;i++){
			if(vectorPunteros[i]!=NULL){
				if(!flagMax){
					indiceMaximo=i;
					precioMaximo=vectorPunteros[i]->precio;
					flagMax=1;
				}
				else if(vectorPunteros[i]->precio > precioMaximo){
					indiceMaximo=i;
					precioMaximo=vectorPunteros[i]->precio;
				}
			}
		}
		*indice=indiceMaximo;
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
				if(comparacion>0){
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
				if(comparacion>0){
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

