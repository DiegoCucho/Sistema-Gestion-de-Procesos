#ifndef PLANIFICADOR_CPU_H
#define PLANIFICADOR_CPU_H
#include "GestorProcesos.h"

struct NodoCola {
    Proceso proceso;
    NodoCola* siguiente;
};

extern NodoCola* frente;

void encolar(Proceso p);
void ejecutarProceso();
void mostrarCola();

#endif