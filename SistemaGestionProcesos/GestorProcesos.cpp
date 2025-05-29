#include "GestorProcesos.h"
#include "PlanificadorCPU.h"

Proceso* listaProcesos = NULL;

void insertarProceso() {
    int id, prioridad;
    string nombre;
    cout << "ID: "; cin >> id;
    cout << "Nombre: "; cin >> nombre;
    cout << "Prioridad: "; cin >> prioridad;

    Proceso* nuevo = new Proceso{id, nombre, prioridad, NULL};
    if (listaProcesos == NULL) listaProcesos = nuevo;
    else {
        Proceso* temp = listaProcesos;
        while (temp->siguiente != NULL) temp = temp->siguiente;
        temp->siguiente = nuevo;
    }
    cout << "Proceso insertado.\n";
}

void mostrarProcesos() {
    Proceso* temp = listaProcesos;
    cout << "\n--- Lista de Procesos ---\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Nombre: " << temp->nombre << ", Prioridad: " << temp->prioridad << endl;
        temp = temp->siguiente;
    }
}

Proceso* buscarProcesoPorID(int id) {
    Proceso* temp = listaProcesos;
    while (temp != NULL && temp->id != id) temp = temp->siguiente;
    return temp;
}

void encolarDesdeLista() {
    int id;
    cout << "ID del proceso a encolar: "; cin >> id;
    Proceso* p = buscarProcesoPorID(id);
    if (p != NULL) encolar(*p);
    else cout << "Proceso no encontrado.\n";
}