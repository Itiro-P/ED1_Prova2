import matplotlib.pyplot as plt

tamanho = ["P", "M", "G"]

# Comparações exatas extraídas da descrição
BuscaBinaria = [13, 1, 18]
BuscaSequencial = [6822, 45733, 119449]

plt.figure(figsize=(10, 6))

plt.plot(tamanho, BuscaBinaria, color='#ff0000', marker='o', label='Busca_Binária')
plt.plot(tamanho, BuscaSequencial, color='#2266ff', marker='s', label='Busca_Sequencial')

plt.title("Comparação do número de Comparações (Busca)")
plt.xlabel("Tamanho da Entrada")
plt.ylabel("Número de Comparações")
plt.legend()
plt.grid(True)
plt.show()
