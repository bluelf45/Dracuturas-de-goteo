#ifndef TDA_LISTA_H
#define TDA_LISTA_H
typedef struct nodo {
    int data1;//inicio
    int data2;//final
    struct nodo* next;
} tNodo;
//lista1 memoria disponible
//lista2 memoria usada
typedef struct {
    tNodo* head;
    tNodo* tail;
    tNodo* curr;
    unsigned int listSize;
    unsigned int pos;
} tLista;

int move_next(tLista* lista);

int  contarBytes (tLista* lista);

void initList(tLista* lista);

void initNodo(tNodo* nodo, int dato1, int dato2);

void anterior(tLista* lista);

void push(tLista* lista,int data1,int data2);

int insert_nodo(tLista*lista,tNodo* nodo);

tNodo* remove2(tLista* lista,int data1);

void printlista(tLista* lista);

void move_to_head(tLista* lista);

void move_to_tail(tLista* lista);

int limpieza(tNodo* head);

int clear(tLista* lista);

int search(tLista* lista, int dato);

void free2(tLista* listaD, tLista* listaU, int byte);

int malloc2(tLista* listaD, tLista* listaU, int bytesize);

int tamLista(tLista* lista);

int bytesLib(tLista* lista);

#endif
