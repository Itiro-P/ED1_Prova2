#include <vector>
#include <fstream>
#include <random>
#include <string>
#include <filesystem>
#include <limits>
#include <iostream>


enum qtdNumeros {
    PEQUENO,
    MEDIO,
    GRANDE
};

const size_t qtdNumerosSize[3] = {
    24000,
    120000,
    250000
};

static constexpr const char* nomes[] = { "PEQUENO", "MEDIO", "GRANDE" };
static constexpr const char* nomesOrdenado[] = { "PEQUENO_ORDENADO", "MEDIO_ORDENADO", "GRANDE_ORDENADO" };

static std::filesystem::path BASE_DIR = std::filesystem::path{ DATA_DIR };

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> distrib(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
static std::uniform_int_distribution<> qtdRandPequeno(0, qtdNumerosSize[0]);
static std::uniform_int_distribution<> qtdRandMedio(0, qtdNumerosSize[1]);
static std::uniform_int_distribution<> qtdRandGrande(0, qtdNumerosSize[2]);

static int randN(qtdNumeros n) {
    switch(n) {
        case PEQUENO:
        return qtdRandPequeno(gen);
        case MEDIO:
        return qtdRandMedio(gen);
        case GRANDE:
        return qtdRandGrande(gen);
    }
    return qtdRandPequeno(gen);
}

static void gerarNumeros(const qtdNumeros qtd = PEQUENO) {
    size_t n = qtdNumerosSize[qtd];
    std::filesystem::path str = BASE_DIR / nomes[qtd];
    std::ofstream arquivo(str, std::ios::binary);
    for(size_t i = 0; i < n; ++i) {
        int valor = distrib(gen);
        arquivo.write(reinterpret_cast<const char*>(&valor), sizeof(valor));
    }
}

static void salvarVetor(std::vector<int>& vec, const qtdNumeros qtd = PEQUENO) {
    std::filesystem::path str = BASE_DIR / nomesOrdenado[qtd];
    std::ofstream arquivo(str, std::ios::binary);
    for(auto &it: vec) {
        arquivo.write(reinterpret_cast<char*>(&it), sizeof(it));
    }
}

static std::vector<int> lerNumeros(const qtdNumeros qtd = PEQUENO, const bool ordenado = false) {
    size_t n = qtdNumerosSize[qtd];

    std::filesystem::path str = BASE_DIR / (ordenado ? nomesOrdenado[qtd] : nomes[qtd]);
    std::ifstream arquivo(str, std::ios::binary);

    std::vector<int> res;
    res.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        int valor;
        arquivo.read(reinterpret_cast<char*>(&valor), sizeof(valor));
        res.push_back(valor);
    }
    return res;
}

static bool isSorted(const std::vector<int> vec) {
    int prev = vec.front();
    for(auto it = vec.begin() + 1; it != vec.end(); ++it) {
        if(prev > *it) return false;
        prev = *it;
    }
    return true;
}