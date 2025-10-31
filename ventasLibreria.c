//Control de ventas en una librería//
//Una librería desea implementar un programa en C que le permita llevar el control de las// 
//ventas de sus 5 libros más vendidos. El sistema debe permitir registrar los datos de cada //
//libro, calcular el subtotal por venta y mostrar al final el total de dinero recaudado.//
//Requerimientos del programa//
//1. Para cada libro se debe ingresar://
//o ID del libro (número entero).//
//o Cantidad disponible en stock.//
//o Precio unitario.//
//o Cantidad vendida.//
//2. El programa debe validar que://
//o Todos los valores ingresados sean números válidos (no letras ni símbolos).//
//o Las cantidades ingresadas sean mayores o iguales a cero.//
//o La cantidad vendida no supere el stock disponible.//
//3. Si la cantidad vendida supera el stock, el programa debe mostrar un mensaje de //
//error y finalizar inmediatamente.//
//4. Si los datos son correctos, se debe calcular://
//o El subtotal de venta por cada libro (precio × cantidad vendida).//
//5. Al finalizar, el programa debe mostrar://
//o El subtotal de cada libro vendido.//
//o El total general recaudado por todas las ventas.//
#include <stdio.h>
#include <stdlib.h>

int main() {
    const int NUM_LIBROS = 5;
    int id[NUM_LIBROS];
    int stock[NUM_LIBROS];
    float precio[NUM_LIBROS];
    int vendidos[NUM_LIBROS];
    float subtotal[NUM_LIBROS];
    float totalRecaudado = 0;

    printf("📘 Registro de ventas de los 5 libros más vendidos\n");

    for (int i = 0; i < NUM_LIBROS; i++) {
        printf("\nLibro %d:\n", i + 1);

        // ID del libro
        printf("Ingrese el ID del libro: ");
        if (scanf("%d", &id[i]) != 1 || id[i] < 0) {
            printf("❌ Error: ID inválido.\n");
            return 1;
        }

        // Stock disponible
        printf("Ingrese la cantidad en stock: ");
        if (scanf("%d", &stock[i]) != 1 || stock[i] < 0) {
            printf("❌ Error: Stock inválido.\n");
            return 1;
        }

        // Precio unitario
        printf("Ingrese el precio unitario: ");
        if (scanf("%f", &precio[i]) != 1 || precio[i] < 0) {
            printf("❌ Error: Precio inválido.\n");
            return 1;
        }

        // Cantidad vendida
        printf("Ingrese la cantidad vendida: ");
        if (scanf("%d", &vendidos[i]) != 1 || vendidos[i] < 0) {
            printf("❌ Error: Cantidad vendida inválida.\n");
            return 1;
        }

        // Validar que no se vendan más libros de los que hay en stock
        if (vendidos[i] > stock[i]) {
            printf("❌ Error: La cantidad vendida supera el stock disponible.\n");
            return 1;
        }

        // Calcular subtotal
        subtotal[i] = precio[i] * vendidos[i];
        totalRecaudado += subtotal[i];
    }

    // Mostrar resultados
    printf("\n📊 Subtotales por libro:\n");
    for (int i = 0; i < NUM_LIBROS; i++) {
        printf("Libro ID %d: Subtotal = $%.2f\n", id[i], subtotal[i]);
    }

    printf("\n💰 Total recaudado por todas las ventas: $%.2f\n", totalRecaudado);

    return 0;
}
