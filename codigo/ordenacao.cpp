#include <algorithm> // Usado aqui para usar std::iter_swap
#include <vector>
#include <iostream>

static void selection_sort(std::vector<int> &vet){
    if(vet.size() <= 0) return;

    for(auto i = vet.begin(); i != vet.end(); ++i) {
        auto toSwap = i;
        for(auto j = i+1; j != vet.end(); ++j) {
            if(*j < *toSwap) toSwap = j;
        }
        std::iter_swap(toSwap, i);
    }
}

namespace bubble_sort {
    static void original(std::vector<int> &vet) {
        auto end = vet.end();
        do {
            for(auto it = vet.begin(); it + 1 != end; ++it) {
                if(*it > *(it + 1)) std::iter_swap(it, (it+1));
            }
            --end;
        } while(end != vet.begin());
    }

    static void optimized(std::vector<int> &vet) {
        if(vet.size() < 2) return;
        bool swapped = false;
        auto end = vet.end();
        do {
            swapped = false;
            for(auto it = vet.begin(); it + 1 != end; ++it) {
                if(*it > *(it + 1)) {
                    std::iter_swap(it, (it+1));
                    swapped = true;
                }
            }
            --end;
        } while(swapped); 
    }
}

namespace insertion_sort {
    static void original(std::vector<int> &vet) {
        for(size_t step = 1; step < vet.size(); ++step) {
            int revStep = step-1;
            int key = vet[step];
            vet[step] = vet[step-1];
            while(revStep >= 0 && key < vet[revStep]) {
                vet[revStep + 1] = vet[revStep];
                --revStep;
            }
            vet[revStep + 1] = key;
        }
    }

    static void optimized(std::vector<int> &vet) {
        if(vet.size() < 2) return;

        for(auto step = vet.begin() + 1; step != vet.end(); ++step) {
            int key = *step;
            auto revStep = step - 1;
            while(revStep != vet.begin() && key < *revStep) {
                std::iter_swap(revStep, (revStep + 1));
                --revStep;
            }
            std::iter_swap(revStep, (revStep + 1));
        }
    }
}