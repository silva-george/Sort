#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void input(int array[], int tamanho) {
    FILE *arquivo;
    int n;
    arquivo = fopen("inputs/random_100000.txt", "r"); 

    if (arquivo == NULL) { 
        printf("Erro ao abrir o arquivo.\n"); 
        exit(1); 
    }

    for (int i = 0; i < tamanho && fscanf(arquivo, "%d", &n) == 1; i++) { 
        array[i] = n; 
    } 

    fclose(arquivo);
}

void bubbleSort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) { 
    for (j = 0; j < n - i - 1; j++) { 
      if (arr[j] > arr[j+1]) { 
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
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
  arr = (int *) malloc(sizeof(int)*100000); //reserva a memoria pro array, declarando o tamanho
  int n = 100000;

  input(arr, n);  // Lê os números do arquivo

  //printf("Array antes da ordenação: \n");
  //printArray(arr, n);
  printf("Ordenand o array... \n");

  clock_t start = clock();

  bubbleSort(arr, n);

  clock_t end = clock();  
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Array ordenado com sucesso! \n");
  //printf("Array após a ordenação: \n");
  //printArray(arr, n);
  printf("\n Tempo de execução: %.6f segundos\n", time_spent);
  return 0;
}