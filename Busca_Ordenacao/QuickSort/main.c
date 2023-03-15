/*Dada a sequencia de numeros: 3 4 9 2 5 8 2 1 7 4 6 2 9 8 5 1, ordene-a em ordem não decrescente segundo os seguintes algoritmos, apresentando a sequencia obtida após
cada passo do algoritmo:
(a) QuickSort*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        printf("Passo %d: ", pi);
        for (int i = 0; i < high+1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Sequência original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    quicksort(arr, 0, n-1);
    
    printf("\nSequência ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

