#include <algorithm> // Usado aqui para usar std::iter_swap
#include <vector>
#include <iostream>
#include <stddef.h>
#include "cronometro.cpp"

namespace selection_sort {
    static std::pair<size_t, size_t> original(std::vector<int> &vet){ 
        Cronometro cro("Selection Sort Original");
        if(vet.size() <= 0) return std::pair<size_t, size_t>(0, 0);

        size_t comparacoes = 0;
        size_t trocas = 0;
        for(auto i = vet.begin(); i != vet.end(); ++i) {
            auto toSwap = i;
            for(auto j = i+1; j != vet.end(); ++j) {
                ++comparacoes;
                if(*j < *toSwap) {
                    toSwap = j;
                }
            }
            if(toSwap != i) {
                std::iter_swap(toSwap, i);
                ++trocas;
            }
        }
        return std::pair<size_t, size_t>(trocas, comparacoes);
    }

    static std::pair<size_t, size_t> optimized(std::vector<int> &vet) {
        Cronometro cro("Selection Sort Otimizado");
        auto n = vet.size();
        if(n <= 1) return std::pair<size_t, size_t>(0, 0);
        size_t comparacoes = 0;
        size_t trocas = 0;

        auto left  = vet.begin();
        auto right = vet.end() - 1;

        while(left < right) {
            auto minIt = left;
            auto maxIt = left;
            for(auto it = left + 1; it <= right; ++it) {
                ++comparacoes;
                if(*it < *minIt) {
                    minIt = it;
                }
                else {
                    ++comparacoes;
                    if(*it > *maxIt) {
                        maxIt = it;
                    }
                }
            }
            if(minIt != left) {
                ++trocas;
                std::iter_swap(minIt, left);
                if(maxIt == left) {
                    maxIt = minIt;
                }
            }
            if(maxIt != right) {
                ++trocas;
                std::iter_swap(maxIt, right);
            }
            ++left;
            --right;
        }

        return std::pair<size_t, size_t>(trocas, comparacoes);
    }
}

namespace bubble_sort {
    static std::pair<size_t, size_t> original(std::vector<int> &vet) {
        Cronometro cro("Bubble Sort Original");
        size_t comparacoes = 0;
        size_t trocas = 0;
        auto end = vet.end();
        do {
            for(auto it = vet.begin(); it + 1 != end; ++it) {
                ++comparacoes;
                if(*it > *(it + 1)) {
                    ++trocas;
                    std::iter_swap(it, (it+1));
                }
            }
            --end;
        } while(end > vet.begin());
        return std::pair<size_t, size_t>(trocas, comparacoes);
    }

    static std::pair<size_t, size_t> optimized(std::vector<int> &vet) {
        Cronometro cro("Bubble Sort Otimizado");
        if(vet.size() < 2) return std::pair<size_t, size_t>(0, 0);
        size_t comparacoes = 0;
        size_t trocas = 0;
        bool swapped = false;
        auto end = vet.end();
        do {
            swapped = false;
            for(auto it = vet.begin(); it + 1 != end; ++it) {
                ++comparacoes;
                if(*it > *(it + 1)) {
                    ++trocas;
                    std::iter_swap(it, (it+1));
                    swapped = true;
                }
            }
            --end;
        } while(swapped); 
        return std::pair<size_t, size_t>(trocas, comparacoes);
    }
}


static std::pair<size_t, size_t> insertion_sort(std::vector<int> &vet) {
    Cronometro cro("Insertion Sort");
    if(vet.size() < 2) return {0, 0};

    size_t comparacoes = 0;
    size_t trocas = 0;

    for(auto step = vet.begin() + 1; step != vet.end(); ++step) {
        int key = *step;
        auto revStep = step - 1;

        ++comparacoes;
        while(key < *revStep) {
            ++trocas;
            *(revStep + 1) = *revStep;

            if(revStep == vet.begin()) {
                revStep = vet.begin() - 1; 
                break;
            }
            --revStep;
            ++comparacoes;
        }
        *(revStep + 1) = key;
    }
    return {trocas, comparacoes};
}