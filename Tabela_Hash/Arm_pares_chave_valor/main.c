/*Implemente uma tabela hash em C que permita armazenar pares chave-valor. 
A tabela deve ser capaz de lidar com colisões usando uma estratégia de encadeamento separado.
A implementação da tabela hash deve conter as seguintes funções:

hash_table_create: Cria uma nova tabela hash com um tamanho especificado.
hash_table_put: Insere um novo par chave-valor na tabela hash.
hash_table_get: Retorna o valor associado a uma determinada chave na tabela hash.
hash_table_remove: Remove o par chave-valor associado a uma determinada chave na tabela hash.

A tabela hash deve ser implementada usando uma matriz de listas ligadas, 
onde cada elemento da matriz é uma lista ligada que contém todos os pares chave-valor que foram mapeados para esse índice da matriz. 
A função hash deve ser implementada usando uma função de dispersão simples, como a função módulo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct node {
    char key[50];
    int value;
    struct node *next;
} Node;

typedef struct {
    Node *table[TABLE_SIZE];
} HashTable;

int hash(char *key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

void insert(HashTable *ht, char *key, int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;
    
    int index = hash(key);
    if (ht->table[index] == NULL) {
        ht->table[index] = new_node;
    } else {
        Node *current = ht->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

Node* search(HashTable *ht, char *key) {
    int index = hash(key);
    Node *current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    HashTable ht;
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht.table[i] = NULL;
    }

    insert(&ht, "apple", 1);
    insert(&ht, "banana", 2);
    insert(&ht, "cherry", 3);
    insert(&ht, "date", 4);
    insert(&ht, "elderberry", 5);

    Node *node1 = search(&ht, "cherry");
    if (node1 != NULL) {
        printf("The value for 'cherry' is %d\n", node1->value);
    } else {
        printf("Key not found\n");
    }

    Node *node2 = search(&ht, "fig");
    if (node2 != NULL) {
        printf("The value for 'fig' is %d\n", node2->value);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
