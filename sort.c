#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//O trabalho pede para ordenar os vetores de retgistro grande e pequeno da entrada de forma aleatória,
//crescente e decrescente

void gerar_vetor_reg_aleatorio(Registro *vetor, int tam){
    srand(time(NULL));

    for(int i=0; i<tam; i++){
        
        vetor[i].chave = rand();
    }
}

void gerar_vetor_reg_crescente(Registro *vetor, int tam){
   
    for(int i=0; i<tam; i++){
      
        vetor[i].chave = i;
    }
}

void gerar_vetor_reg_decrescente(Registro *vetor, int tam){

    for(int i=tam-1; i>=0; i--){

        vetor[i].chave = i;
    }
}

void gerar_vetor_inteiros_rand(Registro_pequeno *vetor, int tam){
    srand(time(NULL));
    for(int i=0; i<tam; i++){
        vetor[i].chave = rand();
    }
}

void gerar_vetor_inteiros_crescente(Registro_pequeno *vetor, int tam){
    for(int i=0; i<tam; i++){
        vetor[i].chave = i;
    }
}

void gerar_vetor_inteiros_decrescente(Registro_pequeno *vetor, int tam){
    for(int i=tam-1; i>=0; i--){
        vetor[i].chave = i;

    }

}

void liberar_vetor(Registro *reg){
    free(reg);
}

//essa função será usada no selection sort, quick sort, heap sort para registros grandes

void swap_reggrande(Registro *a, Registro *b, long int *desloc){
    Registro t = *a;
    *a = *b;
    *b = t;
    (*desloc)++;
}

//essa função será usada no selection sort, quick sort, heap sort para registros pequenos

void swap_regpequeno(Registro_pequeno *a, Registro_pequeno *b, long int *desloc){
    Registro_pequeno t = *a;
    *a = *b;
    *b = t;
    (*desloc)++;
}

// Selection Sort registros grandes 

void selectionSort_regrande(Registro arr[], int n, long int *comp, long int *desloc){
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            (*comp)++;
            if(arr[j].chave < arr[min_idx].chave){
                min_idx = j;
            }
        }
        swap_reggrande(&arr[min_idx], &arr[i], desloc);
    }
}

// Selection Sort registros pequenos 

void selectionSort_regpequeno(Registro_pequeno arr[], int n, long int *comp, long int *desloc){
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            (*comp)++;
            if(arr[j].chave < arr[min_idx].chave){
                min_idx = j;
            }
        }
        swap_regpequeno(&arr[min_idx], &arr[i], desloc);
    }
}

// QuickSort para registros grandes

int partition_grande(Registro *array, int low, int high, long int *comp, long int *desloc){

    Registro pivot = array[high];
    //printf("%d\n", pivot.chave);
    int i = (low - 1);

    for(int j = low; j < high; j++){
        (*comp)++;
        if(array[j].chave <= pivot.chave) {
            i++;
            swap_reggrande(&array[i], &array[j], desloc);
        }
    }

    swap_reggrande(&array[i + 1], &array[high], desloc);
    return (i + 1);
}

void quickSort_grande(Registro *array, int low, int high, long int *comp, long int *desloc){
    if (low < high) {

        int pi = partition_grande(array, low, high, comp, desloc);

        quickSort_grande(array, low, pi - 1, comp, desloc);

        quickSort_grande(array, pi + 1, high, comp, desloc);
    }
}

// Quicksort registros pequenos

int partition_pequeno(Registro_pequeno *array, int low, int high, long int *comp, long int *desloc){
    Registro_pequeno pivot = array[high];
    //printf("%d\n", pivot.chave);
    int i = (low - 1);

    for(int j = low; j < high; j++){
        (*comp)++;
        if(array[j].chave <= pivot.chave) {
            i++;
            swap_regpequeno(&array[i], &array[j], desloc);
        }
    }

    swap_regpequeno(&array[i + 1], &array[high], desloc);
    return (i + 1);
}

void quickSort_pequeno(Registro_pequeno *array, int low, int high, long int *comp, long int *desloc){
    if (low < high) {

        int pi = partition_pequeno(array, low, high, comp, desloc);

        quickSort_pequeno(array, low, pi - 1, comp, desloc);

        quickSort_pequeno(array, pi + 1, high, comp, desloc);
    }
}
// Insertion Sort para registros grandes

void insertionSort_grande(Registro arr[], int n, long int *comp, long int *desloc){
    Registro key;
    int j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].chave > key.chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// insertion sort para registros pequenos
void insertionSort_pequeno(Registro_pequeno arr[], int n, long int *comp, long int *desloc){
    Registro_pequeno key;
    int j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].chave > key.chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// // shell Sort

// void shellSort(Registro arr[], int num, long int *comp, long int *desloc){
//     int i, j, k;
//     Registro tmp;
//     for (i = num / 2; i > 0; i /= 2) {
//         for (j = i; j < num; j++) {
//             for(k = j - i; k >= 0; k -= i) {
//                 if (arr[k+i].chave >= arr[k].chave)
//                     break;
//                 else {
//                     tmp = arr[k];
//                     arr[k] = arr[k+i];
//                     arr[k+i] = tmp;
//                 }
//             }
//         }
//     }
// }

// // Heap Sort

// void heapify(Registro arr[], int n, int i, long int *comp, long int *desloc){
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n && arr[left].chave > arr[largest].chave)
//         largest = left;

//     if (right < n && arr[right].chave > arr[largest].chave)
//         largest = right;

//     if (largest != i) {
//         swap(&arr[i], &arr[largest], desloc);
//         heapify(arr, n, largest, comp, desloc);
//     }
// }

// void heapSort(Registro arr[], int n, long int *comp, long int *desloc){
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(arr, n, i, comp, desloc);

//     for (int i = n - 1; i >= 0; i--) {
//         swap(&arr[0], &arr[i], desloc);
//         heapify(arr, i, 0, comp, desloc);
//     }
// }

// // Merge Sort

// void merge(Registro arr[], int l, int m, int r, long int *comp, long int *desloc){
//     int i, j, k;
//     int n1 = m - l + 1;
//     int n2 = r - m;

//     Registro L[n1], R[n2];

//     for (i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];

//     i = 0;
//     j = 0;
//     k = l;

//     while (i < n1 && j < n2){
//         if (L[i].chave <= R[j].chave){
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(Registro arr[], int l, int r, long int *comp, long int *desloc){
//     if (l < r) {
//         int m = l + (r - l) / 2;

//         mergeSort(arr, l, m, comp, desloc);
//         mergeSort(arr, m + 1, r, comp, desloc);
//         merge(arr, l, m, r, comp, desloc);
//     }
// }
