import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class bubble {

    // Função para carregar os números do arquivo para o array
    public static void input(int[] array, String filePath) {
        try {
            File file = new File(filePath); // Abre o arquivo
            Scanner scanner = new Scanner(file); // Scanner para leitura do arquivo
            int i = 0;

            // Lê os números do arquivo até o final ou até preencher o array
            while (scanner.hasNextInt() && i < array.length) {
                array[i] = scanner.nextInt();
                i++;
            }
            scanner.close(); // Fecha o scanner
        } catch (FileNotFoundException e) {
            System.out.println("Erro ao abrir o arquivo: " + e.getMessage());
            System.exit(1);
        }
    }

    // Implementação do Bubble Sort
    public static void bubbleSort(int[] array) {
        int n = array.length;
        for (int i = 0; i < n - 1; i++) { // Passa por todos os elementos
            for (int j = 0; j < n - i - 1; j++) { // Compara elementos adjacentes
                if (array[j] > array[j + 1]) { // Se estiver fora de ordem, troca
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

     public static void printArray(int[] array) {
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Função principal
    public static void main(String[] args) {
        int n = 1000000; // Tamanho do array
        int[] array = new int[n]; // Declara e inicializa o array

        // Caminho do arquivo de entrada
        String filePath = "inputs/random_1000000.txt";

        // Lê os números do arquivo para o array
        input(array, filePath);

        System.out.println("Ordenando o array...");

        // Mede o tempo de execução do Bubble Sort
        long startTime = System.nanoTime(); // Tempo inicial em nanossegundos
        bubbleSort(array);
        long endTime = System.nanoTime(); // Tempo final em nanossegundos
        
        // System.out.println("Array ordenado:");
        // printArray(array);

        // Converte o tempo para segundos e exibe o resultado
        double timeSpent = (endTime - startTime) / 1_000_000_000.0;
        System.out.println("Array ordenado com sucesso!");
        System.out.printf("Tempo de execução: %.6f segundos\n", timeSpent);
    }
}
