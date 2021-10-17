#ifndef INPUT_H_
#define INPUT_H_

/// @brief
/// @param nombre nombre del empleado
/// @param limiteNombre largo del nombre
/// @param apellido apellido del empleado
/// @param limiteApellido largo del nombre
/// @param salario
/// @param sector
/// @return
int IngresarDatos(char nombre[], int limiteNombre, char apellido[], int limiteApellido, float* salario, int* sector);

/// @brief
/// @param pEntero
/// @param mensaje
/// @param mensajeError muestra un mensaje de error cuando el usuario se equivoca
/// @param minimo
/// @param maximo
/// @param reintentos la cantidad de reintentos que se le da al usuario
/// @return
int IngresarEntero(int *pEntero, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/// @brief
/// @param numeroIngresado
/// @param minimo
/// @param maximo
/// @return
int ValidarRangoEntero(int numeroIngresado, int minimo, int maximo);

/// @brief
/// @param pResultado
/// @return
int RecibirEntero(int *pResultado);

/// @brief
/// @param cadena
/// @param limite
/// @return
int esNumerica(char *cadena, int limite);

/// @brief
/// @param pFlotante
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos la cantidad de reintentos que se le da al usuario
/// @return
int IngresarFlotante(float *pFlotante, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);

/// @brief
/// @param numeroIngresado
/// @param minimo
/// @param maximo
/// @return
int ValidarRangoFlotante(float numeroIngresado, float minimo, float maximo);

/// @brief
/// @param pResultado
/// @return
int RecibirFlotante(float *pResultado);

/// @brief
/// @param cadena
/// @param limite
/// @return
int esFlotante(char *cadena,int limite);

/// @brief
/// @param pNombre
/// @param limite
/// @param mensaje
/// @param mensajeError
/// @param reintentos la cantidad de reintentos que se le da al usuario
/// @return
int IngresarNombre(char* pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);

/// @brief
/// @param pResultado
/// @param limite tamaño del nombre
/// @return
int RecibirNombre(char *pResultado, int limite);

/// @brief
/// @param cadena
/// @param limite tamaño del vector
/// @return
int esSoloLetras(char *cadena, int limite);

/// @brief
/// @param nombre
/// @param limite tamaño del vector
/// @return
int AjustarMayusculasNombres(char nombre[],int limite);

/// @brief
/// @param cadena
/// @param longitud tamaño del vector
/// @return
int PedirDatos(char *cadena, int longitud);


#endif
