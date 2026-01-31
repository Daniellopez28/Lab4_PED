#include <iostream>
using namespace std;

struct Nodo {
    int id;
    string nombre;
    float peso;
    Nodo* siguiente;
    Nodo* anterior;
};


Nodo* cabeza = NULL;
Nodo* cola = NULL;


bool insertarOrdenado(Nodo*& cabeza, Nodo*& cola, int id, string nombre, float peso) {

  
    Nodo* aux = cabeza;
    while (aux != NULL) {
        if (aux->id == id)
            return false; 
        aux = aux->siguiente;
    }

 
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    if (cabeza == NULL) {
       cabeza = cola = nuevo;
        return true;
    }

    if (id < cabeza->id) {
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
       cabeza = nuevo;
        return true;
    }

    
    aux = cabeza;
    while (aux->siguiente != NULL && aux->siguiente->id < id) {
        aux = aux->siguiente;
    }

    nuevo->siguiente = aux->siguiente;
    nuevo->anterior = aux;

    if (aux->siguiente != NULL)
        aux->siguiente->anterior = nuevo;
    else
        cola= nuevo; 

    aux->siguiente= nuevo;
    return true;
}
