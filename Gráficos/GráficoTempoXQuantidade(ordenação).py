import matplotlib.pyplot as plt

tamanho = ['P', 'M', 'G']

# Tempos extraídos diretamente da descrição (em segundos)
SelectionSortPadrao = [1.05036, 27.1239, 118.878]
SelectionSortOtimizado = [0.279954, 12.6153, 37.7836]
BubbleSortPadrao = [3.11797, 31.6457, 255.561]
BubbleSortOtimizado = [2.06691, 22.7581, 252.553]
InsertionSort = [0.763719, 4.97227, 84.3878]

plt.figure(figsize=(10, 6))

plt.plot(tamanho, SelectionSortPadrao, color='#ff0000', marker='o', label='Selection_Sort_Original')
plt.plot(tamanho, SelectionSortOtimizado, color='#990000', marker='o', label='Selection_Sort_Otimizado')
plt.plot(tamanho, BubbleSortPadrao, color='#0000ff', marker='s', label='Bubble_Sort_Original')
plt.plot(tamanho, BubbleSortOtimizado, color='#000099', marker='^', label='Bubble_Sort_Otimizado')
plt.plot(tamanho, InsertionSort, color='#00ff00', marker='d', label='Insertion_Sort')

plt.title("Comparação de tempo de execução - Algoritmos de Ordenação")
plt.xlabel("Tamanho de Entrada")
plt.ylabel("Tempo de execução (s)")
plt.legend()
plt.grid(True)
plt.show()
