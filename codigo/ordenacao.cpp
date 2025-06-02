#include <algorithm> // Usado aqui para usar std::iter_swap
#include <vector>
#include <iostream>

namespace selection_sort {
    static size_t original(std::vector<int> &vet){
        size_t comparacoesSort = 0;
        if(vet.size() <= 0) return 0;

        for(auto i = vet.begin(); i != vet.end(); ++i) {
            ++comparacoesSort;
            auto toSwap = i;
            for(auto j = i+1; j != vet.end(); ++j) {
                ++comparacoesSort;
                if(*j < *toSwap) toSwap = j;
            }
            std::iter_swap(toSwap, i);
        }
        return comparacoesSort;
    }

    static size_t optimized(std::vector<int> &vet){
        size_t comparacoesSort = 0;
        auto n = vet.size();
        if(n <= 1) return 0;

        auto left  = vet.begin();
        auto right = vet.end() - 1;

        while(left < right) {
            auto minIt = left;
            auto maxIt = left;
            for(auto it = left + 1; it <= right; ++it) {
                ++comparacoesSort;
                if(*it < *minIt) minIt = it;
                else {
                    ++comparacoesSort;
                    if(*it > *maxIt) maxIt = it;
                }
            }
            if(minIt != left) {
                std::iter_swap(minIt, left);
                if(maxIt == left) maxIt = minIt;
            }
            if(maxIt != right) std::iter_swap(maxIt, right);
            ++left;
            --right;
        }

        return comparacoesSort;
    }
}

namespace bubble_sort {
    static size_t original(std::vector<int> &vet) {
        size_t comparacoesSort = 0;
        auto end = vet.end();
        do {
            ++comparacoesSort;
            for(auto it = vet.begin(); it + 1 != end; ++it) {
                ++comparacoesSort;
                if(*it > *(it + 1)) std::iter_swap(it, (it+1));
            }
            --end;
        } while(end > vet.begin());
        return comparacoesSort;
    }

    static size_t optimized(std::vector<int> &vet) {
        size_t comparacoesSort = 0;
        if(vet.size() < 2) return 0;
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
        return comparacoesSort;
    }
}

static size_t insertion_sort(std::vector<int> &vet) {
    size_t comparacoesSort = 0;
    if(vet.size() < 2) return 0;

    for(auto step = vet.begin() + 1; step != vet.end(); ++step) {
        ++comparacoesSort;
        int key = *step;
        auto revStep = step - 1;
        while(revStep != vet.begin() && key < *revStep) {
            ++comparacoesSort;
            *(revStep + 1) = *revStep;
            --revStep;
        }
        *(revStep + 1) = key;
    }
    return comparacoesSort;
}