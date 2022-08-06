#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Validations.h"
#define MAX_BUFFER_STR 4096

/// @brief Lee desde stdin hasta que encuentre un '\n' o hasta que haya copiado en cadena un maximo de 'longitud-1' caracteres
/// @param cadena Puntero al espacio de memoria donde se guardará la cadena de caracteres ingresada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se obtuvo una cadena de caracteres, -1 (ERROR) si no se consiguió
int obtenerCadena(char* cadena, int limite);

/// @brief Solicita un número entero al usuario, y luego de verificarlo, devuelve el resultado
/// @param pEntero Puntero al espacio de memoria donde se guardará el número entero ingresado
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese el número
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param minimo Es el número mínimo a ser aceptado
/// @param maximo Es el número máximo a ser aceptado
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un número entero válido, -1 (ERROR) si no se consiguió
int ingresarEntero(int* pEntero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief Obtiene un número entero y verifica si la cadena contiene solo números
/// @param pEntero Puntero al espacio de memoria donde se guardará el número entero ingresado
/// @return Retorna 0 (EXITO) si se obtiene un número entero válido, -1 (ERROR) si no se consiguió
int conseguirEntero(int* pEntero);

/// @brief Solicita un número con decimales al usuario, y luego de verificarlo, devuelve el resultado
/// @param pFlotante Puntero al espacio de memoria donde se guardará el número con decimales ingresado
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese el número
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param minimo Es el número mínimo a ser aceptado
/// @param maximo Es el número máximo a ser aceptado
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un número con decimales válido, -1 (ERROR) si no se consiguió
int ingresarFlotante(float *pFlotante, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);

/// @brief Obtiene un número con decimales y verifica si la cadena contiene solo números y un solo punto decimal
/// @param pFlotante Puntero al espacio de memoria donde se guardará el número con decimales ingresado
/// @return Retorna 0 (EXITO) si se obtiene un número con decimales válido, -1 (ERROR) si no se consiguió
int conseguirFlotante(float* pFlotante);

/// @brief Solicita un nombre al usuario, y luego de verificarlo, devuelve el resultado
/// @param pNombre Puntero al espacio de memoria donde se guardará el nombre ingresado
/// @param limite Define el tamaño de la cadena
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese el nombre
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un nombre válido, -1 (ERROR) si no se consiguió
int ingresarNombre(char* pNombre, int limite, char* mensaje, char* mensajeError, int reintentos);

/// @brief Obtiene un nombre y verifica si la cadena contiene letras. Tambien acepta espacios en blanco y guiones para nombres compuestos
/// @param pNombre Puntero al espacio de memoria donde se guardará el nombre ingresado
/// @param limite Define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se obtuvo un nombre válido, -1 (ERROR) si no se consiguió
int conseguirNombre(char* pNombre, int limite);

/// @brief Solicita una descripción al usuario, y luego de verificarla, devuelve el resultado
/// @param pDescripcion Puntero al espacio de memoria donde se guardará la descripción ingresada
/// @param limite Define el tamaño de la cadena
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese la descripción
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo una descripción válida, -1 (ERROR) si no se consiguió
int ingresarDescripcion(char* pDescripcion, int limite, char* mensaje, char* mensajeError, int reintentos);

/// @brief Obtiene una descripción y verifica si la cadena contiene letras, números y otros caracteres específicos
/// @param pDescripcion Puntero al espacio de memoria donde se guardará la descripción ingresada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se obtuvo una descripción válida, -1 (ERROR) si no se consiguió
int conseguirDescipcion(char* pDescripcion, int limite);

/// @brief Solicita un alfanumérico al usuario, y luego de verificarlo, devuelve el resultado
/// @param pAlfanumerico Puntero al espacio de memoria donde se guardará el alfanumérico ingresado
/// @param limite Define el tamaño de la cadena
/// @param mensaje Mensaje a ser mostrado para que el usuario ingrese el alfanumérico
/// @param mensajeError Mensaje que se muestra cuando hubo un error
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un alfanumérico válido, -1 (ERROR) si no se consiguió
int ingresarAlfanumerico(char* pAlfanumerico, int limite, char* mensaje, char* mensajeError, int reintentos);

/// @brief Obtiene un alfanumérico y verifica si la cadena contiene letras, números o espacios en blanco
/// @param pAlfanumerico Puntero al espacio de memoria donde se guardará el alfanumérico ingresado
/// @param limite Define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se obtuvo un alfanumérico válido, -1 (ERROR) si no se consiguió
int conseguirAlfanumerico(char* pAlfanumerico, int limite);

/// @brief Recibe un nombre como una cadena de caracteres, primero transforma todos los caracteres en minúsculas,
/// 		y luego, transforma todas las iniciales en mayúsculas
/// @param nombre Cadena de caracteres a ser modificada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se pudo modificar el nombre correctamente, y -1 si no se consiguió
int conseguirAlfanumerico(char* pAlfanumerico, int limite);

/// @brief Recibe una cadena de caracteres, primero transforma todos los caracteres en minusculas,
/// 		y luego transforma las iniciales en mayusculas
/// @param nombre Cadena de caracteres a ser modificada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se pudo modificar la cadena de caracteres correctamente, y -1 si no se consiguio
int pasarInicialesMayusculas(char* nombre,int limite);

int ingresarArchivo(char* pArchivo, int limite, char* mensaje, char* mensajeError, int reintentos);
int conseguirArchivo(char* pArchivo, int limite);
int ingresarArchivoCSV(char* pArchivoCSV, int limite, char* mensaje, char* mensajeError, int reintentos);


#endif /* INPUT_H_ */
