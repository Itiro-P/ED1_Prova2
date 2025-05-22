#include <stdlib.h>
#include <time.h>

std::vector<int> vetor_aleatorio(int n) {
    std::vector<int> vet(n);
    srand(time(NULL));
    for(size_t i = 0; i < n; i++){
        vet[i] = rand();
    }
    return vet;
}