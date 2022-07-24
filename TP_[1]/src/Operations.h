#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"
#include "Validations.h"
#define LARGO_MENSAJES 750
#define INGRESO_MINIMO 10
#define KM_MAXIMOS 50000.00
#define PRECIO_MAXIMO 750000.00
#define BITCOIN_PRECIO 4800000.00
#define REINTENTOS 3
#define DESCUENTO 10
#define INTERES 25
#define MSJ_MENU_INGRESO "Seleccione una opcion:\n1. Ingresar Kilómetros: (km = %.2f)\n2. Ingresar Precio de Vuelos: (Aerolíneas = $%.2f, Latam = $%.2f)\n3. Calcular todos los costos:\n4. Informar Resultados\n5. Carga forzada de datos\n6. Salir\n\n"
#define MSJ_INGRESO_KM "Ingrese los kilometros de vuelo (maximo %.2f km):\n"
#define MSJ_INGRESO_AEROLINEAS "Ingrese el precio para Aerolineas (maximo $%.2f):\n"
#define MSJ_INGRESO_LATAM "\nIngrese el precio para LATAM (maximo $%.2f):\n"
#define MSJ_ERROR_OPCION "No es una opción válida, reinténtelo de nuevo.\n\n\n"
#define MSJ_ERROR_KM "\nError! No es un kilometro correcto.\n\n\n"
#define MSJ_ERROR_PRECIO "\nError! No es un precio correcto.\n\n\n"


/// @brief Es el menu interactivo del programa
/// @return Retorna 0 (EXITO) si se pudo finalizar el menu interactivo, y -1 (ERROR) si hubo un fallo en el programa
int menuOpcionesEmpresas(void);

/// @brief Divide dos numeros flotantes
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param operandoUno Es el numero flotante a ser dividido
/// @param operandoDos Es el numero divisor
/// @return Retorna 0 (EXITO) si se pudo realizar la division, y -1 si no se pudo
int dividir(float* pResultado,float operandoUno,float operandoDos);

/// @brief Aplica el descuento y calcula el precio final
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param precio Es el precio inicial al que se le aplicara el descuento
/// @param descuento Es el descuento a aplicar
/// @return Retorna 0 (EXITO) si se logra aplicar el descuento, -1 si hubo ERROR y -2 si el descuento es cero y no hubo cambios en el precio
int calcularDescuento(float* pResultado,float precio,float descuento);

/// @brief Aplica el interes y calcula el precio final
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param precio Es el precio inicial al que se le aplicara el interes
/// @param interes Es el interes a aplicar
/// @return Retorna 0 (EXITO) si se logra aplicar el interes, -1 si hubo ERROR y -2 si el interes es cero y no hubo cambios en el precio
int calcularInteres(float* pResultado,float precio,float interes);

/// @brief Determina si un precio es mayor al otro y saca la diferencia restanndole el menor al del mayor
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param precioUno Es el primer precio que se paso.
/// @param precioDos Es el segundo precio que se paso.
/// @return Retorna 1 si encontro que uno es mayor al otro y se realizo la resta, 0 si ambos precios son iguales, -1 si hubo ERROR
int calcularDiferenciaPrecios(float* pResultado,float precioUno,float precioDos);


#endif /* OPERATIONS_H_ */
