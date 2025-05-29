#include <iostream>
#include "GestorProcesos.h"
#include "PlanificadorCPU.h"
#include "GestorMemoria.h"
using namespace std;

void menu() {
    int opcion;
    do {
        cout << "\n--- Sistema de Gestión de Procesos ---\n";
        cout << "1. Insertar proceso\n2. Mostrar procesos\n3. Encolar proceso\n4. Ejecutar proceso\n";
        cout << "5. Mostrar cola\n6. Asignar memoria\n7. Liberar memoria\n8. Mostrar memoria\n0. Salir\nOpción: ";
        cin >> opcion;

        if (opcion == 1) insertarProceso();
        else if (opcion == 2) mostrarProcesos();
        else if (opcion == 3) encolarDesdeLista();
        else if (opcion == 4) ejecutarProceso();
        else if (opcion == 5) mostrarCola();
        else if (opcion == 6) asignarMemoria();
        else if (opcion == 7) liberarMemoria();
        else if (opcion == 8) mostrarMemoria();
    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}