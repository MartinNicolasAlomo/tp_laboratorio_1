#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Input.h"
#include "parser.h"
#include "Validations.h"
#define REINTENTOS 3
#define LARGONOMBRE 50
#define LARGODESCRIPCION 20
#define LARGOID 8
#define LARGONUMEROTXT 11
#define LARGOCODIGO 20
#define MSJ_MENUINGRESO "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n3. Alta de pasajero.\n4. Modificar datos de pasajero.\n5. Baja de pasajero\n6. Listar pasajeros.\n7. Ordenar pasajeros.\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10. Salir\n\n"
#define MSJ_ERROROPCION "No es una opción válida, reinténtelo de nuevo.\n\n\n"
#define MSJ_MENUMODIFICAR "¿Qué desea modificar?\n1-Nombre\n2-Apellido\n3-Precio\n4-Codigo de vuelo\n5-Tipo de pasajero\n6-Estado de vuelo\n7-Finalizar cambios\n\n"
#define MSJ_MENUORDENAR "¿Cómo desea ordenarlos?\n  1- Por ID\n  2- Por Apellido\n  3- Por Precio\n  4- Por Codigo de Vuelo\n  5- Volver al Menú Principal\n\n"


typedef struct
{
	int id;
	char nombre[LARGONOMBRE];
	char apellido[LARGONOMBRE];
	float precio;
	char codigoVuelo[LARGOCODIGO];
	//int tipoPasajero;				//************************************************************
	//int estadoVuelo;				// Agregado		*************************************************************
	char tipoPasajero[LARGODESCRIPCION];
	char estadoVuelo[LARGODESCRIPCION];
}Passenger;


/// @brief
/// @return
Passenger* Passenger_new();			//USAR PARA LEER DESDE UN ARCHIVO BINARIO

/// @brief
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param codigoVueloStr
/// @param tipoPasajeroStr
/// @param estadoVueloStr
/// @return
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,
									char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr);

/// @brief
/// @param this
void Passenger_delete(Passenger* this);

/// @brief
/// @param this
/// @param id
/// @return
int Passenger_setId(Passenger* this,int id);

/// @brief
/// @param this
/// @param id
/// @return
int Passenger_getId(Passenger* this,int* id);

/// @brief
/// @param this
/// @param id
/// @return
int Passenger_setIdTXT(Passenger* this,char id[]);

/// @brief
/// @param this
/// @param id
/// @return
int Passenger_getIdTXT(Passenger* this,char id[]);


/// @brief
/// @param this
/// @param nombre
/// @return
int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);



int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_setPrecioTXT(Passenger* this,char precio[]);
int Passenger_getPrecioTXT(Passenger* this,char precio[]);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);


//*******************************************************************************************************************


int Passenger_inicializarVector(Passenger* vectorPunteros[],int limite);
int Passenger_buscarLibre(Passenger* vectorPunteros[],int limite);

int Passenger_eliminarIndiceEnVector(Passenger* vectorPunteros[],int limite,int indice);
int Passenger_eliminarPorId(Passenger* vectorPunteros[],int limite,int id);

int Passenger_agregarForzadaAlumno(Passenger* vectorPunteros[],int limite,int id,char nombre[],char apellido[],float precio,
																			char codigoVuelo[],int tipoPasajero,int estadoVuelo);
int Passenger_agregarForzadaAlumnoTXT(Passenger* vectorPunteros[],char id[],char nombre[],char apellido[],char precio[],
																			char codigoVuelo[],char tipoPasajero[],char estadoVuelo[]);

int Passenger_calcularPrecioPromedioVector(Passenger* vectorPunteros[],int limite,float* promedio);
int Passenger_calcularPrecioMaximaVector(Passenger* vectorPunteros[],int limite,int* indice);


int Passenger_guardarVectorEnArchivo(Passenger* vectorPunteros[],int limite,char pathArchivo[]);

int Passenger_cargarPasajero(Passenger* this);




/// @brief Da el criterio de ordenamiento segun el ID de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el ID del primer pasajero es mayor, respecto al segundo
///					0 (EXITO) - Si ambos IDs son iguales
///					-1 (ERROR) - Si el ID del segundo pasajero es mayor, respecto al primero
///					-2 (ERROR) - No se pudieron obtener los IDs de los pasajeros
///					-3 (ERROR) - Los parametros son NULL
int Passenger_comparaPorId(void* primerPasajero,void* segundoPasajero);

/// @brief Da el criterio de ordenamiento segun el precio de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el sueldo del primer pasajero es mayor, respecto al segundo
///					0 (EXITO) - Si ambos precios son iguales
///					-1 (ERROR) - Si el sueldo del segundo pasajero es mayor, respecto al primero
///					-2 (ERROR) - No se pudieron obtener los precios de los pasajeros
///					-3 (ERROR) - Los parametros son NULL
int Passenger_comparaPorPrecio(void* primerPasajero,void* segundoPasajero);

/// @brief Da el criterio de ordenamiento segun el apellido de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el apellido del primer pasajero viene antes que el del segundo
///					0 (EXITO) - Si ambos apellidos son iguales
///					-1 (ERROR) - Si el apellido del segundo pasajero viene antes que el del primero
///					-2 (ERROR) - No se pudieron obtener los apellidos de los pasajeros
///					-3 (ERROR) - Los parametros son NULL
int Passenger_comparaPorApellido(void* primerPasajero,void* segundoPasajero);



/// @brief Da el criterio de ordenamiento segun el código de vuelo de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el código de vuelo del primer pasajero viene antes que el del segundo
///					0 (EXITO) - Si ambos códigos de vuelo son iguales
///					-1 (ERROR) - Si el código de vuelo del segundo pasajero viene antes que el del primero
///					-2 (ERROR) - No se pudieron obtener los códigos de vuelo de los pasajeros
///					-3 (ERROR) - Los parametros son NULL
int Passenger_comparaPorCodigoVuelo(void* primerPasajero,void* segundoPasajero);




#endif /* PASSENGER_H_ */
