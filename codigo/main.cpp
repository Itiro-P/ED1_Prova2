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
void teste_sort(Func algoritmo, std::string nome, qtdNumeros n, bool gerarN = false) {
    if(gerarN) {
        std::cout << "Gerando números\n";
        gerarNumeros(n);
    }
    std::vector<int> teste = lerNumeros(n);
    std::string str = (n == PEQUENO ? "pequena": (n == MEDIO ? "mediana" : "grande"));
    std::cout << "O algoritmo " << nome << " está ordenando uma quantidade de números " << str << "...\n";
    Cronometro cro(nome);
    algoritmo(teste);
    std::cout << "Comparações realizadas: " << static_cast<size_t>(getComparacoesSort()) << '\n';
}

template<typename Func>
void teste_busca(Func algoritmo, std::string nome, qtdNumeros n, bool gerarN = false) {
    if(gerarN) {
        std::cout << "Gerando números\n";
        gerarNumeros(n);
    }
    std::vector<int> teste = lerNumeros(n);

    // Elege um número presente no vetor.
    int it = teste.at(randN(n));
    std::string str = (n == PEQUENO ? "pequena": (n == MEDIO ? "mediana" : "grande"));
    std::cout << "O algoritmo " << nome << " está procurando em uma quantidade de números " << str << "...\n";
    Cronometro cro(nome);
    size_t res = algoritmo(teste, it);
    std::cout << "Comparações realizadas: " << static_cast<size_t>(getComparacoesBusca()) << "\nNúmero achado: " << it << "; Posição: " << res << '\n';
}

int main() {
    std::map<std::string, std::function<void(std::vector<int>&)>> algoritmosSort = {
        {"Selection Sort", selection_sort},
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

    std::map<std::string, std::function<int(std::vector<int>&, int&)>> algoritmosBusca = {
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