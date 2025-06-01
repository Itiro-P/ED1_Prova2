#include <vector>

static int comparacoesBusca = 0;

static int recursiva(int pos_min, int pos_max, std::vector<int> &vet, int x) {
    if (pos_min > pos_max) return -1;
    
    size_t pos_med = pos_min + (pos_max - pos_min) / 2;
    
    ++comparacoesBusca;
    if(vet[pos_med] == x) {
        return pos_med;
    } else if (x > vet[pos_med]) {
        return recursiva(pos_med + 1, pos_max, vet, x);
    } else {
        return recursiva(pos_min, pos_med - 1, vet, x);
    }
}

static int busca_binaria(std::vector<int> &vet, int x) {
    comparacoesBusca = 0;
    
    if (vet.empty()) return -1;
    
    size_t pos_max = vet.size() - 1;
    size_t pos_min = 0;
    size_t pos_med = pos_min + (pos_max - pos_min) / 2;
    
    ++comparacoesBusca;
    if(x == vet[pos_med]){
        return pos_med;
    } else if (x > vet[pos_med]){
        return recursiva(pos_med + 1, pos_max, vet, x);
    } else {
        return recursiva(pos_min, pos_med - 1, vet, x);
    }
}

static int busca_sequencial(std::vector<int> &vet, int x) {
    comparacoesBusca = 0;
    
    for(size_t i = 0; i < vet.size(); ++i) {
        ++comparacoesBusca;
        if(vet[i] == x) return i;
    }
    
    return -1;
}

static size_t getComparacoesBusca() {
    return comparacoesBusca;
}