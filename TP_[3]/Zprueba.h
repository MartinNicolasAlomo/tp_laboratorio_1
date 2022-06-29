#ifndef ZPRUEBA_H_
#define ZPRUEBA_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Input.h"
#include "parser.h"
#include "Validations.h"


int Prueba_ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

#endif /* ZPRUEBA_H_ */
