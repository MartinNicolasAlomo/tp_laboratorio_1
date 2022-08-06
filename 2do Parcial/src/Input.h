#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Validations.h"
#define MAX_BUFFER_STR 4096

/// @brief Lee desde stdin hasta que encuentre un '\n' o hasta que haya copiado en cadena un maximo de 'longitud-1' caracteres
/// @param cadena Puntero al espacio de memoria donde se guardar� la cadena de caracteres ingresada
/// @param limite Define el tama�o de la cadena
/// @return Retorna 0 (EXITO) si se obtuvo una cadena de caracteres, -1 (ERROR) si no se consigui�
int obtenerCadena(char* cadena, int limite);

/// @brief Solicita un n�mero entero al usuario, y luego de verificarlo, devuelve el resultado
/// @param pEntero Puntero al espacio de memoria donde se guardar� el n�mero entero ingresado
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese el n�mero
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param minimo Es el n�mero m�nimo a ser aceptado
/// @param maximo Es el n�mero m�ximo a ser aceptado
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un n�mero entero v�lido, -1 (ERROR) si no se consigui�
int ingresarEntero(int* pEntero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief Obtiene un n�mero entero y verifica si la cadena contiene solo n�meros
/// @param pEntero Puntero al espacio de memoria donde se guardar� el n�mero entero ingresado
/// @return Retorna 0 (EXITO) si se obtiene un n�mero entero v�lido, -1 (ERROR) si no se consigui�
int conseguirEntero(int* pEntero);

/// @brief Solicita un n�mero con decimales al usuario, y luego de verificarlo, devuelve el resultado
/// @param pFlotante Puntero al espacio de memoria donde se guardar� el n�mero con decimales ingresado
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese el n�mero
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param minimo Es el n�mero m�nimo a ser aceptado
/// @param maximo Es el n�mero m�ximo a ser aceptado
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un n�mero con decimales v�lido, -1 (ERROR) si no se consigui�
int ingresarFlotante(float *pFlotante, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);

/// @brief Obtiene un n�mero con decimales y verifica si la cadena contiene solo n�meros y un solo punto decimal
/// @param pFlotante Puntero al espacio de memoria donde se guardar� el n�mero con decimales ingresado
/// @return Retorna 0 (EXITO) si se obtiene un n�mero con decimales v�lido, -1 (ERROR) si no se consigui�
int conseguirFlotante(float* pFlotante);

/// @brief Solicita un nombre al usuario, y luego de verificarlo, devuelve el resultado
/// @param pNombre Puntero al espacio de memoria donde se guardar� el nombre ingresado
/// @param limite Define el tama�o de la cadena
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese el nombre
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un nombre v�lido, -1 (ERROR) si no se consigui�
int ingresarNombre(char* pNombre, int limite, char* mensaje, char* mensajeError, int reintentos);

/// @brief Obtiene un nombre y verifica si la cadena contiene letras. Tambien acepta espacios en blanco y guiones para nombres compuestos
/// @param pNombre Puntero al espacio de memoria donde se guardar� el nombre ingresado
/// @param limite Define el tama�o de la cadena
/// @return Retorna 0 (EXITO) si se obtuvo un nombre v�lido, -1 (ERROR) si no se consigui�
int conseguirNombre(char* pNombre, int limite);

/// @brief Solicita una descripci�n al usuario, y luego de verificarla, devuelve el resultado
/// @param pDescripcion Puntero al espacio de memoria donde se guardar� la descripci�n ingresada
/// @param limite Define el tama�o de la cadena
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese la descripci�n
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo una descripci�n v�lida, -1 (ERROR) si no se consigui�
int ingresarDescripcion(char* pDescripcion, int limite, char* mensaje, char* mensajeError, int reintentos);

/// @brief Obtiene una descripci�n y verifica si la cadena contiene letras, n�meros y otros caracteres espec�ficos
/// @param pDescripcion Puntero al espacio de memoria donde se guardar� la descripci�n ingresada
/// @param limite Define el tama�o de la cadena
/// @return Retorna 0 (EXITO) si se obtuvo una descripci�n v�lida, -1 (ERROR) si no se consigui�
int conseguirDescipcion(char* pDescripcion, int limite);

/// @brief Solicita un alfanum�rico al usuario, y luego de verificarlo, devuelve el resultado
/// @param pAlfanumerico Puntero al espacio de memoria donde se guardar� el alfanum�rico ingresado
/// @param limite Define el tama�o de la cadena
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese el alfanum�rico
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un alfanum�rico v�lido, -1 (ERROR) si no se consigui�
int ingresarAlfanumerico(char* pAlfanumerico, int limite, char* mensaje, char* mensajeError, int reintentos);

/// @brief Obtiene un alfanum�rico y verifica si la cadena contiene letras, n�meros o espacios en blanco
/// @param pAlfanumerico Puntero al espacio de memoria donde se guardar� el alfanum�rico ingresado
/// @param limite Define el tama�o de la cadena
/// @return Retorna 0 (EXITO) si se obtuvo un alfanum�rico v�lido, -1 (ERROR) si no se consigui�
int conseguirAlfanumerico(char* pAlfanumerico, int limite);

/// @brief Recibe un nombre como una cadena de caracteres, primero transforma todos los caracteres en min�sculas,
/// 		y luego, transforma todas las iniciales en may�sculas
/// @param nombre Cadena de caracteres a ser modificada
/// @param limite Define el tama�o de la cadena
/// @return Retorna 0 (EXITO) si se pudo modificar el nombre correctamente, y -1 si no se consigui�
int conseguirAlfanumerico(char* pAlfanumerico, int limite);

/// @brief Recibe una cadena de caracteres, primero transforma todos los caracteres en minusculas,
/// 		y luego transforma las iniciales en mayusculas
/// @param nombre Cadena de caracteres a ser modificada
/// @param limite Define el tama�o de la cadena
/// @return Retorna 0 (EXITO) si se pudo modificar la cadena de caracteres correctamente, y -1 si no se consiguio
int pasarInicialesMayusculas(char* nombre,int limite);

int ingresarArchivo(char* pArchivo, int limite, char* mensaje, char* mensajeError, int reintentos);
int conseguirArchivo(char* pArchivo, int limite);
int ingresarArchivoCSV(char* pArchivoCSV, int limite, char* mensaje, char* mensajeError, int reintentos);


#endif /* INPUT_H_ */
