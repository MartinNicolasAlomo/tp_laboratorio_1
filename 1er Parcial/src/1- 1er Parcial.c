/*					Martin Alomo - 1F

										1er Parcial de Laboratorio 1  -  1er Cuatrimestre, 2022
*/

//					Martin Alomo - 1F	1er Parcial de Laboratorio 1  -  1er Cuatrimestre, 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Album.h"
#include "Input.h"
#include "Validations.h"
#include "Listings.h"
#include "Reports.h"

int main(void){
	setbuf(stdout, NULL);
	if(!album_menuPrincipal()){
		puts("Finalizó el programa.");
	}
	else{
		puts("Se cerró el programa de forma errónea.");
	}
	return EXIT_SUCCESS;
}
