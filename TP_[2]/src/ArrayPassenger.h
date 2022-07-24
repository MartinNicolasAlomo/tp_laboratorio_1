#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"
#include "Validations.h"
#define CANT_PASAJEROS 2000
#define CANT_TIPOS_PASAJEROS 4
#define CANT_ESTADOS_VUELOS 4
#define REINTENTOS 3
#define LARGO_TEXTO 16
#define TRUE 1
#define FALSE 0
#define LARGO_NOMBRE 51
#define LARGO_CODIGO 10
#define MSJ_MENU_PRINCIPAL "Seleccione una opción.\n1. Dar de alta un pasajero.\n2. Modificar un pasajero.\n3. Dar de baja un pasajero.\n4. Informar.\n5. Carga forzada.\n6. Salir.\n\n"
#define MSJ_ERROR_OPCION "No es una opción válida, reinténtelo de nuevo.\n\n\n"
#define MSJ_MENU_MODIFICAR "¿Qué desea modificar?\n  1- Nombre.\n  2- Apellido.\n  3- Precio.\n  4- Tipo de pasajero.\n  5- Codigo de vuelo.\n  6- Finalizar cambios.\n\n"
#define MSJ_MENU_INFORME "¿Qué desea informar?\n  1- Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n  2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n  3- Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\n\n"
#define MSJ_ID_MODIFICAR "Ingrese el ID que desea modificar:\n\n"
#define MSJ_ID_ELIMINAR "Ingrese el ID que desea eliminar:\n\n"
#define MSJ_ERROR_ID "No es un ID válido, reinténtelo de nuevo.\n\n\n"
#define MSJ_OPCIONORDEN "¿En qué orden quiere ordenarlos?\n  1- Ascendente\n  0- Descendente\n\n"
#define MSJ_CONFIRMAR_AGREGADO "¿Está seguro/a de quiere agregar este pasajero?\n  1- Si\n  0- No\n\n"
#define MSJ_CONFIRMAR_MODIFICACION "¿Está seguro/a de quiere realizar las modificaciones?\n  1- Si\n  0- No\n\n"
#define MSJ_CONFIRMAR_ELIMINADO "¿Está seguro/a de quiere eliminar este pasajero?\n  1- Si\n  0- No\n\n"

typedef struct{
	int id;
	char name[LARGO_NOMBRE];
	char lastName[LARGO_NOMBRE];
	float price;
	char flyCode[LARGO_CODIGO];
	//int typePassenger;	//***
	//int statusFlight;	//***
	int idEstadoVuelo;
	int idTipoPasajero;

	int isEmpty;
}ePasajero;

typedef struct{
	int id;
	char descripcion[LARGO_TEXTO];
}eTipoPasajero;

typedef struct{
	int id;
	char descripcion[LARGO_TEXTO];
}eEstadoVuelo;


/// @brief Es el menu principal de la entidad Passenger, se usa un ABM
/// @return Retorna 0 (EXITO) si logro finalizar la operatoria, -1 (ERROR) si no se consiguio
int pasaj_menuPrincipal(void);

/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int pasaj_inicializarLista(ePasajero* list, int len);

/** \brief add in a existing list of passengers the values received as parameters* in the first empty position
* \param list passenger* Pointer to array of passenger
* \param len int Array length
* \param id int ID to be assigned to the passenger
* \param name[] char Name of the passenger
* \param lastName[] char Last name of the passenger
* \param price float Price of the flight
* \param typePassenger int Travel class of the flight
* \param statusFlight int Status of the flight
* \param flycode[] char Code of the flight
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int pasaj_agregarPasajero(ePasajero* aPasajeros, int limite, int* indiceNuevo);

/** \brief find a Passenger by Id en returns the index position in array.*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param id int ID of a passenger, used to find its index
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*/
int pasaj_buscarPasajeroPorId(ePasajero* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param id int ID of the passenger to be removed
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
*/
int pasaj_eliminarPasajero(ePasajero* aPasajeros, int limite, int* indiceBuscado);

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param order int [1] indicate UP - [0] indicate DOWN
* \return return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int pasaj_ordenarPorApellidoYTipoPasajero(ePasajero* list, int len, int order);

/** \brief print the content of passengers array
* \param list Passenger* Pointer to array of passenger
* \param length int Array length
* \return return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int pasaj_imprimirLista(ePasajero* aPasajeros, int limPasajeros, eEstadoVuelo* aEstadosVuelos, int limEstadosVuelos,
							eTipoPasajero* aTiposPasajeros, int limTiposPasajeros);

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param order int [1] indicate UP - [0] indicate DOWN
* \return return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int pasaj_ordenarPorCodigoVueloYEstadoVuelo(ePasajero* list, int len, int order);


/// @brief Busca la proxima posiciones del vector que se encuentre vacia
/// @param vector Es el vector en el que se buscara la posicion vacia
/// @param limite Define el tamaño del vector
/// @return Retorna 0 (EXITO) si se logro encontrar una posicion vacia, -1 (ERROR) si no se consiguio
int pasaj_buscarIndiceVacio(ePasajero vector[],int limite);

/// @brief Pide datos al usuario para cargarlos a un pasajero
/// @param vector Es el vector en el que se guardaran los datos ingresados por el usuario
/// @param limite Define el tamaño del vector
/// @param id Es el id que se le asignara al nuevo pasajero ingresado
/// @return  Retorna 0 (EXITO) si se logro cargar y agregar el nuevo pasajero, -1 (ERROR) si no se consiguio ninguno
int pasaj_cargarDatosPasajero(ePasajero* pElemento);
/// @brief Es el menu de opciones para modificar los datos de un pasajero a eleccion
/// @param vector Es el vector en el que se guardaran los nuevos datos modificados
/// @param limite Define el tamaño del vector
/// @param id Es el id con el cual se identificara el pasajero a modificar
/// @return Retorna 0 (EXITO) si se logro modificar el pasajero, -1 (ERROR) si no se consiguio
int pasaj_modificarPasajero(ePasajero* aPasajeros, int limite, int* indiceBuscado, float* precioPrevio);

int pasaj_menuModificar(ePasajero* pElemento, int* cambios);

/// @brief Imprime un solo elemento del vector
/// @param pElemento Es el elemento a imprimir
/// @return Retorna 0 (EXITO) si se logro imprimir el elemento, -1 (ERROR) si no se consiguio
int pasaj_imprimirElemento(ePasajero* pasajero, eEstadoVuelo* estadoVuelo, eTipoPasajero* tipoPasajero);

/// @brief Es el menu de opciones de informes
/// @param vector Es el vector de donde se obtendran los datos a informar
/// @param limite Define el tamaño del vector
/// @param mensajeInforme Es el mensaje de opciones de informes
/// @param mensajeOrden Es el mensaje de opciones de orden
/// @param mensajeOpcionError Mensasje que se muestra cuando hubo se ingreso mal la opcion
/// @param precioTotal Es el total de precios ingresados hasta el momento
/// @param cantidadTotal Es el total de pasajeros ingresados hasta el momento
/// @return Retorna 0 (EXITO) si se logro informar los solicitado, -1 (ERROR) si no se consiguio

int pasaj_menuInformes(ePasajero* aPasajeros, int limPasajeros, eEstadoVuelo* aEstadosVuelos, int limEstadosVuelos,
						eTipoPasajero* aTiposPasajeros, int limTiposPasajeros, float precioTotal, int cantidadTotal);

/// @brief Calcula el precio promedio de los importes ingresados totales
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado del promedio
/// @param precioTotal Es el precio total ingresado hasta el momento
/// @param cantidadTotal Es la cantidad total de pasajeros ingresados hasta el momento
/// @return Retorna 0 (EXITO) si se logro calcular el precio promedio, -1 (ERROR) si no se consiguio
int pasaj_calcularPrecioPromedio(float* pResultado, float precioTotal, int cantidadTotal);


/// @brief Determina cuantos pasajeros superan el precio promedio y los devuelve
/// @param vector Es el vector de donde se obtendran los datos
/// @param limite Define el tamaño del vector
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de los pasajeros que superan el precio promedio
/// @param precioPromedio Es el precio promedio de todos los precios ingresados
/// @return Retorna 0 (EXITO) si se logro calcular cuantos pasajeros superan el precio promedio, -1 (ERROR) si no se consiguio
int pasaj_calcularSuperanPrecioPromedio(ePasajero vector[],int limite,int* pResultado, float precioPromedio);

/// @brief Añade un nuevo pasajero al vector, que fue previamente hardcodeado, pasandole cada campo como parametro
/// @param vector Es el vector en el que se guardaran los datos hardcodeados previamente
/// @param limite Define el tamaño del vector
/// @param id Es el id que se le asignara al nuevo pasajero (autoincremental)
/// @param name Es el nombre del pasajero
/// @param lastName Es el apellido del pasajero
/// @param price Es el precio del vuelo
/// @param flyCode Es el codigo del vuelo
/// @param typePassenger Es la clase de vuelo del pasajero (economico, premium, ejecutivo o primera clase)
/// @param statusFlight Es el estado del vuelo del pasajero (activo, demorado, reprogramado o cancelado)
/// @return Retorna 0 (EXITO) si se logro añadir el pasajero hardcodeado, -1 (ERROR) si no se consiguio

int pasaj_cargaForzadaPasajero(ePasajero* aPasajeros, int limite, int* indiceNuevo, char* name, char* lastName, float price,
									char* flyCode, int typePassenger, int statusFlight);

#endif /* ARRAYPASSENGER_H_ */
