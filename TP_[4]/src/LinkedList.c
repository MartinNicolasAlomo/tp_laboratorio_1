#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);



/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){
    LinkedList* this= NULL;
	this=(LinkedList*)malloc(sizeof(LinkedList));
	if(this!=NULL){
	this->size=0;
	}
    return this;
}


/** \brief Retorna la cantidad de elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 */
int ll_len(LinkedList* this){
    int returnAux = -1;
    if(this!=NULL){
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 */
static Node* getNode(LinkedList* this, int nodeIndex){
	Node* pAuxiliar=NULL;
	int i;
    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this)){
    	pAuxiliar=this->pFirstNode;
    	for(i=0;i<nodeIndex;i++){
    		pAuxiliar=pAuxiliar->pNextNode;
    	}
    }
    return pAuxiliar;
}






//						NO TOCAR			NO TOCAR			NO TOCAR			NO TOCAR			NO TOCAR			 NO TOCAR
//***********************************************************************************************************************************************************************

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

//***********************************************************************************************************************************************************************
//							NO TOCAR			NO TOCAR			NO TOCAR			NO TOCAR			NO TOCAR			 NO TOCAR








/** \brief Agrega y enlaza un nuevo nodo a la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int returnAux = -1;
    Node* pNuevo=NULL;
    Node* pAuxiliar=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this)){
    	pNuevo=(Node*)malloc(sizeof(Node));
    	if(pNuevo!=NULL){
    		pNuevo->pElement=pElement;
    		if(nodeIndex==0){
    			pNuevo->pNextNode = this->pFirstNode;
    			this->pFirstNode = pNuevo;
    		}
    		else{
    			pAuxiliar=getNode(this, nodeIndex-1);
    			if(pAuxiliar!=NULL){
        			pNuevo->pNextNode = pAuxiliar->pNextNode;
        			pAuxiliar->pNextNode = pNuevo;
    			}
    		}
    		this->size++;
    		returnAux=0;
    	}
    }
    return returnAux;
}






//							NO TOCAR			NO TOCAR			NO TOCAR			NO TOCAR			NO TOCAR			 NO TOCAR
//***********************************************************************************************************************************************************************

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

//***********************************************************************************************************************************************************************
//							NO TOCAR			NO TOCAR			NO TOCAR			NO TOCAR			NO TOCAR			 NO TOCAR







/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;
    if(this!=NULL){
    	if(!addNode(this, ll_len(this), pElement)){
    		returnAux=0;
    	}
    }
    return returnAux;
}




/** \brief Permite realizar el test de la funcion addNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index){
    void* returnAux = NULL;
    Node* pAuxiliar=NULL;

    if(this!=NULL && index>=0 && index<=ll_len(this)){
    	pAuxiliar=getNode(this, index);
    	if(pAuxiliar!=NULL){
        	returnAux=pAuxiliar->pElement;
    	}
    }
    return returnAux;
}



/** \brief Modifica un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_set(LinkedList* this, int index,void* pElement){
    int returnAux = -1;
    Node* pAuxiliar=NULL;

    if(this!=NULL && index>=0 && index<=ll_len(this)){
    	pAuxiliar=getNode(this, index);
    	if(pAuxiliar!=NULL){
			pAuxiliar->pElement = pElement;
        	returnAux=0;
    	}
    }
    return returnAux;
}



/** \brief Elimina un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_remove(LinkedList* this,int index){
    int returnAux = -1;
    Node* pAuxiliar=NULL;
    Node* pPrevio=NULL;

    if(this!=NULL && index>=0 && index<=ll_len(this)){
    	pAuxiliar=getNode(this, index);
    	if(pAuxiliar!=NULL){
    		if(index==0){
    			this->pFirstNode = pAuxiliar->pNextNode;
    		}
    		else{
    			pPrevio=getNode(this, index-1);
    			if(pPrevio!=NULL){
        			pPrevio->pNextNode = pAuxiliar->pNextNode;
    			}
    		}
    		free(pAuxiliar);
    		this->size--;
    		returnAux=0;

    		//	if(this->pFirstNode==NULL){		FIN DE LA LISTA
    	}
    }
    return returnAux;
}



/** \brief Elimina todos los elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_clear(LinkedList* this){
    int returnAux = -1;
    int i;
    if(this!=NULL){
    	for(i=0;i<ll_len(this);i++){
    		if(!ll_remove(this, i)){
    	    	returnAux=0;
    		}
    		else{
    			break;
    		}
    	}
    }
    return returnAux;
}



/** \brief Elimina todos los elementos de la lista y la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_deleteLinkedList(LinkedList* this){
    int returnAux = -1;
	if(this!=NULL){
		if(!ll_clear(this)){
			free(this);
			returnAux=0;
		}
	}
    return returnAux;
}



/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 */
int ll_indexOf(LinkedList* this, void* pElement){
    int returnAux = -1;
    void* pAuxiliar;
    int i;

    if(this!=NULL && pElement!=NULL){
		for(i=0;i<ll_len(this);i++){
			pAuxiliar=ll_get(this, i);
			if(pAuxiliar!=NULL && pAuxiliar==pElement){
		       	returnAux=i;
		       	break;
			}
		}
    }
    return returnAux;
}



/** \brief Indica si la lista esta o no vacia
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 */
int ll_isEmpty(LinkedList* this){
    int returnAux = -1;

    if(this!=NULL){
		if(!ll_len(this)){
	       	returnAux=1;
		}
		else{
	       	returnAux=0;
		}
    }
    return returnAux;
}



/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_push(LinkedList* this, int index, void* pElement){
    int returnAux = -1;

    if(this!=NULL && index>=0 && index<=ll_len(this) && pElement!=NULL){
    	if(!addNode(this, index, pElement)){
    		returnAux=0;
    	}
    }
    return returnAux;
}



/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 */
void* ll_pop(LinkedList* this,int index){
    void* returnAux = NULL;
    void* pAuxiliar=NULL;

    if(this!=NULL && index>=0 && index<=ll_len(this)){
    	pAuxiliar=ll_get(this, index);
    	if(pAuxiliar!=NULL){
        	if(!ll_remove(this, index)){
        		returnAux=pAuxiliar;
        	}
    	}
    }
    return returnAux;
}



/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement){
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL){
		if(ll_indexOf(this, pElement)!=-1){
			returnAux=1;
		}
		else{
			returnAux=0;
		}
    }
    return returnAux;
}



/** \brief  Determina si todos los elementos de la lista (this2) estan contenidos en la lista (this)
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2){
    int returnAux = -1;
    void* pAuxiliar=NULL;
    int i;

    if(this!=NULL && this2!=NULL){
    	for(i=0;i<ll_len(this2);i++){
    		pAuxiliar=ll_get(this2, i);
        	if(pAuxiliar!=NULL && ll_contains(this, pAuxiliar)==1){
        		returnAux=1;
        	}
        	else{
        		returnAux=0;
        		break;
        	}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0, o mayor al len de la lista)
                                o (si el indice to es menor o igual a from, o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to){
    LinkedList* cloneArray = NULL;
    void* pElement;
    int i;
    if(this!=NULL && from>=0 && from<=ll_len(this) && to>from && to<=ll_len(this)){
    	cloneArray=ll_newLinkedList();
    	if(cloneArray!=NULL){
    		for(i=from;i<to;i++){
        		pElement=ll_get(this, i);
        		if(pElement!=NULL){
        			ll_add(cloneArray, pElement);
        		}
    		}
    	}
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this){
    LinkedList* cloneArray = NULL;
    if(this!=NULL){
    	cloneArray=ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}



/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
    int returnAux =-1;
    void* pUno=NULL;
    void* pDos=NULL;
    void* pAux=NULL;
    int nuevoLargo;
    int i;
    int largo;
	int flagSwap;
    if(this!=NULL && pFunc!=NULL){
    	largo=ll_len(this);
    	if(largo>=2){
    		nuevoLargo = largo - 1;
    		/*if(pFunc(pUno,pDos)<0 && order==0){
    			do{
    				flagSwap=0;
    				for(i=0;i<nuevoLargo;i++){
    					pUno=ll_get(this, i);
    					pDos=ll_get(this, i);
    					if(pFunc(pUno,pDos)<0){
    						flagSwap=1;
    						pAux=pDos;
    						ll_set(this, i, pUno);
    						ll_set(this, i, pAux);
    					}
    				}
    				nuevoLargo--;
    			}while(flagSwap);
    		}
    		else if(pFunc(pUno,pDos)>0 && order==1){
    			do{
    				flagSwap=0;
    				for(i=0;i<nuevoLargo;i++){
    					pUno=ll_get(this, i);
    					pDos=ll_get(this, i);
    					if(pFunc(pUno,pDos)<0){
    						flagSwap=1;
    						pAux=pDos;
    						ll_set(this, i, pUno);
    						ll_set(this, i, pAux);
    					}
    				}
    				nuevoLargo--;
    			}while(flagSwap);
    		}*/
    		returnAux = 0;
    	}
    	returnAux = 0;
    }
    return returnAux;
}
