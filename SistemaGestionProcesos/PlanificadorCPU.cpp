#include <iostream>
#include "PlanificadorCPU.h"
using namespace std;

NodoCola* frente = NULL;

void encolar(Proceso p) {
    NodoCola* nuevo = new NodoCola{p, NULL};
    if (frente == NULL || p.prioridad > frente->proceso.prioridad) {
        nuevo->siguiente = frente;
        frente = nuevo;
    } else {
        NodoCola* temp = frente;
        while (temp->siguiente != NULL && temp->siguiente->proceso.prioridad >= p.prioridad)
            temp = temp->siguiente;
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }
    cout << "Proceso encolado según prioridad.\n";
}

void ejecutarProceso() {
    if (frente == NULL) {
        cout << "No hay procesos en la cola.\n";
        return;
    }
    cout << "Ejecutando proceso: " << frente->proceso.nombre << endl;
    NodoCola* temp = frente;
    frente = frente->siguiente;
    delete temp;
}

void mostrarCola() {
    NodoCola* temp = frente;
    cout << "\n--- Cola de Ejecución ---\n";
    while (temp != NULL) {
        cout << "ID: " << temp->proceso.id << ", Nombre: " << temp->proceso.nombre << ", Prioridad: " << temp->proceso.prioridad << endl;
        temp = temp->siguiente;
    }
}