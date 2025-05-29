#include <iostream>
using namespace std;

struct BloqueMemoria {
    int idProceso;
    int tam;
    BloqueMemoria* siguiente;
};

BloqueMemoria* cima = NULL;

void asignarMemoria() {
    int id, tam;
    cout << "ID Proceso: "; cin >> id;
    cout << "Tamaño memoria: "; cin >> tam;
    BloqueMemoria* nuevo = new BloqueMemoria{id, tam, cima};
    cima = nuevo;
    cout << "Memoria asignada al proceso " << id << ".\n";
}

void liberarMemoria() {
    if (cima == NULL) {
        cout << "No hay bloques en la pila.\n";
        return;
    }
    cout << "Liberando memoria del proceso " << cima->idProceso << ".\n";
    BloqueMemoria* temp = cima;
    cima = cima->siguiente;
    delete temp;
}

void mostrarMemoria() {
    BloqueMemoria* temp = cima;
    cout << "\n--- Pila de Memoria ---\n";

    if (temp == NULL) {
        cout << "La memoria está vacía.\n";
        return;
    }

    while (temp != NULL) {
        Proceso* p = buscarProcesoPorID(temp->idProceso);
        if (p != NULL) {
            cout << "Proceso: " << p->nombre << " (ID: " << p->id << "), Tamaño: " << temp->tam << " KB\n";
        } else {
            cout << "Proceso desconocido (ID: " << temp->idProceso << "), Tamaño: " << temp->tam << " KB\n";
        }
        temp = temp->siguiente;
    }
}
