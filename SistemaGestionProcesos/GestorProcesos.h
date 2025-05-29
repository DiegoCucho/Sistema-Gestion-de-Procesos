#ifndef GESTOR_PROCESOS_H
#define GESTOR_PROCESOS_H
#include <iostream>
#include <string>
using namespace std;

struct Proceso {
    int id;
    string nombre;
    int prioridad;
    Proceso* siguiente;
};

extern Proceso* listaProcesos;

void insertarProceso();
void mostrarProcesos();
Proceso* buscarProcesoPorID(int id);
void encolarDesdeLista();

#endif