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
#define LARGOCODIGO 10
#define MSJ_MENUPRINCIPAL "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n3. Alta de pasajero.\n4. Modificar datos de pasajero.\n5. Baja de pasajero\n6. Listar pasajeros.\n7. Ordenar pasajeros.\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10. Salir\n\n"
#define MSJ_ERROROPCION "No es una opción válida, reinténtelo de nuevo.\n\n\n"
#define MSJ_MENUMODIFICAR "¿Qué desea modificar?\n  1-Nombre\n  2-Apellido\n  3-Precio\n  4-Codigo de vuelo\n  5-Tipo de pasajero\n  6-Estado de vuelo\n  7-Finalizar cambios\n\n"
#define MSJ_MENUORDENAR "¿Cómo desea ordenarlos?\n  1- Por ID\n  2- Por Nombre\n  3- Por Apellido\n  4- Por Precio\n  5- Por Codigo de Vuelo\n  6- Por Tipo de Pasajero\n  7- Por Estado de Vuelo\n  8- Volver al Menú Principal\n\n"


typedef struct
{
	int id;
	char nombre[LARGONOMBRE];
	char apellido[LARGONOMBRE];
	float precio;
	char codigoVuelo[LARGOCODIGO];
	int tipoPasajero;
	int estadoVuelo;
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


/// @brief - Recibe una cadena de caracteres (descripcion del tipo de pasajero), valida que el dato sea correcto
/// 		 y segun el texto, le carga un numero en el campo del tipo de pasajero del pasajero (dato tratado como int)
/// @param this - Puntero a pasajero
/// @param tipoPasajero - Puntero al tipo de pasajero que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo asignar el numero correspondiente al campo segun el texto recibido
/// 				 -1 (ERROR) - Si el puntero al pasajero o al tipo de pasajero es NULL o si el tipo de pasajero es invalido
int Passenger_setTipoPasajeroTXT_NUM(Passenger* this,char* tipoPasajero);

/// @brief - Obtiene el numero asignado al tipo de pasajero y le carga su descripcion correspondiente al auxiliar
/// @param this - Puntero a pasajero
/// @param tipoPasajero - Puntero al espacio donde se va a guardar la descripcion del tipo de pasajero (texto) obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo cargar la descripcion del tipo de pasajero (texto) en el auxiliar
/// 				 -1 (ERROR) - Si el puntero al pasajero o al tipo de pasajero es NULL o si el tipo de pasajero es invalido
int Passenger_getTipoPasajeroNUM_TXT(Passenger* this,char* tipoPasajero);

/// @brief - Carga el tipo de pasajero (de forma numerica) en el campo del pasajero y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param tipoPasajero - Tipo de pasajero a cargar (numerico)
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el tipo de pasajero (numerico) en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el tipo de pasajero es invalido
int Passenger_setTipoPasajeroNumerico(Passenger* this,int tipoPasajero);

/// @brief - Obtiene el tipo de pasajero del pasajero (de forma numerica)
/// @param this - Puntero a empleado
/// @param tipoPasajero - Puntero al espacio donde se va a guardar el tipo de pasajero (numerico) obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el tipo de pasajero (numerico) del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al tipo de pasajero es NULL
int Passenger_getTipoPasajeroNumerico(Passenger* this,int* tipoPasajero);
//***********************************************************************************************


/// @brief - Recibe una cadena de caracteres (descripcion del estado de vuelo), valida que el dato sea correcto
/// 		 y segun el texto, le carga un numero en el campo del estado de vuelo del pasajero (dato tratado como int)
/// @param this - Puntero a pasajero
/// @param estadoVuelo - Puntero al estado de vuelo que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo asignar el numero correspondiente al campo segun el texto recibido
/// 				 -1 (ERROR) - Si el puntero al pasajero o al estado de vuelo es NULL o si el estado de vuelo es invalido
int Passenger_setEstadoVueloTXT_NUM(Passenger* this,char* estadoVuelo);

/// @brief - Obtiene el numero asignado al estado de vuelo y le carga su descripcion correspondiente al auxiliar
/// @param this - Puntero a pasajero
/// @param estadoVuelo - Puntero al espacio donde se va a guardar la descripcion del estado de vuelo (texto) obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo cargar la descripcion del estado de vuelo (texto) en el auxiliar
/// 				 -1 (ERROR) - Si el puntero al pasajero o al estado de vuelo es NULL o si el estado de vuelo es invalido
int Passenger_getEstadoVueloNUM_TXT(Passenger* this,char* estadoVuelo);

/// @brief - Carga el estado de vuelo (de forma numerica) en el campo del pasajero y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param estadoVuelo - Estado de vuelo a cargar (numerico)
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el estado de vuelo (numerico) en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el estado de vuelo es invalido
int Passenger_setEstadoVueloNumerico(Passenger* this,int estadoVuelo);

/// @brief - Obtiene el estado de vuelo del pasajero (de forma numerica)
/// @param this - Puntero a empleado
/// @param estadoVuelo - Puntero al espacio donde se va a guardar el estado de vuelo (numerico) obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el estado de vuelo (numerico) del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al estado de vuelo es NULL
int Passenger_getEstadoVueloNumerico(Passenger* this,int* estadoVuelo);
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
///					-2 (ERROR) - Si: El puntero a los pasajeros es NULL o no se pudo obtener los datos de los pasajeros
int Passenger_compararPorId(void* primerPasajero,void* segundoPasajero);

/// @brief Da el criterio de ordenamiento segun el precio de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el sueldo del primer pasajero es mayor, respecto al segundo
///					0 (EXITO) - Si ambos precios son iguales
///					-1 (ERROR) - Si el sueldo del segundo pasajero es mayor, respecto al primero
///					-2 (ERROR) - Si: El puntero a los pasajeros es NULL o no se pudo obtener los datos de los pasajeros
int Passenger_compararPorPrecio(void* primerPasajero,void* segundoPasajero);

/// @brief Da el criterio de ordenamiento segun el apellido de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el apellido del primer pasajero viene antes que el del segundo
///					0 (EXITO) - Si ambos apellidos son iguales
///					-1 (ERROR) - Si el apellido del segundo pasajero viene antes que el del primero
///					-2 (ERROR) - Si: El puntero a los pasajeros es NULL o no se pudo obtener los datos de los pasajeros
int Passenger_compararPorApellido(void* primerPasajero,void* segundoPasajero);

/// @brief Da el criterio de ordenamiento segun el código de vuelo de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el código de vuelo del primer pasajero viene antes que el del segundo
///					0 (EXITO) - Si ambos códigos de vuelo son iguales
///					-1 (ERROR) - Si el código de vuelo del segundo pasajero viene antes que el del primero
///					-2 (ERROR) - Si: El puntero a los pasajeros es NULL o no se pudo obtener los datos de los pasajeros
int Passenger_compararPorCodigoVuelo(void* primerPasajero,void* segundoPasajero);

/// @brief Da el criterio de ordenamiento segun el nombre de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el nombre del primer pasajero viene antes que el del segundo
///					0 (EXITO) - Si ambos nombres de vuelo son iguales
///					-1 (ERROR) - Si el nombre del segundo pasajero viene antes que el del primero
///					-2 (ERROR) - Si: El puntero a los pasajeros es NULL o no se pudo obtener los datos de los pasajeros
int Passenger_compararPorNombre(void* primerPasajero,void* segundoPasajero);

/// @brief Da el criterio de ordenamiento segun el código de vuelo de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el tipo de pasajero del primer pasajero viene antes que el del segundo
///					0 (EXITO) - Si ambos tipos de pasajero son iguales
///					-1 (ERROR) - Si el tipo de pasajero del segundo pasajero viene antes que el del primero
///					-2 (ERROR) - Si: El puntero a los pasajeros es NULL o no se pudo obtener los datos de los pasajeros
int Passenger_compararPorTipoPasajero(void* primerPasajero,void* segundoPasajero);

/// @brief Da el criterio de ordenamiento segun el estado de vuelo de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el estado de vuelo del primer pasajero viene antes que el del segundo
///					0 (EXITO) - Si ambos estados de vuelo son iguales
///					-1 (ERROR) - Si el estado de vuelo del segundo pasajero viene antes que el del primero
///					-2 (ERROR) - Si: El puntero a los pasajeros es NULL o no se pudo obtener los datos de los pasajeros
int Passenger_compararPorEstadoVuelo(void* primerPasajero,void* segundoPasajero);



#endif /* PASSENGER_H_ */
