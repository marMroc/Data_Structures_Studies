/*Dada a sequencia de numeros: 3 4 9 2 5 8 2 1 7 4 6 2 9 8 5 1, ordene-a em ordem não decrescente segundo os seguintes algoritmos, apresentando a sequencia obtida após
cada passo do algoritmo:
(a) MergeSort*/

#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Sequência original:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("\nSequência ordenada em ordem não decrescente (MergeSort):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

