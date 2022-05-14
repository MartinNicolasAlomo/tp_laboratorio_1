#ifndef INPUT_H_
#define INPUT_H_


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

/// @brief Verifica si la cadena contiene solo numeros
/// @param cadena cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es numerica, 0(FALSO) si no lo es, y -1 en caso de ERROR
int esNumerica(char cadena[], int limite);

/// @brief Valida que el numero entero recibido este en el rango pedido
/// @param numeroIngresado Es el numero entero a evaluar si esta dentro del rango
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero maximo a ser aceptado
/// @return Retorna 1 (VERDADERO) si esta dentro del rango, y 0 (FALSO) si no lo esta
int validarRangoEntero(int numeroIngresado, int minimo, int maximo);

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

/// @brief Verifica si la cadena contiene solo numeros y un solo punto decimal
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena es un numero flotante, 0 (FALSO) si no lo es, y -1 en caso de ERROR
int esFlotante(char cadena[],int limite);

/// @brief Valida que el numero con decimal recibido este en el rango pedido
/// @param numeroFlotante Es el numero con decimal a evaluar si esta dentro del rango
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero maximo a ser aceptado
/// @return Retorna 1 (VERDADERO) si esta dentro del rango, y 0 (FALSO) si no lo esta.
int validarRangoFlotante(float numeroFlotante, float minimo, float maximo);

/// @brief Solicita un unico nombre o apellido al usuario y luego de verificarlo devuelve el resultado
/// @param pNombre Puntero al espacio de memoria donde se dejara el nombre o apellido ingresado y verificado
/// @param limiteNombre Define el tamaño de la cadena
/// @param mensaje Mensaje a ser mostrado
/// @param mensajeError Mensasje que se muestra cuando hubo un error
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un unico nombre o apellido, y -1 si no se consiguio
int ingresarNombreUnico(char *pNombre, int limiteNombre, char *mensaje, char *mensajeError,int reintentos);

/// @brief Obtiene un unico nombre o apellido y verifica si la cadena contiene unicamente letras
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param limiteNombre Define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se obtiene un unico nombre o apellido, y -1 si no se consiguio
int conseguirUnSoloNombre(char* pResultado, int limiteNombre);

/// @brief Verifica si la cadena contiene unicamente letras
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena contiene unicamente letras, 0 (FALSO) si no lo es, y -1 en caso de ERROR
int esUnSoloNombre(char cadena[], int limite);

/// @brief Solicita un alfanumerico al usuario y luego de verificarlo devuelve el resultado
/// @param pAlfanumerico Puntero al espacio de memoria donde se dejara el alfanumerico ingresado y verificado
/// @param limiteAlfanumerico Define el tamaño de la cadena
/// @param mensaje Mensaje a ser mostrado
/// @param mensajeError Mensasje que se muestra cuando hubo un error
/// @param reintentos La cantidad de veces que el usuario puede volver a ingresar los datos
/// @return Retorna 0 (EXITO) si se obtuvo un alfanmerico, y -1 si no se consiguio
int ingresarAlfanumerico(char *pAlfanumerico, int limiteAlfanumerico, char *mensaje, char *mensajeError,int reintentos);

/// @brief Obtiene un alfanumerico y verifica si la cadena contiene letras, numeros o espacios en blanco
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param limiteAlfanumerico Define el tamaño de la cadena
/// @return Retorna 0 (EXITO) si se obtiene un alfanumerico, y -1 si no se consiguio
int conseguirAlfanumerico(char* pResultado,int limiteAlfanumerico);

/// @brief Verifica si la cadena contiene letras, numeros o espacios en blanco
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite Define el tamaño de la cadena
/// @return Retorna 1 (VERDADERO) si la cadena contiene letras, numeros o espacios en blanco, 0 (FALSO) si no lo es, y -1 en caso de ERROR
int esAlfanumerico(char cadena[], int limite);


#endif /* INPUT_H_ */
