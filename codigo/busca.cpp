#include <vector>
#include <stddef.h>

static std::pair<size_t, size_t> recursiva(size_t pos_min, size_t pos_max, std::vector<int> &vet, int x, size_t comp) {
    if (pos_min > pos_max) return std::pair<size_t, size_t>(0, comp);
    
    size_t pos_med = pos_min + (pos_max - pos_min) / 2;
    
    ++comp;
    if(vet[pos_med] == x) {
        return std::pair<size_t, size_t>(pos_med, comp);
    } else if (x > vet[pos_med]) {
        return recursiva(pos_med + 1, pos_max, vet, x, comp);
    } else {
        return recursiva(pos_min, pos_med - 1, vet, x, comp);
    }
}

static std::pair<size_t, size_t> busca_binaria(std::vector<int> &vet, int x) {
    size_t comparacoesBusca = 0;
    
    if (vet.empty()) return std::pair<size_t, size_t>(0, comparacoesBusca);
    
    size_t pos_max = vet.size() - 1;
    size_t pos_min = 0;
    size_t pos_med = pos_min + (pos_max - pos_min) / 2;
    
    ++comparacoesBusca;
    if(x == vet[pos_med]){
        return std::pair<size_t, size_t>(pos_med, comparacoesBusca);
    } else if (x > vet[pos_med]) {
        return recursiva(pos_med + 1, pos_max, vet, x, comparacoesBusca);
    } else {
        return recursiva(pos_min, pos_med - 1, vet, x, comparacoesBusca);
    }
}

static std::pair<size_t, size_t> busca_sequencial(std::vector<int> &vet, int x) {
    size_t comparacoesBusca = 0;
    
    for(size_t i = 0; i < vet.size(); ++i) {
        ++comparacoesBusca;
        if(vet[i] == x) return std::pair<size_t, size_t>(i, comparacoesBusca);
    }
    
    return std::pair<size_t, size_t>(0, comparacoesBusca);
}