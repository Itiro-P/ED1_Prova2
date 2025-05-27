#include <vector>
#include <print>
#include "gerador_dados.cpp"
#include "ordenacao.cpp"

int main() {
    std::vector<int> teste = { 0, -2, 10, 5 };
    std::cout << "Antes\n\n\n";
    for(const auto &it: teste) {
        std::cout << it << ' ';
    }
    std::cout << "\nDepois:\n\n\n";
    insertion_sort::original(teste);
     for(const auto &it: teste) {
        std::cout << it << ' ';
    }
    std::cout << '\n' << isSorted(teste) << '\n';
    return 0;
}