import matplotlib.pyplot as plt

tamanho = ["P", "M", "G"]

# Comparações exatas extraídas da descrição
SelectionSortPadrao = [287988000, 7199940000, 31249875000]
SelectionSortOtimizado = [287895716, 7199561655, 31248628016]
BubbleSortPadrao = [287988000, 7199940000, 31249875000]
BubbleSortOtimizado = [287978130, 4739884704, 31249026747]
InsertionSort = [142977333, 922717910, 15611824069]

plt.figure(figsize=(10, 6))

plt.plot(tamanho, SelectionSortPadrao, color='#ff0000', marker='o', label='Selection_Sort_Original')
plt.plot(tamanho, SelectionSortOtimizado, color='#990000', marker='o', label='Selection_Sort_Otimizado')
plt.plot(tamanho, BubbleSortPadrao, color='#2266ff', marker='s', label='Bubble_Sort_Original')
plt.plot(tamanho, BubbleSortOtimizado, color='#002299', marker='^', label='Bubble_Sort_Otimizado')
plt.plot(tamanho, InsertionSort, color='#00ff00', marker='d', label='Insertion_Sort')

plt.title("Comparação do número de Comparações (Ordenação)")
plt.xlabel("Tamanho de Entrada")
plt.ylabel("Quantidade")
plt.legend()
plt.grid(True)
plt.show()
