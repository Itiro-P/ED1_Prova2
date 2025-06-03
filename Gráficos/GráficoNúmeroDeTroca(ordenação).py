import matplotlib.pyplot as plt

tamanho = ["P", "M", "G"]

# Trocas exatas extraídas da descrição
SelectionSortPadrao = [23982, 119990, 249987]
SelectionSortOtimizado = [23982, 105730, 249989]
BubbleSortPadrao = [142953346, 922597920, 15611574079]
BubbleSortOtimizado = [142953346, 922597920, 15611574079]
InsertionSort = [142953346, 922597920, 15611574079]

plt.figure(figsize=(10, 6))

plt.plot(tamanho, SelectionSortPadrao, color='#ff0000', marker='o', label='Selection_Sort_Original')
plt.plot(tamanho, SelectionSortOtimizado, color='#990000', marker='o', label='Selection_Sort_Otimizado')
plt.plot(tamanho, BubbleSortPadrao, color='#2266ff', marker='s', label='Bubble_Sort_Original')
plt.plot(tamanho, BubbleSortOtimizado, color='#002299', marker='^', label='Bubble_Sort_Otimizado')
plt.plot(tamanho, InsertionSort, color='#00ff00', marker='d', label='Insertion_Sort')

plt.title("Comparação do número de Trocas (Ordenação)")
plt.xlabel("Tamanho de Entrada")
plt.ylabel("Quantidade")
plt.legend()
plt.grid(True)
plt.show()
