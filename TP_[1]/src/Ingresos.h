#ifndef INGRESOS_H_
#define INGRESOS_H_


/// @brief Lee desde stdin hasta que encuentre un '\n' o hasta que haya copiado en cadena un maximo de 'longitud-1' caracteres
/// @param cadena Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param limite Define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se obtiene una cadena, -1 (ERROR) si no se consiguio
int obtenerDatos(char* cadena, int limite);


/// @brief Solicita un numero entero al usuario y luego de verificarlo devuelve el resultado
/// @param pEntero Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Mensaje a ser mostrado
/// @param mensajeError Mensasje que se muestra cuando hubo un error
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero minimo a ser aceptado
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un entero, y -1 si no se consiguio
int ingresarEntero(int *pEntero, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);


/// @brief Obtiene un numero entero y verifica si la cadena contiene solo numeros
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) si se obtiene un entero, y -1 si no se consiguio
int conseguirEntero(int* pResultado);


/// @brief Solicita un numero con decimal al usuario y luego de verificarlo devuelve el resultado
/// @param pFlotante Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Mensaje a ser mostrado
/// @param mensajeError Mensasje que se muestra cuando hubo un error
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero minimo a ser aceptado
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un numero con decimal, y -1 si no se consiguio
int ingresarFlotante(float *pFlotante, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);


/// @brief Obtiene un numero con decimal y verifica si la cadena contiene solo numeros y un solo punto decimal
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) si se obtiene un numero flotante, y -1 si no se consiguio
int conseguirFlotante(float* pResultado);


#endif /* INGRESOS_H_ */
