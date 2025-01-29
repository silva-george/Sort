#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void input(int array[], int tamanho) {
    FILE *arquivo;
    int n;
    arquivo = fopen("inputs/random_1000000.txt", "r"); 

    if (arquivo == NULL) { 
        printf("Erro ao abrir o arquivo.\n"); 
        exit(1); 
    }

    for (int i = 0; i < tamanho && fscanf(arquivo, "%d", &n) == 1; i++) { 
        array[i] = n; 
    } 

    fclose(arquivo);
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move os elementos de arr[0..i-1], que são
           maiores que key, uma posição para a frente */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int *arr;  // declara um ponteiro pro array
  arr = (int *) malloc(sizeof(int)*1000000); //reserva a memoria pro array, declarando o tamanho
  int n = 1000000;

  input(arr, n);  // Lê os números do arquivo

  printf("Ordenando Array \n");
  //printArray(arr, n);

  clock_t start = clock();

  insertionSort(arr, n);

  clock_t end = clock();  
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  
  printf("Array ordenado com sucesso! \n");
  //printf("Array após a ordenação: \n");
  //printArray(arr, n);
  printf("\n Tempo de execução: %.6f segundos\n", time_spent);
  return 0;
}