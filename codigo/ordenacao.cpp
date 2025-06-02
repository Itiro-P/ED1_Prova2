#include <algorithm> // Usado aqui para usar std::iter_swap
#include <vector>
#include <iostream>
#include <stddef.h>

namespace selection_sort {
    static std::pair<size_t, size_t> original(std::vector<int> &vet){ 
        if(vet.size() <= 0) return std::pair<size_t, size_t>(0, 0);

        size_t comparacoes = 0;
        size_t trocas = 0;
        for(auto i = vet.begin(); i != vet.end(); ++i) {
            ++comparacoes;
            auto toSwap = i;
            for(auto j = i+1; j != vet.end(); ++j) {
                ++comparacoes;
                if(*j < *toSwap) {
                    ++trocas;
                    toSwap = j;
                }
            }
            std::iter_swap(toSwap, i);
        }
        return std::pair<size_t, size_t>(trocas, comparacoes);
    }

    static std::pair<size_t, size_t> optimized(std::vector<int> &vet){
        auto n = vet.size();
        if(n <= 1) return std::pair<size_t, size_t>(0, 0);
        size_t comparacoes = 0;
        size_t trocas = 0;

        auto left  = vet.begin();
        auto right = vet.end() - 1;

        while(left < right) {
            auto minIt = left;
            auto maxIt = left;
            ++comparacoes;
            for(auto it = left + 1; it <= right; ++it) {
                ++comparacoes;
                if(*it < *minIt) {
                    ++trocas;
                    minIt = it;
                }
                else {
                    ++comparacoes;
                    if(*it > *maxIt) {
                        ++trocas;
                        maxIt = it;
                    }
                }
            }
            if(minIt != left) {
                ++comparacoes;
                std::iter_swap(minIt, left);
                if(maxIt == left) {
                    ++trocas;
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
        size_t comparacoes = 0;
        size_t trocas = 0;
        auto end = vet.end();
        do {
            ++comparacoes;
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
        if(vet.size() < 2) return std::pair<size_t, size_t>(0, 0);
        size_t comparacoes = 0;
        size_t trocas = 0;
        bool swapped = false;
        auto end = vet.end();
        do {
            ++comparacoes;
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
    if(vet.size() < 2) return std::pair<size_t, size_t>(0, 0);

    size_t comparacoes = 0;
    size_t trocas = 0;

    for(auto step = vet.begin() + 1; step != vet.end(); ++step) {
        ++comparacoes;
        int key = *step;
        auto revStep = step - 1;
        while(revStep != vet.begin() && key < *revStep) {
            ++comparacoes;
            ++trocas;
            *(revStep + 1) = *revStep;
            --revStep;
        }
        *(revStep + 1) = key;
    }
    return std::pair<size_t, size_t>(trocas, comparacoes);
}