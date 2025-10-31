//Una academia imparte varios cursos y necesita un programa en C que permita registrar cuántos estudiantes se han inscrito en cada curso,//
//calcular cuántos cupos quedan disponibles y cuánto dinero se ha recaudado en total. 🔹 Requisitos del programa: Pedir al usuario cuántos cursos ofrece la academia. //
//Para cada curso: Ingresar el número máximo de cupos. Ingresar el costo del curso. Ingresar cuántos estudiantes se han inscrito. Usar arreglos unidimensionales para guardar los datos de cada curso. //
//Si los inscritos no superan los cupos, mostrar://
//Cuántos cupos quedan. //
//Cuánto dinero se recaudó en ese curso.//
//Si los inscritos superan los cupos, mostrar un mensaje de error.//
//Al final, mostrar la recaudación total de todos los cursos.//
#include <stdio.h>

int main() {
    int numCursos;
    float totalRecaudado = 0;

    // Solicitar número de cursos
    printf("Ingrese el número de cursos que ofrece la academia: ");
    scanf("%d", &numCursos);

    // Declarar arreglos
    int cuposMaximos[numCursos];
    float costos[numCursos];
    int inscritos[numCursos];

    // Procesar cada curso
    for (int i = 0; i < numCursos; i++) {
        printf("\nCurso %d:\n", i + 1);

        // Ingresar datos
        printf("Ingrese el número máximo de cupos: ");
        scanf("%d", &cuposMaximos[i]);

        printf("Ingrese el costo del curso: ");
        scanf("%f", &costos[i]);

        printf("Ingrese el número de estudiantes inscritos: ");
        scanf("%d", &inscritos[i]);

        // Validar cupos
        if (inscritos[i] <= cuposMaximos[i]) {
            int cuposRestantes = cuposMaximos[i] - inscritos[i];
            float recaudado = inscritos[i] * costos[i];
            totalRecaudado += recaudado;

            printf("✅ Cupos disponibles: %d\n", cuposRestantes);
            printf("💰 Dinero recaudado en este curso: $%.2f\n", recaudado);
        } else {
            printf("❌ Error: Los inscritos superan el número de cupos disponibles.\n");
        }
    }

    // Mostrar recaudación total
    printf("\n🔹 Recaudación total de todos los cursos: $%.2f\n", totalRecaudado);

    return 0;
}
