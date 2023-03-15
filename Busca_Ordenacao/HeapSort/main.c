/*Dada a sequencia de numeros: 3 4 9 2 5 8 2 1 7 4 6 2 9 8 5 1, ordene-a em ordem não decrescente segundo os seguintes algoritmos, apresentando a sequencia obtida após
cada passo do algoritmo:
(a) HeapSort*/

#include <stdio.h>

// Função para ajustar um nó no heap
void ajustarHeap(int *v, int i, int f){
    int aux = v[i];
    int j = i * 2 + 1;
    while(j <= f){
        if(j < f){
            if(v[j] < v[j+1]){
                j = j + 1;
            }
        }
        if(aux < v[j]){
            v[i] = v[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    v[i] = aux;
}

// Função para ordenar o vetor usando HeapSort
void heapSort(int *v, int n){
    int i, aux;
    for(i = (n-1)/2; i >= 0; i--){
        ajustarHeap(v, i, n-1);
    }
    for(i = n-1; i >= 1; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        ajustarHeap(v, 0, i-1);
    }
}

int main(){
    int v[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
    int n = sizeof(v) / sizeof(int);
    int i;

    printf("Sequência original: ");
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    heapSort(v, n);

    printf("\nSequência ordenada (HeapSort): ");
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    return 0;
}


