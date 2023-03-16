/*mplemente a funcão reverso, que reposiciona os elementos na fila de tal forma que o
inıcio da fila torna-se o fim, e vice-versa.
*/


#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Inicializa a fila vazia
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Verifica se a fila está vazia
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// Enfileira um elemento na fila
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Desenfileira um elemento da fila
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Erro: fila vazia.\n");
        exit(1);
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return data;
}

// Empilha um elemento na pilha
void push(Node** topRef, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *topRef;
    *topRef = newNode;
}

// Desempilha um elemento da pilha
int pop(Node** topRef) {
    if (*topRef == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(1);
    }

    Node* temp = *topRef;
    int data = temp->data;
    *topRef = (*topRef)->next;
    free(temp);
    return data;
}

// Inverte a ordem dos elementos na fila
void reverso(Queue* q) {
    Node* stack1 = NULL;
    Node* stack2 = NULL;

    // Transferir os elementos da fila para a pilha 1
    while (!isQueueEmpty(q)) {
        push(&stack1, dequeue(q));
    }

    // Transferir os elementos da pilha 1 para a pilha 2
    while (stack1 != NULL) {
        push(&stack2, pop(&stack1));
    }

    // Transferir os elementos da pilha 2 para a fila
    while (stack2 != NULL) {
        enqueue(q, pop(&stack2));
    }
}

// Exibe os elementos da fila

   
void displayQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila: ");
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    // Adicionando alguns elementos na fila
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    // Exibindo os elementos da fila antes da inversão
    printf("Fila antes da inversao: ");
    displayQueue(&q);

    // Invertendo a ordem dos elementos na fila
    reverso(&q);

    // Exibindo os elementos da fila após a inversão
    printf("Fila após a inversao: ");
    displayQueue(&q);

    return 0;
}