#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char Productos[5][50] = {"Teclado", "Mouse", "Monitor", "CPU", "Auriculares"};
    float TiempoYPrecio[2][5] = {{10, 5, 15, 20, 8}, {50, 25, 150, 500, 80}};
    float tiempoRestante = 500;  // Tiempo disponible en minutos
    float dineroRestante = 1000; // Presupuesto disponible en dinero
    Menu(Productos, TiempoYPrecio, &tiempoRestante, &dineroRestante);
    return 0;
}