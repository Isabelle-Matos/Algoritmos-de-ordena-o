## Algoritmos de ordenação
# Trabalho realizado durante a disciplina de algoritmos e estruturas de dados 2

O objetivo do trabalho é avaliar o tempo de execução que os códigos dos algoritmos de ordenação levam para situações diversas. Para isso, foram-se utilizados 5 vetores de tamanhos 20, 500, 5000, 10000 e 100000 elementos, e para cada vetor há dois tipos de registros, pequenos e grandes. Esses contêm apenas uma chave inteira, já estes, além de possuir, também, uma chave inteira, integra 50 campos com strings de 50 caracteres, entretanto, não será necessário inicializar essas strings pois o intuito delas é apenas ocupar o espaço na memória para esse tipo de registro.
Outrossim, para estimar o tempo de cada algoritmo, dividiu-se as situações em 3 tipos para cada vetor de entrada:


** Vetor ordenado aleatoriamente
** Vetor ordenado crescentemente
** Vetor ordenado decrescentemente


Instruções para a compilação:

Após clonar, abra um terminal na pasta do projeto e digite o comando:

```gcc main.c sort.c sort.h -o main```

Depois, execute o programa com `./main` e espere sua execução. depois de finalizada a execução será gerado um arquivo `resultados.txt` que conterá todas as informações de tempo de execução. número de deslocamentos e número de comparações realizadas por cada algoritmo de ordenação em cada um dos casos de teste.
