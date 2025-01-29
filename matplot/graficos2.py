import matplotlib.pyplot as plt
import numpy as np

# Dados
tamanhos = [100, 1000, 10000, 100000, 1000000]
tempos = [0.00006075, 0.00382475, 0.2086165, 19.049092, 2061.1498328]

# Criando o gráfico
plt.figure(figsize=(8, 6))
plt.plot(tamanhos, tempos, marker='o', linestyle='-', color='b', label="Insertion Sort")

# Configuração dos eixos
plt.xscale('log')
plt.yscale('log')

plt.xticks(tamanhos, labels=[str(t) for t in tamanhos])
plt.yticks([0.1, 1, 10, 100, 1000, 10000], labels=["0.1s", "1s", "10s", "100s", "1000s", "10000s"])

plt.xlabel("Tamanho do Vetor (Entradas)")
plt.ylabel("Tempo (Segundos)")
plt.title("Análise de Tempo de Execução - Bubble Sort (C)")
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)

# Exibir gráfico
plt.savefig('bubble_sort_c2.png')