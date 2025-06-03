#pragma once

#include <chrono>
#include <string>
#include <iostream>
#include <stddef.h>

class Cronometro {
    std::string nome;
    std::chrono::time_point<std::chrono::high_resolution_clock> clock;

    public:
    Cronometro(const std::string &nome = ""): nome(nome) {
        clock = std::chrono::high_resolution_clock::now();
    }
    ~Cronometro() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - clock);
        const double res = duration.count();
        const auto a = res/1000000;
        const auto b = res/1000000000;
        std::cout << "Tempo decorrido para " << nome << ": " << res << " ns; " << a << " ms; " << b << "s.\n";
    }
};