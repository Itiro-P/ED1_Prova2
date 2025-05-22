#include <cstdint>
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

static constexpr const char* nomes[] = { "PEQUENO", "MEDIO", "GRANDE" };

static std::filesystem::path BASE_DIR = std::filesystem::path{ DATA_DIR };

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> distrib(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::max());

static void gerarNumeros(const qtdNumeros qtd) {
    size_t n = 0;
    std::filesystem::path str = BASE_DIR / nomes[qtd];
    std::ofstream arquivo(str, std::ios::binary);
    switch(qtd) {
        default:
        case PEQUENO:
        n = 100;
        break;
        case MEDIO:
        n = 100000;
        break;
        case GRANDE:
        n = 100000000;
        break;
    }
    for(size_t i = 0; i < n; ++i) {
        int32_t valor = distrib(gen);
        arquivo.write(reinterpret_cast<const char*>(&valor), sizeof(valor));
    }
}

static std::vector<int32_t> lerNumeros(const qtdNumeros qtd) {
    size_t n = 0;
    switch(qtd) {
        default:
        case PEQUENO:
        n = 100;
        break;
        case MEDIO:
        n = 100000;
        break;
        case GRANDE:
        n = 100000000;
        break;
    }

    std::filesystem::path str = BASE_DIR / nomes[qtd];
    std::ifstream arquivo(str, std::ios::binary);

    std::vector<int32_t> res;
    res.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        int32_t valor;
        arquivo.read(reinterpret_cast<char*>(&valor), sizeof(valor));
        std::cout << valor << '\n';
        res.push_back(valor);
    }
    return res;
}

static bool isSorted(const std::vector<int32_t> vec) {
    int32_t prev = vec.front();
    for(auto it = vec.begin() + 1; it != vec.end(); ++it) {
        if(prev > *it) return false;
        prev = *it;
    }
    return true;
}