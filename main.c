#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(){

    //a escolha do melhor algoritmo de compração é feita avaliando as comparações entre chaves e movimentações
    // de registros, nesse caso, o deslocamento
    long int comp, desloc;
    long double startTime, endTime;
    struct timeval start, end;
    Registro_pequeno vetor[20];
   
    Registro *vetor_heap= (Registro*)malloc(200000*sizeof(Registro));/* cria  de registro e cada registro
                                                                possui uma chave do tipo int e um vetor_heap de
                                                                50 strings com até 50 de tamanho. É usado o malloc
                                                                pois a pilha não possui memória suficiente para guardar
                                                                200000 vetor_heapes de struct*/
    
    Registro vetor1[20];
    gerar_vetor_reg_aleatorio(vetor_heap, 200000);
    // gerar_vetor_reg_crescente(vetor_heap, 20);
    // gerar_vetor_inteiros_crescente(vetor, 20);
    // gerar_vetor_inteiros_decrescente(vetor, 20);
    //gerar_vetor_reg_decrescente(vetor1, 20);
    
 
    gettimeofday(&start, NULL);
    selectionSort_regrande(vetor_heap, 200000, &comp, &desloc);
    gettimeofday(&end, NULL);
    //   for(int i=0; i<20; i++){
    //      printf("ordenado: %d\n", vetor1[i].chave);
    //   }
    
    startTime = start.tv_sec + start.tv_usec / 1000000.0L;
    endTime = end.tv_sec + end.tv_usec / 1000000.0L;
    printf("Tempo inicial = %Lf\n", startTime);
    printf("Tempo final = %Lf\n", endTime);
    printf("Tempo decorrido = %Lf\n", endTime - startTime);
    printf("Comparações = %ld\n", comp);
    printf("Tempo decorrido = %ld\n", desloc);

    gerar_vetor_reg_aleatorio(vetor_heap, 200000);
    gettimeofday(&start, NULL);
    quickSort_grande(vetor_heap, 0, 199999, &comp, &desloc);
    gettimeofday(&end, NULL);
    //   for(int i=0; i<20; i++){
    //      printf("ordenado: %d\n", vetor1[i].chave);
    //   }
    free(vetor_heap);
    startTime = start.tv_sec + start.tv_usec / 1000000.0L;
    endTime = end.tv_sec + end.tv_usec / 1000000.0L;
    printf("Tempo inicial = %Lf\n", startTime);
    printf("Tempo final = %Lf\n", endTime);
    printf("Tempo decorrido = %Lf\n", endTime - startTime);
    printf("Comparações = %ld\n", comp);
    printf("Tempo decorrido = %ld\n", desloc);


    return 0;
}
