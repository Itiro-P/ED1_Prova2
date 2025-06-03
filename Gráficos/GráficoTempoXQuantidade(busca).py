import matplotlib.pyplot as plt

tamanho = ['P', 'M', 'G']

# Tempos exatos em segundos
BuscaBinaria = [1.886e-06, 2.444e-06, 3.912e-06]
BuscaSequencial = [4.3092e-05, 0.000242769, 0.000639257]

plt.figure(figsize=(10, 6))

plt.plot(tamanho, BuscaBinaria, color='#ff0000', marker='o', label='Busca_Binária')
plt.plot(tamanho, BuscaSequencial, color='#2266ff', marker='s', label='Busca_Sequencial')

plt.title("Comparação de tempo de execução - Busca Binária vs Sequencial")
plt.xlabel("Tamanho de Entrada")
plt.ylabel("Tempo de execução (s)")
plt.legend()
plt.grid(True)
plt.show()
