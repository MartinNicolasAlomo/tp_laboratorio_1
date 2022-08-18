#include "Passenger.h"

Passenger* Passenger_new(){
	Passenger* auxPuntero=NULL;
	auxPuntero=(Passenger*) malloc(sizeof(Passenger));
	return auxPuntero;
}

Passenger* Passenger_newParametros(int numeroPasajero, char* idStr, char* nombreStr, char* apellidoStr, char* precioStr,
									char* codigoVueloStr, char* tipoPasajeroStr,char* estadoVueloStr){
	Passenger* this=NULL;
	this=Passenger_new();
	if(this!=NULL && idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL &&
		codigoVueloStr!=NULL && tipoPasajeroStr!=NULL && estadoVueloStr!=NULL){

		if(Passenger_setIdTXT(this, idStr)==-1 ||
				Passenger_setNombre(this, nombreStr)==-1 ||
				Passenger_setApellido(this, apellidoStr)==-1 ||
				Product_setPrecioTXT(this, precioStr)==-1 ||
				Passenger_setCodigoVuelo(this, codigoVueloStr)==-1 ||
				Passenger_setTipoPasajeroTXT_NUM(this, tipoPasajeroStr)==-1 ||
				Passenger_setEstadoVueloTXT_NUM(this, estadoVueloStr)==-1) {
			printf("*No se pudieron setear los datos del pasajero n° %d de la lista.\n", numeroPasajero);
			Passenger_delete(this);
			this=NULL;
		}
	}
	else if(this==NULL){
		printf("*No se creó el pasajero n° %d de la lista, no hay espacio en memoria suficiente.\n", numeroPasajero);
	}
	else{
		printf("*Se recibieron mal los parametros del pasajero n° %d de la lista.\n", numeroPasajero);
	}
	return this;
}

void Passenger_delete(Passenger* this){
	if(this!=NULL){
		free(this);
	}
}
//***********************************************************************************************



/*int Passenger_setEverything(Passenger* this, Passenger auxiliar){
	int retorno=-1;
	if(this!=NULL &&
			!Passenger_setDescripcion(this, auxiliar.nombre) &&
			!Passenger_setApellido(this, auxiliar.apellido) &&
			!Product_setPrecio(this, auxiliar.precio) &&
			!Passenger_setCodigoVuelo(this, auxiliar.codigoVuelo) &&
			!Passenger_setTipoPasajeroNumerico(this, auxiliar.tipoPasajero) &&
			!Passenger_setEstadoVueloNumerico(this, auxiliar.estadoVuelo)){
		retorno=0;
	}
	return retorno;
}*/









int Passenger_setId(Passenger* this, int id){
	int retorno=-1;
	if(this!=NULL && id>0){
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int Passenger_getId(Passenger* this, int* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int Passenger_setIdTXT(Passenger* this, char* id){
	int retorno=-1;
	char mensajeFallo[LARGO_MENSAJE];
	if(this!=NULL && id!=NULL && esEntero(id, LARGO_NUMERO_TXT, mensajeFallo)){
		this->id=atoi(id);
		retorno=0;
	}
	else{
		puts("Recibió mal el numero de ID.\n");
	}
	return retorno;
}

int Passenger_getIdTXT(Passenger* this, char* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		sprintf(id, "%d", this->id);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setNombre(Passenger* this, char* nombre){
	int retorno=-1;
	char mensajeFallo[LARGO_MENSAJE];
	if(this!=NULL && nombre!=NULL && esNombre(nombre, LARGO_NOMBRE, mensajeFallo) && !pasarInicialesMayusculas(nombre, LARGO_NOMBRE)){
		strncpy(this->nombre, nombre, LARGO_NOMBRE);
		retorno=0;
	}
	return retorno;
}

int Passenger_getDescripcion(Passenger* this, char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre!=NULL){
		strncpy(nombre, this->nombre, LARGO_NOMBRE);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setApellido(Passenger* this, char* apellido){
	int retorno=-1;
	char mensajeFallo[LARGO_MENSAJE];
	if(this!=NULL && apellido!=NULL && esNombre(apellido, LARGO_NOMBRE, mensajeFallo) && !pasarInicialesMayusculas(apellido, LARGO_NOMBRE)){
		strncpy(this->apellido, apellido, LARGO_NOMBRE);
		retorno=0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this, char* apellido){
	int retorno=-1;
	if(this!=NULL && apellido!=NULL){
		strncpy(apellido, this->apellido, LARGO_NOMBRE);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Product_setPrecio(Passenger* this, float precio){
	int retorno=-1;
	if(this!=NULL && precio>0){
		this->precio=precio;
		retorno=0;
	}
	return retorno;
}

int Product_getPrecio(Passenger* this, float* precio){
	int retorno=-1;
	if(this!=NULL && precio>0){
		*precio=this->precio;
		retorno=0;
	}
	return retorno;
}

int Product_setPrecioTXT(Passenger* this, char* precio){
	int retorno=-1;
	char mensajeFallo[LARGO_MENSAJE];
	float auxPrecio;
	if(this!=NULL && precio>0 && esFlotante(precio, LARGO_NUMERO_TXT, mensajeFallo)){
		auxPrecio=atof(precio);
		if(auxPrecio>=0){
			this->precio=auxPrecio;
			retorno=0;
		}
	}
	else{
		puts("Recibió mal el precio.\n");
	}
	return retorno;
}

int Product_getPrecioTXT(Passenger* this, char* precio){
	int retorno=-1;
	if(this!=NULL && precio!=NULL){
		sprintf(precio, "%.2f", this->precio);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo){
	int retorno=-1;
	char mensajeFallo[LARGO_MENSAJE];
	if(this!=NULL && codigoVuelo!=NULL && esAlfanumerico(codigoVuelo, LARGO_CODIGO, mensajeFallo)){
		strupr(codigoVuelo);
		strncpy(this->codigoVuelo, codigoVuelo, LARGO_CODIGO);
		retorno=0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo){
	int retorno=-1;
	if(this!=NULL && codigoVuelo!=NULL){
		strncpy(codigoVuelo, this->codigoVuelo, LARGO_CODIGO);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setTipoPasajeroTXT_NUM(Passenger* this, char* tipoPasajero){
	int retorno=-1;
	char mensajeFallo[LARGO_MENSAJE];
	if(this!=NULL && tipoPasajero!=NULL && esDescripcion(tipoPasajero, LARGO_DESCRIPCION, mensajeFallo)){
		if(strncmp(tipoPasajero, "EconomyClass", LARGO_DESCRIPCION)==0){
			this->tipoPasajero=1;
			retorno=0;
		}
		else if(strncmp(tipoPasajero, "ExecutiveClass", LARGO_DESCRIPCION)==0){
			this->tipoPasajero=2;
			retorno=0;
		}
		else if(strncmp(tipoPasajero, "FirstClass", LARGO_DESCRIPCION)==0){
			this->tipoPasajero=3;
			retorno=0;
		}
	}
	else{
		puts("Recibió mal el Tipo Pasajero (TEXTO).\n");
	}
	return retorno;
}

int Passenger_getTipoPasajeroNUM_TXT(Passenger* this, char* tipoPasajero){
	int retorno=-1;
	char mensajeFallo[LARGO_MENSAJE];
	if(this!=NULL && tipoPasajero!=NULL && esDescripcion(tipoPasajero, LARGO_DESCRIPCION, mensajeFallo)){
		if(this->tipoPasajero==1){
			strncpy(tipoPasajero, "EconomyClass", LARGO_DESCRIPCION);
			retorno=0;
		}
		else if(this->tipoPasajero==2){
			strncpy(tipoPasajero, "ExecutiveClass", LARGO_DESCRIPCION);
			retorno=0;
		}
		else if(this->tipoPasajero==3){
			strncpy(tipoPasajero, "FirstClass", LARGO_DESCRIPCION);
			retorno=0;
		}
	}
	else{
		puts("Recibió mal tipos pasajeros (TEXTO).\n");
	}
	return retorno;
}

int Passenger_setTipoPasajeroNumerico(Passenger* this, int tipoPasajero){
	int retorno=-1;
	if(this!=NULL && tipoPasajero>0 && tipoPasajero<4){
		this->tipoPasajero=tipoPasajero;
		retorno=0;
	}
	return retorno;
}

int Passenger_getTipoPasajeroNumerico(Passenger* this, int* tipoPasajero){
	int retorno=-1;
	if(this!=NULL && tipoPasajero!=NULL){
		*tipoPasajero=this->tipoPasajero;
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Passenger_setEstadoVueloTXT_NUM(Passenger* this, char* estadoVuelo){
	int retorno=-1;
	char mensajeFallo[LARGO_MENSAJE];
	if(this!=NULL && estadoVuelo!=NULL && esDescripcion(estadoVuelo, LARGO_DESCRIPCION, mensajeFallo)){
		if(strncmp(estadoVuelo, "En Horario", LARGO_DESCRIPCION)==0){
			this->estadoVuelo=1;
			retorno=0;
		}
		else if(strncmp(estadoVuelo, "En Vuelo", LARGO_DESCRIPCION)==0){
			this->estadoVuelo=2;
			retorno=0;
		}
		else if(strncmp(estadoVuelo, "Demorado", LARGO_DESCRIPCION)==0){
			this->estadoVuelo=3;
			retorno=0;
		}
		else if(strncmp(estadoVuelo, "Aterrizado", LARGO_DESCRIPCION)==0){
			this->estadoVuelo=4;
			retorno=0;
		}
	}
	else{
		puts("Recibió mal los parametros en SET PRECIO (TEXTO).\n");
	}
	return retorno;
}

int Passenger_getEstadoVueloNUM_TXT(Passenger* this, char* estadoVuelo){
	int retorno=-1;
	char mensajeFallo[LARGO_MENSAJE];
	if(this!=NULL && estadoVuelo!=NULL && esNombre(estadoVuelo, LARGO_DESCRIPCION, mensajeFallo)){
		if(this->estadoVuelo==1){
			strncpy(estadoVuelo, "En Horario", LARGO_DESCRIPCION);
			retorno=0;
		}
		else if(this->estadoVuelo==2){
			strncpy(estadoVuelo, "En Vuelo", LARGO_DESCRIPCION);
			retorno=0;
		}
		else if(this->estadoVuelo==3){
			strncpy(estadoVuelo, "Demorado", LARGO_DESCRIPCION);
			retorno=0;
		}
		else if(this->estadoVuelo==4){
			strncpy(estadoVuelo, "Aterrizado", LARGO_DESCRIPCION);
			retorno=0;
		}
	}
	else{
		puts("Recibió mal el estado de vuelo (TEXTO).\n");
	}
	return retorno;
}

int Passenger_setEstadoVueloNumerico(Passenger* this, int estadoVuelo){
	int retorno=-1;
	if(this!=NULL && estadoVuelo>0 && estadoVuelo<5){
		this->estadoVuelo=estadoVuelo;
		retorno=0;
	}
	return retorno;
}

int Passenger_getEstadoVueloNumerico(Passenger* this, int* estadoVuelo){
	int retorno=-1;
	if(this!=NULL && estadoVuelo!=NULL){
		*estadoVuelo=this->estadoVuelo;
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************************************************


int Passenger_cargarPasajero(Passenger* this){
	int retorno=-1;
	Passenger auxPasajero;

	if(this!=NULL){
		if(!ingresarNombre(auxPasajero.nombre, LARGO_NOMBRE, "Ingrese el nombre:\n", "Error. No es un nombre correcto, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarNombre(auxPasajero.apellido, LARGO_NOMBRE, "Ingrese el apellido:\n", "Error. No es un apellido correcto, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarFlotante(&auxPasajero.precio, "Ingrese el precio del vuelo:\n", "Error. No es un precio correcto, reinténtelo de nuevo.\n\n\n", 0.1, 500000, REINTENTOS) &&
			!ingresarAlfanumerico(auxPasajero.codigoVuelo, LARGO_CODIGO, "Ingrese el código del pasaje:\n", "Error. No es un código válido, reinténtelo de nuevo.\n\n\n", REINTENTOS) &&
			!ingresarEntero(&auxPasajero.tipoPasajero, "Ingrese el tipo de pasajero: (1- EconomyClass, 2- ExecutiveClass o 3- FirstClass)\n", "Error. No es un tipo válido, reinténtelo de nuevo.\n\n\n", 1, 3, REINTENTOS) &&
			!ingresarEntero(&auxPasajero.estadoVuelo, "Indique el estado de su vuelo: (1- En Horario, 2- En Vuelo, 3- Demorado o 4- Aterrizado)\n", "Error. No es un estado válido, reinténtelo de nuevo.\n\n\n", 1, 4, REINTENTOS)){
			retorno=0;
			*this=auxPasajero;
		}
	}
	else{
		puts("El puntero a pasajero es NULL.\n\n\n");
	}
	return retorno;
}

int Passenger_compararPorId(void* primerPasajero, void* segundoPasajero){
	int retorno=-2;
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
			puts("No se pudo obtener los datos de los pasajeros.\n");
		}
	}
	return retorno;
}

int Passenger_compararPorPrecio(void* primerPasajero, void* segundoPasajero){
	int retorno=-2;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	float precioUno;
	float precioDos;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Product_getPrecio(pasajeroUno, &precioUno) && !Product_getPrecio(pasajeroDos, &precioDos)){
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
			puts("No se pudo obtener los datos de los pasajeros.\n");
		}
	}
	return retorno;
}

int Passenger_compararPorApellido(void* primerPasajero, void* segundoPasajero){
	int retorno=-2;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	char apellidoUno[LARGO_NOMBRE];
	char apellidoDos[LARGO_NOMBRE];
	int comparacion;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Passenger_getApellido(pasajeroUno, apellidoUno) && !Passenger_getApellido(pasajeroDos, apellidoDos)){
			comparacion = strncmp(apellidoUno, apellidoDos, LARGO_NOMBRE);
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
			puts("No se pudo obtener los datos de los pasajeros.\n");
		}
	}
	return retorno;
}

int Passenger_compararPorCodigoVuelo(void* primerPasajero, void* segundoPasajero){
	int retorno=-2;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	char codigoVueloUno[LARGO_NOMBRE];
	char codigoVueloDos[LARGO_NOMBRE];
	int comparacion;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Passenger_getCodigoVuelo(pasajeroUno, codigoVueloUno) && !Passenger_getCodigoVuelo(pasajeroDos, codigoVueloDos)){
			comparacion = strncmp(codigoVueloUno, codigoVueloDos, LARGO_NOMBRE);
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
			puts("No se pudo obtener los datos de los pasajeros.\n");
		}
	}
	return retorno;
}

int Passenger_compararPorNombre(void* primerPasajero, void* segundoPasajero){
	int retorno=-2;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	char nombreUno[LARGO_NOMBRE];
	char nombreDos[LARGO_NOMBRE];
	int comparacion;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Passenger_getDescripcion(pasajeroUno, nombreUno) && !Passenger_getDescripcion(pasajeroDos, nombreDos)){
			comparacion = strncmp(nombreUno, nombreDos, LARGO_NOMBRE);
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
			puts("No se pudo obtener los datos de los pasajeros.\n");
		}
	}
	return retorno;
}


int Passenger_compararPorTipoPasajero(void* primerPasajero, void* segundoPasajero){
	int retorno=-2;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	int tipoPasajeroUno;
	int tipoPasajeroDos;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Passenger_getTipoPasajeroNumerico(pasajeroUno, &tipoPasajeroUno) && !Passenger_getTipoPasajeroNumerico(pasajeroDos, &tipoPasajeroDos)){
			if(tipoPasajeroUno>tipoPasajeroDos){
				retorno=1;
			}
			else{
				if(tipoPasajeroUno<tipoPasajeroDos){
					retorno=-1;
				}
				else{
					retorno=0;
				}
			}
		}
		else{
			puts("No se pudo obtener los datos de los pasajeros.\n");
		}
	}
	return retorno;
}

int Passenger_compararPorEstadoVuelo(void* primerPasajero,void* segundoPasajero){
	int retorno=-2;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	int estadoVueloUno;
	int estadoVueloDos;
	if(primerPasajero!=NULL && segundoPasajero!=NULL){
		pasajeroUno = (Passenger*) primerPasajero;
		pasajeroDos = (Passenger*) segundoPasajero;
		if(!Passenger_getEstadoVueloNumerico(pasajeroUno, &estadoVueloUno) && !Passenger_getEstadoVueloNumerico(pasajeroDos, &estadoVueloDos)){
			if(estadoVueloUno>estadoVueloDos){
				retorno=1;
			}
			else{
				if(estadoVueloUno<estadoVueloDos){
					retorno=-1;
				}
				else{
					retorno=0;
				}
			}
		}
		else{
			puts("No se pudo obtener los datos de los pasajeros.\n");
		}
	}
	return retorno;
}
