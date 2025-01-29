#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void input(int array[], int tamanho) {
    FILE *arquivo;
    int n;
    arquivo = fopen("random_100.txt", "r"); 

    if (arquivo == NULL) { 
        printf("Erro ao abrir o arquivo.\n"); 
        exit(1); 
    }

    for (int i = 0; i < tamanho && fscanf(arquivo, "%d", &n) == 1; i++) { 
        array[i] = n; 
    } 

    fclose(arquivo);
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  // Um por um mover o menor elemento para o início
  for (i = 0; i < n-1; i++) {
    // Encontrar o índice do menor elemento
    min_idx = i;
    for (j = i+1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    // Trocar o encontrado mínimo com o primeiro elemento
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
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
  int arr[100];  // Assumindo que o arquivo tem exatamente 100 números
  int n = sizeof(arr)/sizeof(arr[0]); 

  input(arr, n);  // Lê os números do arquivo

  printf("Array antes da ordenação: \n");
  printArray(arr, n);

  clock_t start = clock();

  selectionSort(arr, n);

  clock_t end = clock();  
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Array após a ordenação: \n");
  printArray(arr, n);
  printf("\n Tempo de execução: %.6f segundos\n", time_spent);
  return 0;
}