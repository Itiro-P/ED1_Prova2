template <typename T>

void selection_sort(T vet){
    for(int i = 0; i < vet.size(); i++){
        T minimun = &(vet.i);
        for(int j = i; j < vet.size(); j++){
            if(*minimun > vet.j){
                *minimun = vet.j;
            }
        }
        swip(*minimun, vet.i);
    }
}

template <typename T>

void bubble_sort_padrao(T vet){
    for(int i = 0; i < vet.size(); i++){
        for(int j = 0; j+1 < vet.size(); j++){
            if(vet.j > vet.(j+1)){
                swip(vet.j,  vet.(j+1));
            }
        }
    }
}

template <typename T>

void bubble_sort_otimizado(T vet){
    bool verificacao = true;
    while(verificacao){
        verificacao = false;
        for(int j = 0; j+1 < vet.size(); j++){
            if(vet.j > vet.(j+1)){
                swip(vet.j,  vet.(j+1));
                verificacao = true;
            }
        }
    }
}

