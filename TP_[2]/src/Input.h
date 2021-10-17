#ifndef INPUT_H_
#define INPUT_H_

int IngresarDatos(char nombre[], int limiteNombre, char apellido[], int limiteApellido, float* salario, int* sector);
int IngresarEntero(int *pEntero, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int ValidarRangoEntero(int numeroIngresado, int minimo, int maximo);
int RecibirEntero(int *pResultado);
int esNumerica(char *cadena, int limite);
int IngresarFlotante(float *pFlotante, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);
int ValidarRangoFlotante(float numeroIngresado, float minimo, float maximo);
int RecibirFlotante(float *pResultado);
int esFlotante(char *cadena,int limite);
int IngresarNombre(char* pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
int RecibirNombre(char *pResultado, int limite);
int esSoloLetras(char *cadena, int limite);
int AjustarMayusculasNombres(char nombre[],int limite);
int PedirDatos(char *cadena, int longitud);


#endif
