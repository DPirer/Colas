#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

// PROTOTIPOS
void menu();
void insertarCola(Nodo *&, Nodo *&, int);
void borrarCola(Nodo *&, Nodo *&, int &);

// MAIN
int main()
{
    menu();

    return 0;
}

// FUNCIONES
void menu(){

    // Inicializamos los punteros frente y fin
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    int respuesta = 0, dato;

    while (respuesta != 3){
        cout<<"\t MENU\n";
        cout<<"1. Insertar un elemento en la cola"<<endl;
        cout<<"2. Mostrar los elementos de la cola"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>respuesta;

        switch (respuesta){
            case 1:
                cout<<"Introduzca un numero: ";
                cin>>dato;
                insertarCola(frente,fin,dato);
                break;

            case 2:
                cout<<"Los elementos de la cola son: ";

                while(frente != NULL){
                    borrarCola(frente,fin,dato);

                    if (frente != NULL){
                        cout<<dato<<", ";
                    }
                    else {
                        cout<<dato<<".\n";
                    }
                }
                system("pause");

            case 3:
                exit(1);
        }
        system("cls");
    }

}

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *nuevo_nodo = new Nodo();                      // Reservamos espacio en memoria para un nuevo nodo
    nuevo_nodo -> dato = n;                             // Metemos el dato en el nodo
    nuevo_nodo -> siguiente = NULL;                     // Y apuntamos siguiente a NULL
    if(frente == NULL){                                 // Si es el primer nodo, frente y fin avanzan
        frente = nuevo_nodo;
    }
    else{                                               // Si es otro nodo, frente se queda al principio y movemos fin
        fin -> siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
}

void borrarCola(Nodo *&frente, Nodo *&fin, int &n){
    n = frente -> dato;                                 // Obtenemos el dato que queremos borrar
    Nodo *aux = frente;                                 // Creamos una variable auxiliar
    if(frente == fin){                                  // Si estamos al final de la cola, frente y fin son null
        frente = NULL;
        fin = NULL;
    }
    else{                                               // Si no, avanzamos frente
        frente = frente -> siguiente;
    }
    delete aux;                                         // Y borramos la variable auxiliar para eliminar el nodo
}
