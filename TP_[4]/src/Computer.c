#include "Computer.h"

/*
 * 	int id;
	char descripcion[LARGODESCRIPCION];
	float precio;
	int idTipo;
	*/


eComputer* Computer_new(){
	eComputer* auxPuntero=NULL;
	auxPuntero=(eComputer*) malloc(sizeof(eComputer));
	return auxPuntero;
}

eComputer* Computer_newParametros(char* idStr,char* descripcionStr,char* precioStr,char* idTipoStr){
	eComputer* this=NULL;
	this=Computer_new();
	if(this!=NULL && idStr!=NULL && descripcionStr!=NULL && precioStr!=NULL && idTipoStr!=NULL){
		if(Computer_setIdTXT(this, idStr)==-1 ||
			Computer_setDescripcion(this, descripcionStr)==-1 ||
			Computer_setPrecioTXT(this, precioStr)==-1 ||
			Computer_setTipo_TXT(this, idTipoStr)==-1){
			puts("Fallaron los Setters.\n");
			Passenger_delete(this);
			this=NULL;
		}
	}
	else if(idStr==NULL || descripcionStr==NULL || precioStr==NULL || idTipoStr==NULL){
		puts("Parametros en Passanger_newParametros estan mal.\n");
	}
	else if(this==NULL){
		puts("No se pudo crear nuevo pasajero con Passanger_new.\n");
	}
	return this;
}

void Passenger_delete(eComputer* this){
	if(this!=NULL){
		free(this);
	}
}
//***********************************************************************************************

int Passenger_setId(eComputer* this,int id){
	int retorno=-1;
	if(this!=NULL && id>0){
		this->id=id;
		retorno=0;
	}
	return retorno;
}


int Passenger_getId(eComputer* this,int* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int Computer_setIdTXT(eComputer* this,char id[]){
	int retorno=-1;
	int auxId;
	if(this!=NULL && id!=NULL && esEntero(id, LARGONUMEROTXT)){
		auxId=atoi(id);
		if(auxId>=0){
			this->id=auxId;
			retorno=0;
		}
	}
	else{
		puts("Recibió mal los parametros en SET PRECIO (TEXTO).\n");
	}
	return retorno;
}

int Computer_getIdTXT(eComputer* this,char id[]){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		sprintf(id,"%d",this->id);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Computer_setDescripcion(eComputer* this,char* descripcion){
	int retorno=-1;
	if(this!=NULL && descripcion!=NULL && esDescripcion(descripcion, LARGODESCRIPCION)){
		strncpy(this->descripcion, descripcion, LARGODESCRIPCION);
		retorno=0;
	}
	return retorno;
}

int Computer_getDescripcion(eComputer* this,char* descripcion){
	int retorno=-1;
	if(this!=NULL && descripcion!=NULL){
		strncpy(descripcion, this->descripcion, LARGODESCRIPCION);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************

int Passenger_setPrecio(eComputer* this,float precio){
	int retorno=-1;
	if(this!=NULL && precio>0){
		this->precio=precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_getPrecio(eComputer* this,float* precio){
	int retorno=-1;
	if(this!=NULL && precio>0){
		*precio=this->precio;
		retorno=0;
	}
	return retorno;
}

int Computer_setPrecioTXT(eComputer* this,char precio[]){
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
		puts("Recibió mal los parametros en SET PRECIO (TEXTO).\n");
	}
	return retorno;
}

int Computer_getPrecioTXT(eComputer* this,char precio[]){
	int retorno=-1;
	if(this!=NULL && precio!=NULL){
		sprintf(precio,"%.2f",this->precio);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************

int Computer_setTipo(eComputer* this,int tipo){
	int retorno=-1;
	if(this!=NULL && tipo>0){
		this->idTipo=tipo;
		retorno=0;
	}
	return retorno;
}

int Computer_getTipo(eComputer* this,int* tipo){
	int retorno=-1;
	if(this!=NULL && tipo!=NULL){
		*tipo=this->idTipo;
		retorno=0;
	}
	return retorno;
}

int Computer_setTipo_TXT(eComputer* this,char tipo[]){
	int retorno=-1;
	int auxIdTipo;
	if(this!=NULL && tipo!=NULL && esEntero(tipo, LARGONUMEROTXT)){
		auxIdTipo=atoi(tipo);
		this->idTipo=auxIdTipo;
		retorno=0;
	}
	else{
		puts("Recibió mal los parametros en SET PRECIO (TEXTO).\n");
	}
	return retorno;
}

int Computer_getTipo_TXT(eComputer* this,char tipo[]){
	int retorno=-1;
	if(this!=NULL && tipo!=NULL){
		sprintf(tipo,"%d",this->idTipo);
		retorno=0;
	}
	return retorno;
}






int Passenger_compararPorIdTipo(void* elemento1,void* elemento2){
	int retorno=-2;
	eComputer* elementoUno;
	eComputer* elementoDos;
	int idUno;
	int idDos;
	if(elemento1!=NULL && elemento2!=NULL){
		elementoUno = (eComputer*) elemento1;
		elementoDos = (eComputer*) elemento2;
		if(!Computer_getTipo(elementoUno, &idUno) && !Computer_getTipo(elementoDos, &idDos)){
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

int Passenger_compararPrecios(void* elemento1){
	int retorno=-1;
	eComputer* elementoUno;
	float precio;
	int idTipo;
	if(elemento1!=NULL){
		elementoUno = (eComputer*) elemento1;
		if(elementoUno!=NULL && !Computer_getTipo(elementoUno, &idTipo) && !Passenger_getPrecio(elementoUno, &precio)){
			if(idTipo==1){
				precio = precio+(precio*10/100);
				Passenger_setPrecio(elementoUno, precio);
			}
			else if(idTipo==2){
				precio = precio+(precio*20/100);
				Passenger_setPrecio(elementoUno, precio);
			}
			retorno=0;
		}
		else{
			puts("No se pudo obtener los datos de los pasajeros.\n");
		}
	}
	return retorno;
}
