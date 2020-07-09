#include<stdio.h>
#include<stdlib.h>
#include "TDArbol.h"
int i;
/*****
* void initArbol
******
* inicia un arbol vacio
******
* Input:
* arbolBin* arbol : puntero a un arbolBin para iniciar.
* .......
******
* Returns:
* nada, es void
*****/
void initArbol(arbolBin* arbol){
    arbol->raiz=NULL;
    arbol->nElems=0;
}
/*****
* void initNodo
******
* inicia un nodo con dato el item dado
******
* Input:
* tNodo* nodo : puntero al nodo a inciar;
*int item : dato que quieres que tenga el nodo
* .......
******
* Returns:
* nada, es void
*****/

void initNodo(tNodo* nodo, int item){
    nodo->left=nodo->right=NULL;
    nodo->dato=item;
}
/*****
* void clearHelp
******
* funcion usada para liberar un arbol entero, es usada para ayudar clear
******
* Input:
* tNodo* nodo : primero es la raiz del arbol y funciona recursivamente liberando todos los nodos
* .......
******
* Returns:
* nada, es void
*****/
void clearHelp(tNodo* nodo){
    if(nodo==NULL){
        return;
    }
    clearHelp(nodo->left);
    clearHelp(nodo->right);
    free(nodo);
}
/*****
* void clear
******
* liberar un arbol dado
******
* Input:
* arbolBin* arbol : arbol para liberar/limpiar
* .......
******
* Returns:
* nada, es void
*****/
void clear(arbolBin* arbol){
    if (arbol->raiz==NULL){
        return;
    }
    clearHelp(arbol->raiz);
    arbol->raiz=NULL;
    arbol->nElems=0;
}
/*****
* 
******
* 
******
* Input:
* 
* .......
******
* Returns:
* 
*****/
tNodo* encontrarMax(tNodo* nodo){
    while(nodo->right != NULL){
        nodo = nodo->right;
    }
    return nodo;
}
/*****
* void borrarHelp
******
* ayuda a encontrar el nodo deseado en borrar y lo remueve del arbol
******
* Input:
* tNodo* nodo : primero es la raiz del arbol, luego es recursiva tomando todos los nodos hasta encontrar el nodo deseado
* int item : dato del nodo a eliminar
* .......
******
* Returns:
* tNodo* :  nodo eliminado del arbol
*****/
tNodo* borrarHelp(tNodo* nodo, int item){
    if(nodo == NULL){
        return NULL;
    }
    if(item < nodo->dato){
        nodo->left = borrarHelp(nodo->left, item);
    }
    else if(item > nodo->dato){
        nodo->right = borrarHelp(nodo->right, item);
    }
    else{
        // 0 Hijos
        if(nodo->left == NULL && nodo->right == NULL){
            free(nodo);
            return NULL;
            }

        // 1 Hijo
        else if(nodo->right == NULL || nodo->left == NULL){
            tNodo* aux;
            if(nodo->left == NULL){
                aux = nodo->right;
            }
            else {
                aux = nodo->left;
            }
            free(nodo);
            return aux;
        // 2 hijos
        } else{
            tNodo* aux = encontrarMax(nodo->left);
            nodo->dato = aux->dato;
            nodo->left = borrarHelp(nodo->left, aux->dato);
        }
    }
    return nodo;
}
/*****
* int Borrar
******
* Borra cierto item del ABB arbol
******
* Input:
* arbolBin* arbol : el arbol al que le quieres borrar algo
* int item : item que deseas eliminar del arbol
* .......
******
* Returns:
* int: Retorna 0 si no se logro o 1 si se hizo correctamente.
*****/
int Borrar(arbolBin* arbol, int item){

    if(arbol->raiz == NULL){
        return 0;
    }
    else{
        borrarHelp(arbol->raiz, item);
        arbol->nElems--;
        return 1;
    }
}
/*****
* void sucesor
******
* 
******
* Input:
* 
* .......
******
* Returns:
* 
*****/
void Sucesor(arbolBin* arbol, int item, int u){
    i = 0;
    if(arbol->raiz!=NULL){
        if (encontrarMax(arbol->raiz)->dato < item){
            printf("%d \n", u);
        }
    }
    else{
        printf("%d \n", u);
    }
    sucesorHelp(arbol->raiz, item);
}
/*****
* int move_next
******
* mueve lista->curr a la siguiente posicion, es decr, al siguiente nodo en la lista dada.
******
* Input:
* tLista* lista : Lista que queremos cambiar de posicion.
* .......
******
* Returns:
* int: Retorna 0 si no se logro, o si esta en la cabeza de la lista. Sino retorna 1 diciendo que se hizo correctamente.
*****/
void sucesorHelp(tNodo* nodo, int item){
    if (nodo == NULL){
        return;
    }
    sucesorHelp(nodo->left, item);
    if (nodo->dato > item && i == 0){
        printf ( "%d \n", nodo->dato);
        i = -1;
        return;
    }
    sucesorHelp(nodo->right, item);

}
/*****
* insertHelp
******
* funcion recursiva
******
* Input:
* tNodo* nodo : primero es la raiz del arbol, se usa para poder encontrar donde insertar el nodo
* int item : item del nodo a insertar
* .......
******
* Returns:
* int  : 1 si se logro y 0 si no se pudo
*****/
int insertHelp(tNodo* nodo, int item){
    if(nodo->dato==item){
        return 0;
    }
    else if(nodo->dato < item){
        if(nodo->right==NULL){
            tNodo* NewNode=(tNodo*)malloc(sizeof(tNodo));
            initNodo(NewNode, item);
            nodo->right=NewNode;
            return 1;
        }
        else{
            insertHelp(nodo->right, item);
        }
    }
    else if(nodo->dato > item){
        if(nodo->left==NULL){
            tNodo* NewNode=(tNodo*)malloc(sizeof(tNodo));
            initNodo(NewNode, item);
            nodo->left=NewNode;
            return 1;
        }
        else{
            insertHelp(nodo->left, item);
        }
    }
    return 0;
}
/*****
* int move_next
******
* funcion que usa insertHelp para poder insertar un nodo en el arbol
******
* Input:
* arbolBin* arbol : arbol al que le quieres insertar un nodo
* int item : item del nodo que quieres insertar
* .......
******
* Returns:
* void no retorna
*****/
void insertar(arbolBin* arbol, int item){
    if(arbol->raiz==NULL){
        tNodo* NewNode=(tNodo*)malloc(sizeof(tNodo));
        initNodo(NewNode, item);
        arbol->raiz=NewNode;
    }
    else if(insertHelp(arbol->raiz,item)==1){
        arbol->nElems++;
    }
}
/*****
* void printPreNodo
******
* funcion recursiva para printear el arbon en preorden
******
* Input:
* tNodo* nodo : funcion recursiva, primer nodo es la raiz
* .......
******
* Returns:
* vacio
*****/
void printPreNodo(tNodo* nodo){
    if(nodo==NULL){
        return;
    }
    printf("%d ",nodo->dato);
    printPreNodo(nodo->left);
    printPreNodo(nodo->right);
}
/*****
* void preorden
******
* printear un arbol en preorden
******
* Input:
* arbolBin* arbol : arbol a printear
* .......
******
* Returns:
* void
*****/
void preorden(arbolBin* arbol){
    printPreNodo(arbol->raiz);
    printf("\n");
}
