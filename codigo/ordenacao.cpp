#include <algorithm> // Usado aqui para usar std::iter_swap
#include <vector>
#include <iostream>

static int comparacoesSort = 0;

static void selection_sort(std::vector<int> &vet){
    comparacoesSort = 0;
    if(vet.size() <= 0) return;

    for(auto i = vet.begin(); i != vet.end(); ++i) {
        auto toSwap = i;
        for(auto j = i+1; j != vet.end(); ++j) {
            ++comparacoesSort;
            if(*j < *toSwap) toSwap = j;
        }
        std::iter_swap(toSwap, i);
    }
}

namespace bubble_sort {
    static void original(std::vector<int> &vet) {
        comparacoesSort = 0;
        auto end = vet.end();
        do {
            ++comparacoesSort;
            for(auto it = vet.begin(); it + 1 != end; ++it) {
                ++comparacoesSort;
                if(*it > *(it + 1)) std::iter_swap(it, (it+1));
            }
            --end;
        } while(end != vet.begin());
    }

    static void optimized(std::vector<int> &vet) {
        comparacoesSort = 0;
        if(vet.size() < 2) return;
        bool swapped = false;
        auto end = vet.end();
        do {
            ++comparacoesSort;
            swapped = false;
            for(auto it = vet.begin(); it + 1 != end; ++it) {
                ++comparacoesSort;
                if(*it > *(it + 1)) {
                    std::iter_swap(it, (it+1));
                    swapped = true;
                }
            }
            --end;
        } while(swapped); 
    }
}

static void insertion_sort(std::vector<int> &vet) {
    comparacoesSort = 0;
    if(vet.size() < 2) return;

    for(auto step = vet.begin() + 1; step != vet.end(); ++step) {
        ++comparacoesSort;
        int key = *step;
        auto revStep = step - 1;
        while(revStep != vet.begin() && key < *revStep) {
            ++comparacoesSort;
            std::iter_swap(revStep, (revStep + 1));
            --revStep;
        }
        std::iter_swap(revStep, (revStep + 1));
    }
}

static size_t getComparacoesSort() {
    return comparacoesSort;
}