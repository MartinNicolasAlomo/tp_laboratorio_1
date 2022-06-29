#include "Zprueba.h"


int Prueba_ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
    int returnAux =-1;
    void* pUno=NULL;
    void* pDos=NULL;
    int nuevoLargo;
    int i;
    int criterio;
	int flagSwap=1;
    if(this!=NULL && pFunc!=NULL && (order==0 || order==1)){
    	nuevoLargo=ll_len(this)-1;
		do{
			flagSwap=0;
			for(i=0;i<nuevoLargo;i++){
				pUno=ll_get(this, i);
				pDos=ll_get(this, i+1);
				criterio=pFunc(pUno,pDos);
				if((order==1 && criterio==1) || (order==0 && criterio==-1)){
					ll_set(this, i, pDos);
					ll_set(this, i+1, pUno);
					flagSwap=1;
				}
			}
			nuevoLargo--;
		}while(flagSwap);
    	returnAux=0;
    }
    return returnAux;
}
