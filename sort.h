#include <stdio.h>

typedef struct{
    int chave;
    char campos[50][50];
}Registro;

typedef struct{
    int chave;
}Registro_pequeno;

void gerar_vetor_reg_aleatorio(Registro *vetor, int tam);
void gerar_vetor_reg_crescente(Registro *vetor, int tam);
void gerar_vetor_reg_decrescente(Registro *vetor, int tam);
void gerar_vetor_inteiros_rand(Registro_pequeno *vetor, int tam);
void gerar_vetor_inteiros_crescente(Registro_pequeno *vetor, int tam);
void gerar_vetor_inteiros_decrescente(Registro_pequeno *vetor, int tam);
void liberar_vetor(Registro *reg);
void swap_reggrande(Registro *a, Registro *b, long int *desloc);
void swap_regpequeno(Registro_pequeno *a, Registro_pequeno *b, long int *desloc);
void selectionSort_regrande(Registro *reg, int tam, long int *comp, long int *desloc);
void selectionSort_regpequeno(Registro_pequeno *reg, int tam, long int *comp, long int *desloc);
void quickSort_grande(Registro *array, int low, int high, long int *comp, long int *desloc);
int partition_grande(Registro *array, int low, int high, long int *comp, long int *desloc);
void quickSort_pequeno(Registro_pequeno *array, int low, int high, long int *comp, long int *desloc);
int partition_pequeno(Registro_pequeno *array, int low, int high, long int *comp, long int *desloc);
void insertionSort(Registro arr[], int n, long int *comp, long int *desloc);
void shellSort(Registro arr[], int num, long int *comp, long int *desloc);
void heapSort(Registro arr[], int n, long int *comp, long int *desloc);
void mergeSort(Registro arr[], int l, int r, long int *comp, long int *desloc);
