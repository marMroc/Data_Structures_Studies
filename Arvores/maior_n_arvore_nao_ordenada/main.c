/* Escreva uma função para achar o MAIOR número em uma arvore binária NÃO ordenada */
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Cria um novo nó na árvore
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Busca pelo maior número na árvore binária não ordenada
int findMax(Node* root) {
    if (root == NULL) {
        return -1;
    }

    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }

    return max;
}

int main() {
    // Construção da árvore
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    // Encontrar o maior número na árvore
    int max = findMax(root);

    printf("Maior numero na arvore: %d\n", max);

    return 0;
}
