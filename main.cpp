#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    string accion;
    Nodo* siguiente;
};

void push(Nodo*& pila, string accion) {
    Nodo* nuevo = new Nodo();

    nuevo->accion = accion;
    nuevo->siguiente = pila;

    pila = nuevo;
}

bool pop(Nodo*& pila, string& accion) {

    if (pila == nullptr) {
        return false;
    }

    Nodo* temp = pila;

    accion = pila->accion;
    pila = pila->siguiente;

    delete temp;
    temp = nullptr;

    return true;
}

void mostrar(Nodo* pila) {

    if (pila == nullptr) {
        cout << "La pila esta vacia.\n";
        return;
    }

    cout << "----- CONTENIDO DE LA PILA -----\n";

    Nodo* aux = pila;

    while (aux != nullptr) {
        cout << "- " << aux->accion << endl;
        aux = aux->siguiente;
    }
}

void limpiarPila(Nodo*& pila) {

    string basura;

    while (pila != nullptr) {
        pop(pila, basura);
    }
}

int main() {

    Nodo* pilaAcciones = nullptr;
    Nodo* pilaRedo = nullptr;

    int opcion;
    string accion;

    do {

        cout << "\n=====================================\n";
        cout << "   SIMULADOR UNDO / REDO\n";
        cout << "   Nombre: Sebastian Rodas\n";
        cout << "=====================================\n";

        cout << "1. Realizar accion\n";
        cout << "2. Deshacer ultima accion\n";
        cout << "3. Rehacer accion\n";
        cout << "4. Mostrar acciones actuales\n";
        cout << "5. Mostrar pila de rehacer\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                cout << "Ingrese la accion: ";
                cin>>accion;

                push(pilaAcciones, accion);

                limpiarPila(pilaRedo);

                cout << "Accion realizada correctamente.\n";

                break;

            case 2:

                if (pop(pilaAcciones, accion)) {

                    push(pilaRedo, accion);

                    cout << "Accion deshecha: "
                         << accion << endl;
                }
                else {
                    cout << "No hay acciones para deshacer.\n";
                }

                break;

            case 3:

                if (pop(pilaRedo, accion)) {

                    push(pilaAcciones, accion);

                    cout << "Accion rehecha: "
                         << accion << endl;
                }
                else {
                    cout << "No hay acciones para rehacer.\n";
                }

                break;

            case 4:

                cout << "\nACCIONES ACTUALES:\n";
                mostrar(pilaAcciones);

                break;

            case 5:

                cout << "\nPILA DE REHACER:\n";
                mostrar(pilaRedo);

                break;

            case 6:

                cout << "Saliendo del programa...\n";

                break;

            default:

                cout << "Opcion invalida.\n";
        }

    } while(opcion != 6);

    limpiarPila(pilaAcciones);
    limpiarPila(pilaRedo);

    return 0;
}
