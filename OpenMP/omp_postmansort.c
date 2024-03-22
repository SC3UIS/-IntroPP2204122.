#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define ARRAY_SIZE 100000

// Declaración de funciones
void quicksort(int[], int, int);
int partition(int[], int, int);
int generateRandom();

// Variables globales
int array[ARRAY_SIZE];
int i, temp;

int main() {
    double start, end;

    start = omp_get_wtime(); // Iniciar el cronómetro

    srand(time(NULL)); // Inicializar la semilla del generador de números aleatorios

#pragma omp parallel for
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = generateRandom();
    }

    // Ordenar el arreglo usando Quick Sort
    quicksort(array, 0, ARRAY_SIZE - 1);

    end = omp_get_wtime(); // Detener el cronómetro

    printf("El trabajo tomó %f segundos\n", end - start); // Imprimir el tiempo de ejecución

    return 0;
}

// Implementación de Quick Sort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

#pragma omp task
        quicksort(arr, low, pi - 1);

#pragma omp task
        quicksort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Función para generar un número aleatorio entre 0 y 9999
int generateRandom() {
    return rand() % 10000;
}

