/*
 Considere uma pilha que armazene caracteres. Faça uma função para determinar se uma string e da forma XY, onde X é uma cadeia formada por caracteres arbitrários e Y é o reverso de X. Por exemplo, se x = ABCD, então y = DCBA. Considere que x e y são duas strings distintas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Definição da estrutura de um nó da pilha
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Empilha um elemento na pilha
void push(Node** topRef, char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *topRef;
    *topRef = newNode;
}

// Desempilha um elemento da pilha
char pop(Node** topRef) {
    if (*topRef == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(1);
    }

    Node* temp = *topRef;
    char data = temp->data;
    *topRef = (*topRef)->next;
    free(temp);
    return data;
}

// Verifica se uma string é igual a sua reversa
int isStringReversed(char* x, char* y) {
    int i, len = strlen(x);
    Node* stack = NULL;

    // Empilha os caracteres da string x na pilha
    for (i = 0; i < len; i++) {
        push(&stack, x[i]);
    }

    // Desempilha os caracteres da pilha e verifica se são iguais aos da string y
    for (i = 0; i < len; i++) {
        if (pop(&stack) != y[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char x[MAX], y[MAX];

    printf("Digite a string X: ");
    scanf("%s", x);

    printf("Digite a string Y: ");
    scanf("%s", y);

    if (isStringReversed(x, y)) {
        printf("A string X é igual a sua reversa Y.\n");
    } else {
        printf("A string X não é igual a sua reversa Y.\n");
    }

    return 0;
}
