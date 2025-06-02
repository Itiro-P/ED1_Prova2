#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "gerador_dados.cpp"
#include "ordenacao.cpp"
#include "busca.cpp"
#include "cronometro.cpp"

template<typename Func>
void rodar_algoritmo(Func algoritmo, std::string nome, std::vector<int>& vec) {
    Cronometro cro(nome);
    std::pair<size_t, size_t> res = algoritmo(vec);
    std::cout << "Trocas realizadas: " << static_cast<size_t>(res.first) << "\nComparações realizadas: " << static_cast<size_t>(res.second) << '\n';
}

template<typename Func>
void teste_sort(Func algoritmo, std::string nome, qtdNumeros n, bool gerarN = false) {
    if(gerarN) {
        std::cout << "Gerando números\n";
        gerarNumeros(n);
    }
    std::vector<int> teste = lerNumeros(n);
    std::string str = (n == PEQUENO ? "pequena": (n == MEDIO ? "mediana" : "grande"));
    std::cout << "O algoritmo " << nome << " está ordenando uma quantidade de números " << str << "...\n";
    rodar_algoritmo(algoritmo, nome, teste);
    salvarVetor(teste, n);
}

template<typename Func>
void rodar_busca(Func algoritmo, std::string nome, std::vector<int>& vec, int it) {
    Cronometro cro(nome);
    std::pair<size_t, size_t> res = algoritmo(vec, it);
    std::cout << "Comparações realizadas: " << static_cast<size_t>(res.second) << "\nNúmero achado: " << it << "; Posição: " << res.first << '\n';
}

template<typename Func>
void teste_busca(Func algoritmo, std::string nome, qtdNumeros n, bool gerarN = false) {
    if(gerarN) {
        std::cout << "Gerando números\n";
        gerarNumeros(n);
    }
    std::vector<int> teste = lerNumeros(n, true);

    // Elege um número presente no vetor.
    int it = teste.at(randN(n));
    std::string str = (n == PEQUENO ? "pequena": (n == MEDIO ? "mediana" : "grande"));
    std::cout << "O algoritmo " << nome << " está procurando em uma quantidade de números " << str << "...\n";
    rodar_busca(algoritmo, nome, teste, it);
}

int main() {
    std::map<std::string, std::function<std::pair<size_t, size_t>(std::vector<int>&)>> algoritmosSort = {
        {"Selection Sort Original", selection_sort::original},
        {"Selection Sort Otimizado", selection_sort::optimized},
        {"Bubble Sort Original", bubble_sort::original},
        {"Bubble Sort Otimizado", bubble_sort::optimized},
        {"Insertion Sort", insertion_sort}
    };

    const qtdNumeros tamanhos[] = {PEQUENO, MEDIO, GRANDE};
    bool primeiro_teste = true;

    for (const auto& algo : algoritmosSort) {
        for (auto tamanho : tamanhos) {
            teste_sort(algo.second, algo.first, tamanho, primeiro_teste);
            primeiro_teste = false;
        }
    }

    std::map<std::string, std::function<std::pair<size_t, size_t>(std::vector<int>&, int)>> algoritmosBusca = {
        {"Busca Binária", busca_binaria},
        {"Busca Sequencial", busca_sequencial}
    };

    for (const auto& algo : algoritmosBusca) {
        for (auto tamanho : tamanhos) {
            teste_busca(algo.second, algo.first, tamanho, primeiro_teste);
            primeiro_teste = false;
        }
    }

    return 0;
}