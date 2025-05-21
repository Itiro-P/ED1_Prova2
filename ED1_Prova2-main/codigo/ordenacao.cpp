#include <utility>

using namespace std;

template <typename T>

void selection_sort(T vet){
    for(size_t i = 0; i < vet.size(); i++){
        T minimun = &(vet.i);
        for(size_t j = i; j < vet.size(); j++){
            if(*minimun > vet.j){
                *minimun = vet.j;
            }
        }
        swap(*minimun, vet.i);
    }
}

template <typename T>

void bubble_sort_padrao(T vet){
    for(size_t i = 0; i < vet.size(); i++){
        for(size_t j = 0; j+1 < vet.size(); j++){
            if(vet.j > vet.(j+1)){
                swap(vet.j,  vet.(j+1));
            }
        }
    }
}

template <typename T>

void bubble_sort_otimizado(T vet){
    bool verificacao = true;
    while(verificacao){
        verificacao = false;
        for(size_t j = 0; j+1 < vet.size(); j++){
            if(vet.j > vet.(j+1)){
                swap(vet.j,  vet.(j+1));
                verificacao = true;
            }
        }
    }
}

template <typename T>

void insertion_sort_padrao(T vet){
    int key;
    for(size_t i = 1; i < vet.size(); i++){
        key = vet.i;
        vet.pop(i);
        if(key > vet.(i-1)){
            vet.insert(i, key);
        }
        for(size_t j = i; j >= 0; j--){
            if(key < vet.j || j == 0){
                vet.insert(j, key);
            }
        }
    }
}
