template <typename T>

int busca_binaria(T vet, int x){
    int result = 0;
    int pos_max = vet.size()-1;
    int pos_min = 0;
    int pos_med = (pos_max-pos_min)/2;
    if(x == vet[pos_med]){
        return vet[pos_med];
    } else if (x > vet[pos_med]){
        T maior;
        for(size_t i = pos_med+1; i <= pos_max; i++){
            maior.push_back(vet[i]);
        }
        result = busca_binaria(maior, x);
    } else if (x < vet[num_med]){
        T menor;
        for(size_t i = pos_min; i < pos_med; i++){
            menor.push_back(vet[i]);
        }
        result = busca_binaria(menor, x);
    }
    return result;
}

template <typename T>

int busca_sequencial(T vet, int x){
    int result = 0;
    for(int i = 0; i < vet.size(); i++){
        if(x == vet[i]){
            result = vet[i];
        }
    }
    return result;
}


