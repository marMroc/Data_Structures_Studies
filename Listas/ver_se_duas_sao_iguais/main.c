/*Implemente uma funcão recursiva para verificar se duas listas dinâmicas e encadeadas 
são iguais.*/

#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

bool is_equal(Node* head1, Node* head2) {
    // Se ambas as listas estão vazias, elas são iguais
    if (head1 == NULL && head2 == NULL) {
        return true;
    }
    // Se uma das listas é vazia e a outra não, elas são diferentes
    if (head1 == NULL || head2 == NULL) {
        return false;
    }
    // Se os dados dos nós são diferentes, as listas são diferentes
    if (head1->data != head2->data) {
        return false;
    }
    // Caso contrário, continua a verificação recursivamente
    return is_equal(head1->next, head2->next);
}

int main() {
   // Criando as duas listas
   Node* list1 = NULL;
   Node* list2 = NULL;
   
   // Adicionando elementos na primeira lista
   insertElement(&list1, 1);
   insertElement(&list1, 2);
   insertElement(&list1, 3);
   
   // Adicionando elementos na segunda lista
   insertElement(&list2, 1);
   insertElement(&list2, 2);
   insertElement(&list2, 3);
   
   // Verificando se as listas são iguais
   if (compareLists(list1, list2))
      printf("As listas são iguais!\n");
   else
      printf("As listas são diferentes!\n");

   return 0;
}

