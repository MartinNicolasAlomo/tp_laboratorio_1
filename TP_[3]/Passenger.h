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
#define MSJ_MENUPRINCIPAL "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n3. Alta de pasajero.\n4. Modificar datos de pasajero.\n5. Baja de pasajero\n6. Listar pasajeros.\n7. Ordenar pasajeros.\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10. Salir\n\n"
#define MSJ_ERROROPCION "No es una opción válida, reinténtelo de nuevo.\n\n\n"
#define MSJ_MENUMODIFICAR "¿Qué desea modificar?\n  1-Nombre\n  2-Apellido\n  3-Precio\n  4-Codigo de vuelo\n  5-Tipo de pasajero\n  6-Estado de vuelo\n  7-Finalizar cambios\n\n"
#define MSJ_MENUORDENAR "¿Cómo desea ordenarlos?\n  1- Por ID\n  2- Por Apellido\n  3- Por Precio\n  4- Por Codigo de Vuelo\n  5- Volver al Menú Principal\n\n"


typedef struct
{
	int id;
	char nombre[LARGONOMBRE];
	char apellido[LARGONOMBRE];
	float precio;
	char codigoVuelo[LARGOCODIGO];
	//int tipoPasajero;
	//int estadoVuelo;
	char tipoPasajero[LARGONOMBRE];
	char estadoVuelo[LARGONOMBRE];
}Passenger;


//***********************************************************************************************


/// @brief - Pide memoria para un nuevo empleado
/// @return - Retorna un puntero con espacio de memoria de tipo Passenger
Passenger* Passenger_new();

/// @brief - Pide memoria para un pasajero nuevo y setea los campos en el espacio de memoria requerido
/// @param idStr - ID que va a setear
/// @param nombreStr - Nombre que va a setear
/// @param apellidoStr - Apellido que va a setear
/// @param precioStr - Precio que va a setear
/// @param codigoVueloStr - Codigo de vuelo que va a setear
/// @param tipoPasajeroStr - Tipo de pasajero que va a setear
/// @param estadoVueloStr - Estado de vuelo que va a setear
/// @return - Retorna el puntero con espacio de memoria de tipo Passenger con los campos ya seteados si salió bien, o puntero a NULL si hubo un error
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr);

/// @brief - Libera espacio de memoria de un pasajero
/// @param this - Puntero a pasajero
void Passenger_delete(Passenger* this);
//***********************************************************************************************


/// @brief - Carga el ID en el campo del pasajero
/// @param this - Puntero a pasajero
/// @param id - ID a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el ID en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el ID no es valido
int Passenger_setId(Passenger* this,int id);


/// @brief - Obtiene el ID del pasajero
/// @param this - Puntero a pasajero
/// @param id - Puntero al espacio donde se va a guardar el ID obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el ID del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al ID es NULL
int Passenger_getId(Passenger* this,int* id);

/// @brief - Carga el ID en el campo del pasajero (tratado como texto) y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param id - Puntero al ID que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el ID en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al ID es NULL
int Passenger_setIdTXT(Passenger* this,char id[]);

/// @brief - Obtiene el ID del pasajero (tratado como texto)
/// @param this - Puntero a pasajero
/// @param id - Puntero al espacio donde se va a guardar el ID obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el ID del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al ID es NULL
int Passenger_getIdTXT(Passenger* this,char id[]);
//***********************************************************************************************


/// @brief - Carga el nombre en el campo del pasajero y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param nombre - Puntero al nombre que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el nombre en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al nombre es NULL
int Passenger_setNombre(Passenger* this,char* nombre);

/// @brief - Obtiene el nombre del empleado
/// @param this - Puntero a empleado
/// @param nombre - Puntero al espacio donde se va a guardar el nombre obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el nombre del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al nombre es NULL
int Passenger_getNombre(Passenger* this,char* nombre);
//***********************************************************************************************


/// @brief - Carga el apellido en el campo del pasajero y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param apellido - Puntero al apellido que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el apellido en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al apellido es NULL
int Passenger_setApellido(Passenger* this,char* apellido);

/// @brief - Obtiene el apellido del empleado
/// @param this - Puntero a empleado
/// @param apellido - Puntero al espacio donde se va a guardar el apellido obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el apellido del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al apellido es NULL
int Passenger_getApellido(Passenger* this,char* apellido);
//***********************************************************************************************


/// @brief - Carga el precio en el campo del pasajero
/// @param this - Puntero a pasajero
/// @param precio - Precio a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el precio en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el precio no es valido
int Passenger_setPrecio(Passenger* this,float precio);

/// @brief * Obtiene el precio del pasajero
/// @param this - Puntero a pasajero
/// @param precio - Puntero al espacio donde se va a guardar el precio obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el precio del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al precio es NULL
int Passenger_getPrecio(Passenger* this,float* precio);


/// @brief - Carga el precio en el campo del pasajero (tratado como texto) y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param precio - Puntero al precio que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el precio en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al precio es NULL
int Passenger_setPrecioTXT(Passenger* this,char precio[]);

/// @brief - Obtiene el precio del pasajero (tratado como texto)
/// @param this - Puntero a pasajero
/// @param precio - Puntero al espacio donde se va a guardar el precio obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el precio del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al precio es NULL
int Passenger_getPrecioTXT(Passenger* this,char precio[]);
//***********************************************************************************************


/// @brief - Carga el código de vuelo en el campo del pasajero y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param codigoVuelo - Puntero al código de vuelo que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el código de vuelo en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al código de vuelo es NULL
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief - Obtiene el código de vuelo del empleado
/// @param this - Puntero a empleado
/// @param codigoVuelo - Puntero al espacio donde se va a guardar el código de vuelo obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el código de vuelo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al código de vuelo es NULL
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
//***********************************************************************************************


/// @brief - Carga el tipo de pasajero en el campo del pasajero y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param tipoPasajero - Puntero al tipo de pasajero que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el tipo de pasajero en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al tipo de pasajero es NULL
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

/// @brief - Obtiene el tipo de pasajero del empleado
/// @param this - Puntero a empleado
/// @param tipoPasajero - Puntero al espacio donde se va a guardar el tipo de pasajero obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el tipo de pasajero del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al tipo de pasajero es NULL
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);
//***********************************************************************************************


/// @brief - Carga el estado de vuelo en el campo del pasajero y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param estadoVuelo - Puntero al estado de vuelo que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el estado de vuelo en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al estado de vuelo es NULL
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);

/// @brief - Obtiene el estado de vuelo del empleado
/// @param this - Puntero a empleado
/// @param estadoVuelo - Puntero al espacio donde se va a guardar el estado de vuelo obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el estado de vuelo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al estado de vuelo es NULL
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);


int Passenger_setEstadoVueloNUMERO(Passenger* this,int numeroEstadoVuelo);
//***********************************************************************************************


/// @brief - Solicita los datos del pasajero al usuario
/// @param this - Puntero a pasajero
/// @return - Retorna 0 (EXITO) - Si se pudo ingresar correctamente todos los datos solicitados al usuario
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si alguno de los datos solicitados es erronéo
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
