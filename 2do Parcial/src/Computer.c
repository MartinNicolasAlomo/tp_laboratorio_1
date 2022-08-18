#include "Computer.h"

/*
 * 	int id;
	char descripcion[LARGODESCRIPCION];
	float precio;
	int idTipo;
	*/


eComputer* Computer_new(){
	eComputer* auxiliar=NULL;
	auxiliar=(eComputer*) malloc(sizeof(eComputer));
	return auxiliar;
}

eComputer* Computer_newParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr){
	eComputer* this=NULL;
	this=Computer_new();
	if(this!=NULL && idStr!=NULL && descripcionStr!=NULL && precioStr!=NULL && idTipoStr!=NULL){
		if(Computer_setId_TXT(this, idStr)==-1 ||
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

int Passenger_setId(eComputer* this, int id){
	int retorno=-1;
	if(this!=NULL && id>0){
		this->id=id;
		retorno=0;
	}
	return retorno;
}


int Passenger_getId(eComputer* this, int* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int Computer_setId_TXT(eComputer* this, char* id){
	int retorno=-1;
	int auxId;
	if(this!=NULL && id!=NULL && esEntero(id, LARGO_NUMERO_TXT)){
		auxId=atoi(id);
		if(auxId>=0){
			this->id=auxId;
			retorno=0;
		}
	}
	else{
		puts("Recibi� mal los parametros en SET PRECIO (TEXTO).\n");
	}
	return retorno;
}

int Computer_getIdTXT(eComputer* this, char* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		sprintf(id, "%d", this->id);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************


int Computer_setDescripcion(eComputer* this, char* descripcion){
	int retorno=-1;
	if(this!=NULL && descripcion!=NULL && esDescripcion(descripcion, LARGO_DESCRIPCION)){
		strncpy(this->descripcion, descripcion, LARGO_DESCRIPCION);
		retorno=0;
	}
	return retorno;
}

int Computer_getDescripcion(eComputer* this, char* descripcion){
	int retorno=-1;
	if(this!=NULL && descripcion!=NULL){
		strncpy(descripcion, this->descripcion, LARGO_DESCRIPCION);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************

int Product_setPrecio(eComputer* this, float precio){
	int retorno=-1;
	if(this!=NULL && precio>0){
		this->precio=precio;
		retorno=0;
	}
	return retorno;
}

int Product_getPrecio(eComputer* this, float* precio){
	int retorno=-1;
	if(this!=NULL && precio>0){
		*precio=this->precio;
		retorno=0;
	}
	return retorno;
}

int Computer_setPrecioTXT(eComputer* this, char* precio){
	int retorno=-1;
	float auxPrecio;
	if(this!=NULL && precio>0 && esFlotante(precio, LARGO_NUMERO_TXT)){
		auxPrecio=atof(precio);
		if(auxPrecio>=0){
			this->precio=auxPrecio;
			retorno=0;
		}
	}
	else{
		puts("Recibi� mal los parametros en SET PRECIO (TEXTO).\n");
	}
	return retorno;
}

int Computer_getPrecioTXT(eComputer* this, char* precio){
	int retorno=-1;
	if(this!=NULL && precio!=NULL){
		sprintf(precio, "%.2f", this->precio);
		retorno=0;
	}
	return retorno;
}
//***********************************************************************************************

int Computer_setTipo(eComputer* this, int tipo){
	int retorno=-1;
	if(this!=NULL && tipo>0){
		this->idTipo=tipo;
		retorno=0;
	}
	return retorno;
}

int Computer_getTipo(eComputer* this, int* tipo){
	int retorno=-1;
	if(this!=NULL && tipo!=NULL){
		*tipo=this->idTipo;
		retorno=0;
	}
	return retorno;
}

int Computer_setTipo_TXT(eComputer* this, char* tipo){
	int retorno=-1;
	int auxIdTipo;
	if(this!=NULL && tipo!=NULL && esEntero(tipo, LARGO_NUMERO_TXT)){
		auxIdTipo=atoi(tipo);
		this->idTipo=auxIdTipo;
		retorno=0;
	}
	else{
		puts("Recibi� mal los parametros en SET PRECIO (TEXTO).\n");
	}
	return retorno;
}

int Computer_getTipo_TXT(eComputer* this,char* tipo){
	int retorno=-1;
	if(this!=NULL && tipo!=NULL){
		sprintf(tipo, "%d", this->idTipo);
		retorno=0;
	}
	return retorno;
}






int Passenger_compararPorIdTipo(void* primerElemento, void* segundoElemento){
	int retorno=-2;
	eComputer* elementoUno;
	eComputer* elementoDos;
	int idUno;
	int idDos;
	if(primerElemento!=NULL && segundoElemento!=NULL){
		elementoUno = (eComputer*)primerElemento;
		elementoDos = (eComputer*)segundoElemento;
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

int Passenger_compararPrecios(void* this){
	int retorno=-1;
	eComputer* pComputadora;
	float precio;
	int idTipo;
	if(this!=NULL){
		pComputadora = (eComputer*) this;
		if(pComputadora!=NULL && !Computer_getTipo(pComputadora, &idTipo) && !Product_getPrecio(pComputadora, &precio)){
			if(idTipo==1){
				precio=precio+(precio*10/100);
				Product_setPrecio(pComputadora, precio);
			}
			else if(idTipo==2){
				precio=precio+(precio*20/100);
				Product_setPrecio(pComputadora, precio);
			}
			retorno=0;
		}
		else{
			puts("No se pudo obtener los datos de los pasajeros.\n");
		}
	}
	return retorno;
}
