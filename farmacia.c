//Una farmacia necesita registrar la información de 5 medicamentos.//
//Por cada medicamento se debe guardar://
//Su nombre//
//Su precio//
//La cantidad disponible//
//El programa debe mostrar al final://
//Cuántos medicamentos tienen menos de 10 unidades.//
//El valor total del inventario (precio × cantidad).//
//Además, debe indicar si el inventario total supera los 1000 dólares.//
#include <stdio.h>
#include <string.h>

int main() {
    const int NUM_MEDICAMENTOS = 5;
    char nombres[NUM_MEDICAMENTOS][50];
    float precios[NUM_MEDICAMENTOS];
    int cantidades[NUM_MEDICAMENTOS];
    int menosDeDiez = 0;
    float totalInventario = 0;

    // Registro de medicamentos
    for (int i = 0; i < NUM_MEDICAMENTOS; i++) {
        printf("\nMedicamento %d:\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", nombres[i]); // Leer cadena con espacios

        printf("Precio: ");
        scanf("%f", &precios[i]);

        printf("Cantidad disponible: ");
        scanf("%d", &cantidades[i]);

        // Contar medicamentos con menos de 10 unidades
        if (cantidades[i] < 10) {
            menosDeDiez++;
        }

        // Calcular valor total del inventario
        totalInventario += precios[i] * cantidades[i];
    }

    // Resultados
    printf("\n📦 Medicamentos con menos de 10 unidades: %d\n", menosDeDiez);
    printf("💰 Valor total del inventario: $%.2f\n", totalInventario);

    if (totalInventario > 1000) {
        printf("✅ El inventario supera los $1000.\n");
    } else {
        printf("ℹ️ El inventario no supera los $1000.\n");
    }

    return 0;
}
