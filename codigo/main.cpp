#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include "gerador_dados.cpp"
#include "ordenacao.cpp"
#include "busca.cpp"
#include "cronometro.cpp"

struct Resultado {
    std::string algoritmo;
    std::string tamanho;
    size_t n_elementos;
    double tempo_ns;
    double tempo_ms;
    double tempo_s;
    int comparacoes;
};

static std::vector<Resultado> resultados;

static void salvarResultadosCSV(const std::string& filename) {
    std::ofstream file(filename);
    file << "algoritmo,tamanho,n_elementos,tempo_ns,tempo_ms,tempo_s,comparacoes\n";
    for (const auto& res : resultados) {
        file << std::quoted(res.algoritmo) << ","
             << std::quoted(res.tamanho) << ","
             << res.n_elementos << ","
             << res.tempo_ns << ","
             << res.tempo_ms << ","
             << res.tempo_s << ","
             << res.comparacoes << "\n";
    }
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
    Cronometro res(nome);
    algoritmo(teste);
}

int main() {
    std::map<std::string, std::function<void(std::vector<int>&)>> algoritmos = {
        {"Selection Sort", selection_sort},
        {"Bubble Sort Original", bubble_sort::original},
        {"Bubble Sort Otimizado", bubble_sort::optimized},
        {"Insertion Sort Original", insertion_sort::original},
        {"Insertion Sort Otimizado", insertion_sort::optimized}
    };

    const qtdNumeros tamanhos[] = {PEQUENO, MEDIO, GRANDE};
    bool primeiro_teste = true;

    for (const auto& algo : algoritmos) {
        for (auto tamanho : tamanhos) {
            teste_sort(algo.second, algo.first, tamanho, primeiro_teste);
            primeiro_teste = false;
        }
    }

    salvarResultadosCSV("resultados_ordenacao.csv");
    std::cout << "Resultados exportados para 'resultados_ordenacao.csv'\n";
    return 0;
}