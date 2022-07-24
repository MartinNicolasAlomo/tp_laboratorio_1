#include "Operations.h"

int menuOpcionesEmpresas(void){
	int retorno=-1;
	int opcion;
	char mensajeMenuIngreso[LARGO_MENSAJES];
	char mensajeKmIngreso[LARGO_MENSAJES];
	char mensajeAerolineasIngreso[LARGO_MENSAJES];
	char mensajeLatamIngreso[LARGO_MENSAJES];
	float kilometrosIngresados=0;
	float precioLatamIngresado=0;
	float precioAerolineasIngresado=0;
	int flagKilometros=1;
	int flagLatam=1;
	int flagAerolineas=1;
	int flagCalculos=1;
	int flagReingresos=1;
	float precioLatamDescuento;
	float precioLatamInteres;
	float precioLatamBitcoin;
	float precioLatamUnitario;
	float precioAerolineasDescuento;
	float precioAerolineasInteres;
	float precioAerolineasBitcoin;
	float precioAerolineasUnitario;
	float diferenciaPrecios;
	int respuestaDescuentoLatam;
	int respuestaInteresLatam;
	int respuestaBitcoinLatam;
	int respuestaUnitarioLatam;
	int respuestaDescuentoAerolineas;
	int respuestaInteresAerolineas;
	int respuestaBitcoinAerolineas;
	int respuestaUnitarioAerolineas;
	int respuestaDiferenciaPrecios;
	int respuestaDiferenciaPreciosHardcodeado;

	snprintf(mensajeKmIngreso, sizeof(mensajeKmIngreso), MSJ_INGRESO_KM, KM_MAXIMOS);
	snprintf(mensajeAerolineasIngreso, sizeof(mensajeAerolineasIngreso), MSJ_INGRESO_AEROLINEAS, PRECIO_MAXIMO);
	snprintf(mensajeLatamIngreso, sizeof(mensajeLatamIngreso), MSJ_INGRESO_LATAM, PRECIO_MAXIMO);
	do{
		snprintf(mensajeMenuIngreso, sizeof(mensajeMenuIngreso), MSJ_MENU_INGRESO, kilometrosIngresados, precioAerolineasIngresado, precioLatamIngresado);
		if(!ingresarEntero(&opcion, mensajeMenuIngreso, MSJ_ERROR_OPCION, 1, 6, REINTENTOS)){
			switch(opcion){
			case 1:
				if(!flagReingresos){
					puts("Ya se ingresaron kilometros previamente. Finalice la operación para volver a reingresar kilometros.\n\n\n");
					flagReingresos=0;
				}
				else{
					if(!ingresarFlotante(&kilometrosIngresados, mensajeKmIngreso, MSJ_ERROR_KM, INGRESO_MINIMO, KM_MAXIMOS, REINTENTOS)){
						printf("KM ingresados: %.2f km.\n\n\n\n", kilometrosIngresados);
						flagKilometros=0;
					}
					else{
						puts("No se pudo ingresar los kilometros de vuelo.\n\n\n");
					}
				}
				break;
			case 2:
				if(!flagReingresos){
					puts("Ya se ingresaron los precios previamente. Finalice la operacion para volver a reingresar precios.\n\n\n");
					flagReingresos=0;
				}
				else if(!flagKilometros){
					if(!ingresarFlotante(&precioAerolineasIngresado, mensajeAerolineasIngreso, MSJ_ERROR_PRECIO, INGRESO_MINIMO, PRECIO_MAXIMO, REINTENTOS)){
						flagAerolineas=0;
					}
					else{
						puts("No se pudo ingresar el precio para Aerolineas.\nPara poder ingresar el precio para LATAM, en necesario que primero se ingrese un precio para Aerolineas.\n\n\n");
					}
					if(!flagAerolineas){
						if(!ingresarFlotante(&precioLatamIngresado, mensajeLatamIngreso, MSJ_ERROR_PRECIO, INGRESO_MINIMO, PRECIO_MAXIMO, REINTENTOS)){
							printf("\nSe ingresaron los precios correctamente:\n  El precio de vuelo para Aerolineas es $%.2f.\n  El precio de vuelo para LATAM es $%.2f.\n\n\n\n",
																					precioAerolineasIngresado, precioLatamIngresado);
							flagLatam=0;
						}
						else{
							puts("No se pudo ingresar el precio para LATAM.\nPara poder continuar con las operaciones, en necesario que primero se ingrese un precio para Latam.\n\n\n");
						}
					}
				}
				else{
					puts("Falta ingresar los kilometros de vuelo para realizar las operaciones.\n\n\n");
				}
				break;
			case 3:
				if(flagKilometros){
					puts("Falta ingresar los kilometros de vuelo para realizar las operaciones.\n\n\n");
				}
				else if(flagLatam){
					puts("No se ingresaron los precios de los vuelos para realizar las operaciones.\n\n\n");
				}
				else if(!flagLatam || !flagReingresos){
					flagCalculos=0;
					flagReingresos=0;
					puts("Se calcularon todos los costos.\n\n\n");
					respuestaDescuentoLatam=calcularDescuento(&precioLatamDescuento, precioLatamIngresado, DESCUENTO);
					respuestaInteresLatam=calcularInteres(&precioLatamInteres, precioLatamIngresado, INTERES);
					respuestaBitcoinLatam=dividir(&precioLatamBitcoin, precioLatamIngresado, BITCOIN_PRECIO);
					respuestaUnitarioLatam=dividir(&precioLatamUnitario, precioLatamIngresado, kilometrosIngresados);
					respuestaDescuentoAerolineas=calcularDescuento(&precioAerolineasDescuento, precioAerolineasIngresado, DESCUENTO);
					respuestaInteresAerolineas=calcularInteres(&precioAerolineasInteres, precioAerolineasIngresado, INTERES);
					respuestaBitcoinAerolineas=dividir(&precioAerolineasBitcoin, precioAerolineasIngresado, BITCOIN_PRECIO);
					respuestaUnitarioAerolineas=dividir(&precioAerolineasUnitario, precioAerolineasIngresado, kilometrosIngresados);
					respuestaDiferenciaPrecios=calcularDiferenciaPrecios(&diferenciaPrecios, precioLatamIngresado, precioAerolineasIngresado);
				}
				break;
			case 4:
				if(flagKilometros){
					puts("Falta ingresar los kilometros de vuelo para realizar las operaciones.\n\n\n");
				}
				else if(flagLatam){
					puts("No se ingresaron los precios de los vuelos para realizar las operaciones.\n\n\n");
				}
				else if(flagCalculos){
					puts("Aun no se realizó ningún calculo de precio.\n\n\n");
				}
				else if(!flagCalculos || !flagReingresos){
					printf("KMs ingresados: %.2f.\n\n", kilometrosIngresados);
					printf("Aerolineas: %.2f.\n", precioAerolineasIngresado);
					if(!respuestaDescuentoAerolineas){
						printf("a) Precio con tarjeta de débito: $%.2f.\n", precioAerolineasDescuento);
					}
					else{
						puts("No se pudo calcular el precio final con descuento para Aerolineas.\n");
					}
					if(!respuestaInteresAerolineas){
						printf("b) Precio con tarjeta de crédito: $%.2f.\n", precioAerolineasInteres);
					}
					else{
						 puts("No se pudo calcular el precio final con interes para Aerolineas.\n");
					}
					if(!respuestaBitcoinAerolineas){
						 printf("c) Precio pagando con bitcoin: %.2f BTC.\n", precioAerolineasBitcoin);
					}
					else{
						 puts("No se pudo calcular el precio de Aerolineas pagando con bitcoin.\n");
					}
					if(!respuestaUnitarioAerolineas){
						 printf("d) Precio unitario: $%.2f.\n\n", precioAerolineasUnitario);
					}
					else{
						puts("No se pudo calcular el precio unitario para Aerolineas.\n");
					}
					printf("Latam: %.2f.\n",precioLatamIngresado);
					if(!respuestaDescuentoLatam){
						printf("a) Precio con tarjeta de débito: $%.2f.\n", precioLatamDescuento);
					}
					else{
						puts("No se pudo calcular el precio final con descuento para LATAM.\n");
					}
					if(!respuestaInteresLatam){
						printf("b) Precio con tarjeta de crédito: $%.2f.\n", precioLatamInteres);
					}
					else{
						puts("No se pudo calcular el precio final con interes para LATAM.\n");
					}
					if(!respuestaBitcoinLatam){
						printf("c) Precio pagando con bitcoin: %.2f BTC.\n", precioLatamBitcoin);
					}
					else{
						puts("No se pudo calcular el precio de LATAM pagando con bitcoin.\n");
					}
					if(!respuestaUnitarioLatam){
						printf("d) Precio unitario: $%.2f.\n\n", precioLatamUnitario);
					}
					else{
						puts("No se pudo calcular el precio unitario para LATAM.\n\n");
					}
					if(respuestaDiferenciaPrecios==1){
						printf("La diferencia de precio es: $%.2f.\n\n", diferenciaPrecios);
					}
					else if(respuestaDiferenciaPrecios==0){
						puts("Ambos precios son iguales.\n\n");
					}
					else {
						puts("No se pudo calcular la diferencia entre los precios ingresados.\n\n\n");
					}
					puts("*Luego de mostrar los resultados se reiniciarán todos los valores.\n\n\n");
					kilometrosIngresados=0;
					precioLatamIngresado=0;
					precioAerolineasIngresado=0;
					precioLatamDescuento=0;
					precioLatamInteres=0;
					precioLatamBitcoin=0;
					precioLatamUnitario=0;
					precioAerolineasDescuento=0;
					precioAerolineasInteres=0;
					precioAerolineasBitcoin=0;
					precioAerolineasUnitario=0;
					diferenciaPrecios=0;
					flagKilometros=1;
					flagAerolineas=1;
					flagLatam=1;
					flagCalculos=1;
					flagReingresos=1;
				}
				break;
			case 5:
				if(!flagKilometros)
				{
					puts("Ya hay otra operatoria en proceso, espere a que termine para poder mostrar los datos hardcodeades:\n\n\n");
				}
				else{
					kilometrosIngresados=7090;
					precioAerolineasIngresado=162965;
					precioLatamIngresado=159339;
					puts("Datos forzados:\n");
					printf("KMs ingresados: %.2f\n\n", kilometrosIngresados);
					printf("Aerolineas: %.2f\n", precioAerolineasIngresado);
					if(!calcularDescuento(&precioAerolineasDescuento, precioAerolineasIngresado, DESCUENTO)){
						printf("a) Precio con tarjeta de débito: $%.2f\n", precioAerolineasDescuento);
					}
					else{
						puts("No se pudo calcular el precio final con descuento para Aerolineas.\n");
					}
					if(!calcularInteres(&precioAerolineasInteres, precioAerolineasIngresado, INTERES)){
						printf("b) Precio con tarjeta de crédito: $%.2f\n", precioAerolineasInteres);
					}
					else{
						puts("No se pudo calcular el precio final con interes para Aerolineas.\n");
					}
					if(!dividir(&precioAerolineasBitcoin, precioAerolineasIngresado, BITCOIN_PRECIO)){
						printf("c) Precio pagando con bitcoin: %.2f BTC\n", precioAerolineasBitcoin);
					}
					else{
						puts("No se pudo calcular el precio de Aerolineas pagando con bitcoin.\n");
					}
					if(!dividir(&precioAerolineasUnitario, precioAerolineasIngresado, kilometrosIngresados)){
						printf("d) Precio unitario: $%.2f\n\n", precioAerolineasUnitario);
					}
					else{
						puts("No se pudo calcular el precio unitario para Aerolineas.\n\n");
					}
					printf("Latam: %.2f\n",precioLatamIngresado);
					if(!calcularDescuento(&precioLatamDescuento, precioLatamIngresado, DESCUENTO)){
						printf("a) Precio con tarjeta de débito: $%.2f\n", precioLatamDescuento);
					}
					else{
						puts("No se pudo calcular el precio final con descuento para LATAM.\n");
					}
					if(!calcularInteres(&precioLatamInteres, precioLatamIngresado, INTERES)){
						printf("b) Precio con tarjeta de crédito: $%.2f\n", precioLatamInteres);
					}
					else{
						puts("No se pudo calcular el precio final con interes para LATAM.\n");
					}
					if(!dividir(&precioLatamBitcoin, precioLatamIngresado, BITCOIN_PRECIO)){
						printf("c) Precio pagando con bitcoin: %.2f BTC\n", precioLatamBitcoin);
					}
					else{
						puts("No se pudo calcular el precio de LATAM pagando con bitcoin.\n");
					}
					if(!dividir(&precioLatamUnitario, precioLatamIngresado, kilometrosIngresados)){
						printf("d) Precio unitario: $%.2f\n\n", precioLatamUnitario);
					}
					else{
						puts("No se pudo calcular el precio unitario para LATAM.\n");
					}
					respuestaDiferenciaPreciosHardcodeado=calcularDiferenciaPrecios(&diferenciaPrecios, precioLatamIngresado, precioAerolineasIngresado);
					if(respuestaDiferenciaPreciosHardcodeado==1){
						printf("La diferencia de precio es: $%.2f\n\n\n\n", diferenciaPrecios);
					}
					else if(respuestaDiferenciaPreciosHardcodeado==0){
						puts("Ambos precios son iguales.\n\n\n\n");
					}
					else {
						puts("No se pudo calcular la diferencia entre los precios ingresados.\n\n\n");
					}
					kilometrosIngresados=0;
					precioLatamIngresado=0;
					precioAerolineasIngresado=0;
					precioLatamDescuento=0;
					precioLatamInteres=0;
					precioLatamBitcoin=0;
					precioLatamUnitario=0;
					precioAerolineasDescuento=0;
					precioAerolineasInteres=0;
					precioAerolineasBitcoin=0;
					precioAerolineasUnitario=0;
					diferenciaPrecios=0;
				}
				break;
			case 6:
				puts("Usted finalizó la operación.\n");
				retorno=0;
				break;
			}
		}
	}while(opcion!=6);
	return retorno;
}

int dividir(float* pResultado, float operandoUno, float operandoDos){
	int retorno=-1;
	float resultado;
	if(pResultado!=NULL && operandoDos!=0){
		resultado=operandoUno/operandoDos;
		*pResultado=resultado;
		retorno=0;
	}
	return retorno;
}

int calcularDescuento(float* pResultado, float precio, float descuento){
	int retorno=-1;
	float resultado;
	if(pResultado!=NULL && descuento>0){
		resultado=precio-(precio*descuento/100);
		*pResultado=resultado;
		retorno=0;
	}
	if(descuento==0){
		puts("No hay ningún descuento para aplicar.\n\n\n");
		retorno=-2;
	}
	return retorno;
}

int calcularInteres(float* pResultado, float precio, float interes){
	int retorno=-1;
	float resultado;
	if(pResultado!=NULL && interes>0){
		resultado=precio+(precio*interes/100);
		*pResultado=resultado;
		retorno=0;
	}
	if(interes==0){
		puts("No hay ningún interés para aplicar.\n\n\n");
	}
	return retorno;
}

int calcularDiferenciaPrecios(float* pResultado, float precioUno, float precioDos){
	int retorno=-1;
	float resultado;
	if(pResultado!=NULL){
		if(precioUno==precioDos){
			retorno=0;
		}
		else{
			retorno=1;
			if(precioUno>precioDos){
				resultado=precioUno-precioDos;
				*pResultado=resultado;
			}
			else{
				resultado=precioDos-precioUno;
				*pResultado=resultado;;
			}
		}
	}
	return retorno;
}
