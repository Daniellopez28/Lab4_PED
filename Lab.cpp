#include <iostream>
using namespace std;

struct Nodo
{
    int id;
    string nombre;
    float peso;
    Nodo *siguiente;
    Nodo *anterior;
};

// Indicacion 2:
Nodo *cabeza = NULL;
Nodo *cola = NULL;

// Funciones:

bool insertarOrdenado(Nodo *&cabeza, Nodo *&cola, int id, string nombre, float peso) // Punto extra, literal A:
{

    Nodo *aux = cabeza;
    while (aux != NULL)
    {
        if (aux->id == id)
            return false;
        aux = aux->siguiente;
    }
    Nodo *nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    if (cabeza == NULL)
    {
        cabeza = cola = nuevo;
        return true;
    }

    if (id < cabeza->id)
    {
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
        cabeza = nuevo;
        return true;
    }

    // Para insertar en medio o al final...

    aux = cabeza;
    while (aux->siguiente != NULL && aux->siguiente->id < id)
    {
        aux = aux->siguiente;
    }

    nuevo->siguiente = aux->siguiente;
    nuevo->anterior = aux;

    if (aux->siguiente != NULL)
        aux->siguiente->anterior = nuevo;
    else
    {
        cola = nuevo;
        aux->siguiente = nuevo;
        return true;
    }
}

// Para mostrar adelante, continuacion de funciones:

void mostrarAdelante(Nodo *cabeza)
{
    if (cabeza == NULL)
    {
        cout << "Lista vacia" << endl;
        return;
    }
    Nodo *aux = cabeza;
    while (aux != NULL)
    {
        cout << "ID: " << aux->id
             << "  Nombre: " << aux->nombre
             << "  Peso: " << aux->peso << endl;
        aux = aux->siguiente;
    }
}

void mostrarAtras(Nodo *cola)
{
    if (cola == NULL)
    {
        cout << "Lista vacia." << endl;
        return;
    }

    Nodo *aux = cola;
    while (aux != NULL)
    {
        cout << "ID: " << aux->id
             << " Nombre: " << aux->nombre
             << " Peso: " << aux->peso << endl;
        aux = aux->anterior;
    }
}

// Para buscar por el id

bool buscar(Nodo *cabeza, int id)
{
    Nodo *aux = cabeza;
    while (aux != NULL)
    {
        if (aux->id == id)
            return true;
        aux = aux->siguiente;
    }
    return false;
}

// funcion para eliminar por id

bool eliminar(Nodo *&cabeza, Nodo *&cola, int id)
{

    if (cabeza == NULL)
        return false;

    Nodo *aux = cabeza;

    while (aux != NULL)
    {
        if (aux->id == id)
        {

            // Caso 1: eliminar cabeza
            if (aux == cabeza)
            {
                cabeza = cabeza->siguiente;
                if (cabeza != NULL)
                    cabeza->anterior = NULL;
                else
                    cola = NULL;
            }
            else if (aux == cola)
            {
                cola = cola->anterior;
                cola->siguiente = NULL;
            }
            else
            {
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;
            }

            delete aux;
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
};
