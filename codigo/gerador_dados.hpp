#pragma once

#include <cstdint>
#include <vector>

enum qtdNumeros {
    PEQUENO,
    MEDIO,
    GRANDE
};

static constexpr const char* nomes[] = { "PEQUENO", "MEDIO", "GRANDE" };

void gerarNumeros(const qtdNumeros qtd);

std::vector<int32_t> lerNumeros(const qtdNumeros qtd);