#ifndef COMPUTER_H_
#define COMPUTER_H_
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

#define LARGONUMEROTXT 10
#define LARGODESCRIPCION 150
#define REINTENTOS 3
typedef struct{
	int id;
	char descripcion[LARGODESCRIPCION];
	float precio;
	int idTipo;
}eComputer;


/// @brief - Pide memoria para un nuevo empleado
/// @return - Retorna un puntero con espacio de memoria de tipo Passenger
eComputer* Computer_new();

/// @brief - Pide memoria para un pasajero nuevo y setea los campos en el espacio de memoria requerido
/// @param idStr - ID que va a setear
/// @param nombreStr - Nombre que va a setear
/// @param apellidoStr - Apellido que va a setear
/// @param precioStr - Precio que va a setear
/// @param codigoVueloStr - Codigo de vuelo que va a setear
/// @param tipoPasajeroStr - Tipo de pasajero que va a setear
/// @param estadoVueloStr - Estado de vuelo que va a setear
/// @return - Retorna el puntero con espacio de memoria de tipo Passenger con los campos ya seteados si salió bien, o puntero a NULL si hubo un error
eComputer* Computer_newParametros(char* idStr,char* descripcionStr,char* precioStr,char* idTipoStr);

/// @brief - Libera espacio de memoria de un pasajero
/// @param this - Puntero a pasajero
void Passenger_delete(eComputer* this);
//***********************************************************************************************


/// @brief - Carga el ID en el campo del pasajero
/// @param this - Puntero a pasajero
/// @param id - ID a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el ID en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el ID no es valido
int Passenger_setId(eComputer* this,int id);

/// @brief - Obtiene el ID del pasajero
/// @param this - Puntero a pasajero
/// @param id - Puntero al espacio donde se va a guardar el ID obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el ID del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al ID es NULL
int Passenger_getId(eComputer* this,int* id);

/// @brief - Carga el ID en el campo del pasajero (tratado como texto) y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param id - Puntero al ID que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el ID en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al ID es NULL

int Computer_setIdTXT(eComputer* this,char id[]);

/// @brief - Obtiene el ID del pasajero (tratado como texto)
/// @param this - Puntero a pasajero
/// @param id - Puntero al espacio donde se va a guardar el ID obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el ID del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al ID es NULL

int Computer_getIdTXT(eComputer* this,char id[]);
//***********************************************************************************************


/// @brief - Carga el nombre en el campo del pasajero y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param nombre - Puntero al nombre que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el nombre en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al nombre es NULL
int Computer_setDescripcion(eComputer* this,char* nombre);

/// @brief - Obtiene el nombre del empleado
/// @param this - Puntero a empleado
/// @param nombre - Puntero al espacio donde se va a guardar el nombre obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el nombre del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al nombre es NULL
int Computer_getDescripcion(eComputer* this,char* nombre);
//***********************************************************************************************




/// @brief - Carga el precio en el campo del pasajero
/// @param this - Puntero a pasajero
/// @param precio - Precio a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el precio en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el precio no es valido
int Product_setPrecio(eComputer* this,float precio);

/// @brief * Obtiene el precio del pasajero
/// @param this - Puntero a pasajero
/// @param precio - Puntero al espacio donde se va a guardar el precio obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el precio del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al precio es NULL
int Product_getPrecio(eComputer* this,float* precio);


/// @brief - Carga el precio en el campo del pasajero (tratado como texto) y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param precio - Puntero al precio que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el precio en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al precio es NULL
int Computer_setPrecioTXT(eComputer* this,char precio[]);

/// @brief - Obtiene el precio del pasajero (tratado como texto)
/// @param this - Puntero a pasajero
/// @param precio - Puntero al espacio donde se va a guardar el precio obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el precio del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al precio es NULL
int Computer_getPrecioTXT(eComputer* this,char precio[]);















/// @brief - Carga el tipo en el campo del pasajero
/// @param this - Puntero a pasajero
/// @param tipo - tipo a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el tipo en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el ID no es valido
int Computer_setTipo(eComputer* this,int tipo);

/// @brief - Obtiene el tipo del pasajero
/// @param this - Puntero a pasajero
/// @param tipo - Puntero al espacio donde se va a guardar el tipo obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el tipo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al ID es NULL
int Computer_getTipo(eComputer* this,int* tipo);

/// @brief - Carga el tipo en el campo del pasajero (tratado como texto) y valida que el dato sea correcto
/// @param this - Puntero a pasajero
/// @param tipo - Puntero al tipo que se va a cargar
/// @return - Retorna 0 (EXITO) - Si se pudo cargar el ID en el campo del pasajero
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al ID es NULL

int Computer_setTipo_TXT(eComputer* this,char tipo[]);

/// @brief - Obtiene el id de tipo del computadora (tratado como texto)
/// @param this - Puntero a computadora
/// @param tipo - Puntero al espacio donde se va a guardar el tipo obtenido
/// @return - Retorna 0 (EXITO) - Si se pudo obtener el tipo del computadora
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL o si el puntero al ID es NULL
int Computer_getTipo_TXT(eComputer* this,char tipo[]);


/// @brief Da el criterio de ordenamiento segun el ID de los pasajeros
/// @param primerPasajero Puntero al primer pasajero a comparar
/// @param segundoPasajero Puntero al segundo pasajero a comparar
/// @return Retorna 1 (EXITO) - Si el ID del primer pasajero es mayor, respecto al segundo
///					0 (EXITO) - Si ambos IDs son iguales
///					-1 (ERROR) - Si el ID del segundo pasajero es mayor, respecto al primero
///					-2 (ERROR) - Si: El puntero a los pasajeros es NULL o no se pudo obtener los datos de los pasajeros
int Passenger_compararPorIdTipo(void* primerPasajero,void* segundoPasajero);

/// @brief Ajusta el precio de las computadoras segun el tipo
/// @param elemento1 El elemento de donde se saca la informacion a modificar
/// @return - Retorna 0 (EXITO) - Si se pudo ajustar los preicios de la computadoras
/// 				 -1 (ERROR) - Si el puntero al pasajero es NULL
int Passenger_compararPrecios(void* elemento1);

#endif /* COMPUTER_H_ */
