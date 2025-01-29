from matplotlib import ticker
import matplotlib.pyplot as plt

# Dados
tamanhos_vetores = [0, 100, 1000, 10000, 100000, 1000000]
tempos = [0, 0.000013, 0.0010585, 0.03126475, 2.58947275, 309.152441]

# Criando o gráfico
plt.plot(tamanhos_vetores, tempos, marker='o')
plt.xlabel('Tamanho do Vetor')

# Formatando o eixo y para 3 casas decimais
formatter = ticker.FormatStrFormatter('%.3f')
plt.gca().yaxis.set_major_formatter(formatter)

plt.ylabel('Tempo de Execução (s)')
plt.title('Análise de Tempo de Execução - Insertion Sort (C)')
plt.xscale('log')
plt.yscale('log')
plt.grid(True)
plt.xticks(tamanhos_vetores, labels=[str(t) for t in tamanhos_vetores])
plt.yticks([0.1, 1, 10, 100, 1000, 10000], labels=["0.1s", "1s", "10s", "100s", "1000s", "10000s"])


# plt.plot(tamanhos_vetores, tempos, marker='o')
# plt.xlabel('Tamanho do Vetor')
# plt.ylabel('Tempo de Execução (s)')
# plt.title('Análise de Tempo de Execução - Insertion Sort (Java)')
# plt.xscale('log')
# plt.yscale('log')
# plt.grid(True)

# Configurando os limites dos eixos (opcional)
# plt.xlim(100, 1000000)
# plt.ylim(0.001, 10000)

plt.savefig('insertion_sort_c3.png')