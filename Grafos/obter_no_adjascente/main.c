/*Faça uma função para obter todos os nós adjacentes (vizinhos) a um nó do grafo, dado 
que o grafo e representado por uma matriz de adjacencias*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj_matrix[MAX_NODES][MAX_NODES];
int num_nodes;

void get_adjacent_nodes(int node, int *adj_nodes, int *num_adj_nodes) {
    int i;
    *num_adj_nodes = 0;
    for (i = 0; i < num_nodes; i++) {
        if (adj_matrix[node][i]) {
            adj_nodes[*num_adj_nodes] = i;
            (*num_adj_nodes)++;
        }
    }
}

int main() {
    int i, j, node;
    int adj_nodes[MAX_NODES];
    int num_adj_nodes;
    
    printf("Digite o número de nós do grafo (máximo %d): ", MAX_NODES);
    scanf("%d", &num_nodes);

    printf("Digite a matriz de adjacências (%d x %d):\n", num_nodes, num_nodes);
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    
    printf("Digite o nó para o qual deseja obter os vizinhos: ");
    scanf("%d", &node);

    get_adjacent_nodes(node, adj_nodes, &num_adj_nodes);
    
    printf("Vizinhos do nó %d:", node);
    for (i = 0; i < num_adj_nodes; i++) {
        printf(" %d", adj_nodes[i]);
    }
    printf("\n");
    
    return 0;
}
