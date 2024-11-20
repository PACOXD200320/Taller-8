#include <stdio.h>
#include <string.h>
#include "funciones.h"

void Menu(char Productos[5][50], float TiempoYPrecio[2][5], float *tiempoRestante, float *dineroRestante) {
    int opciones;

    do {
        printf("\n======================\n");
        printf("  MENU DE LA EMPRESA\n");
        printf("======================\n");
        printf("Tiempo restante: %.2f minutos\n", *tiempoRestante);
        printf("Dinero restante: %.2f\n", *dineroRestante);
        printf("\nSeleccione una opcion:\n");
        printf(" 1. Cambiar Producto\n");
        printf(" 2. Cambiar Precio\n");
        printf(" 3. Cambiar Tiempo\n");
        printf(" 4. Lista de Productos\n");
        printf(" 5. Eliminar Producto\n");
        printf(" 6. Realizar Pedido\n");
        printf(" 0. Salir\n");
        printf("======================\n");
        printf("Opcion: ");
        scanf("%d", &opciones);

        switch (opciones) {
            case 1: CambiarProducto(Productos, TiempoYPrecio); break;
            case 2: CambiarPrecio(Productos, TiempoYPrecio); break;
            case 3: CambiarTiempo(Productos, TiempoYPrecio); break;
            case 4: ListadoProductos(Productos, TiempoYPrecio); break;
            case 5: EliminarProducto(Productos, TiempoYPrecio); break;
            case 6: RealizarPedido(Productos, TiempoYPrecio, tiempoRestante, dineroRestante); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opción invalida.\n");
        }
    } while (opciones != 0);
}

void ListadoProductos(char Productos[5][50], float TiempoYPrecio[2][5]) {
    printf("\n--- Listado de Productos ---\n");
    for (int i = 0; i < 5; i++) {
        if (strcmp(Productos[i], "") != 0) {
            printf("%d. %s - Tiempo: %.2f min, Precio: %.2f\n", i + 1, Productos[i], TiempoYPrecio[0][i], TiempoYPrecio[1][i]);
        }
    }
}

void CambiarProducto(char Productos[5][50], float TiempoYPrecio[2][5]) {
    ListadoProductos(Productos, TiempoYPrecio); // Mostrar listado actualizado
    int index;
    printf("\nIngrese el indice (1-5) del producto a cambiar: ");
    scanf("%d", &index);
    if (index < 1 || index > 5) {
        printf("indice invalido.\n");
        return;
    }
    index--;
    getchar(); // Limpiar buffer
    printf("Nuevo nombre del producto: ");
    fgets(Productos[index], 50, stdin);
    Productos[index][strcspn(Productos[index], "\n")] = '\0';
    printf("Nuevo tiempo de fabricacion: ");
    scanf("%f", &TiempoYPrecio[0][index]);
    printf("Nuevo precio: ");
    scanf("%f", &TiempoYPrecio[1][index]);
    printf("Producto actualizado.\n");
}

void CambiarPrecio(char Productos[5][50], float TiempoYPrecio[2][5]) {
    ListadoProductos(Productos, TiempoYPrecio); // Mostrar listado actualizado
    int index;
    printf("\nIngrese el indice (1-5) del producto para cambiar precio: ");
    scanf("%d", &index);
    if (index < 1 || index > 5) {
        printf("indice invalido.\n");
        return;
    }
    index--;
    printf("Nuevo precio: ");
    scanf("%f", &TiempoYPrecio[1][index]);
    printf("Precio actualizado.\n");
}

void CambiarTiempo(char Productos[5][50], float TiempoYPrecio[2][5]) {
    ListadoProductos(Productos, TiempoYPrecio); // Mostrar listado actualizado
    int index;
    printf("\nIngrese el indice (1-5) del producto para cambiar tiempo: ");
    scanf("%d", &index);
    if (index < 1 || index > 5) {
        printf("indice invalido.\n");
        return;
    }
    index--;
    printf("Nuevo tiempo de fabricacion: ");
    scanf("%f", &TiempoYPrecio[0][index]);
    printf("Tiempo actualizado.\n");
}

void EliminarProducto(char Productos[5][50], float TiempoYPrecio[2][5]) {
    ListadoProductos(Productos, TiempoYPrecio); // Mostrar listado actualizado
    int index;
    printf("\nIngrese el indice (1-5) del producto a eliminar: ");
    scanf("%d", &index);
    if (index < 1 || index > 5) {
        printf("indice invalido.\n");
        return;
    }
    index--;
    for (int i = index; i < 4; i++) {
        strcpy(Productos[i], Productos[i + 1]);
        TiempoYPrecio[0][i] = TiempoYPrecio[0][i + 1];
        TiempoYPrecio[1][i] = TiempoYPrecio[1][i + 1];
    }
    strcpy(Productos[4], "");
    TiempoYPrecio[0][4] = 0;
    TiempoYPrecio[1][4] = 0;
    printf("Producto eliminado.\n");
}

void RealizarPedido(char Productos[5][50], float TiempoYPrecio[2][5], float *tiempoRestante, float *dineroRestante) {
    int r, cantidad;
    float total = 0, tiempoUsado = 0;
    char continuar;

    do {
        ListadoProductos(Productos, TiempoYPrecio);

        do {
            printf("\nIngrese el numero del producto que desea pedir (1-5): ");
            scanf("%d", &r);
            if (r < 1 || r > 5 || strcmp(Productos[r - 1], "") == 0) {
                printf("Numero no valido o producto vacio.\n");
            }
        } while (r < 1 || r > 5 || strcmp(Productos[r - 1], "") == 0);

        r--;
        printf("Ingrese la cantidad: ");
        scanf("%d", &cantidad);

        float costoProducto = TiempoYPrecio[1][r] * cantidad;
        float tiempoProducto = TiempoYPrecio[0][r] * cantidad;

        if (costoProducto > *dineroRestante || tiempoProducto > *tiempoRestante) {
            printf("\nNo se puede realizar el pedido.\n");
            if (tiempoProducto > *tiempoRestante) {
                printf("Recomendacion: Reduzca la cantidad de %s a un maximo de %.0f unidades.\n", Productos[r], *tiempoRestante / TiempoYPrecio[0][r]);
            }
            if (costoProducto > *dineroRestante) {
                printf("Recomendacion: Reduzca la cantidad de %s a un maximo de %.0f unidades.\n", Productos[r], *dineroRestante / TiempoYPrecio[1][r]);
            }
            continue;
        }

        total += costoProducto;
        tiempoUsado += tiempoProducto;
        *dineroRestante -= costoProducto;
        *tiempoRestante -= tiempoProducto;

        printf("\nProducto añadido al pedido: %s, cantidad: %d, subtotal: %.2f\n", Productos[r], cantidad, costoProducto);

        printf("\n¿Desea agregar otro producto al pedido? (s/n): ");
        getchar();
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("\nPedido finalizado.\nTotal gastado: %.2f\nTiempo usado: %.2f minutos\n", total, tiempoUsado);
}