#ifndef INGRESOS_H_
#define INGRESOS_H_

/// @brief le pide al usuario que elija un numero segun sea la opcion que desea seleccionar.
/// @param pResultado es el puntero de la variable Opcion en la funcion Main.
/// @param mensaje es el mensaje que se imprime por pantalla indicandole al usaurio lo que tiene que hacer.
/// @param mensajeError es el mensaje que le aparace al usuario cuando se equivoca al intentar seleccionar una opcion.
/// @param minimo es el primer numero de las opciones.
/// @param maximo es el numero limite de opciones a elejir.
/// @param reintentos son la cantidad de reintentos que se le dan al usuario luego equivocarse.
/// @return devuelve 0 si la opcion elegida estuvo dentro del rango correcto.
int PedirOpcion(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/// @brief le pide al usuario que ingrese el numero que desea ingresar.
/// @param mensaje es el mensaje que se imprime pidiendole al usuario quue ingrese un numero.
/// @return devuelve el numero que ingreso el usuario.
float PedirNumero(char mensaje[]);

#endif /* INGRESOS_H_ */
