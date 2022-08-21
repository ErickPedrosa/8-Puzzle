#include "jogo.h"

// .c Contendo todas as definições de funções relacionadas a estrutura de Grafo.


Grafos_mat* aloca_grafo_m(void) {
	Grafos_mat* mat;

	mat = (Grafos_mat*)malloc(sizeof(Grafos_mat));
	
	mat->adj = (Bool**)malloc(sizeof(Bool*) * TAMANHO);
	
	for (int i = 0; i < TAMANHO; i++) {
		mat->adj[i] = (Bool*)calloc(TAMANHO, sizeof(Bool));
		
	}

	mat->arcos = 0;
	mat->vert = TAMANHO;

	return mat;
}
void libera_grafo_m(Grafos_mat* mat) {

	for (int i = 0; i < mat->vert; i++) {
		free(mat->adj[i]);
	}
	free(mat->adj);
	free(mat);

}

// Insere uma aresta não-orientada no grafo;
void insere_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino) {

	if (mat->adj[origem][destino] == 0) {
		mat->adj[origem][destino] = 1;
		mat->adj[destino][origem] = 1;
		mat->arcos++;
	}

}

// Retira uma aresta do grafo;
void retira_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino) {

	if (mat->adj[origem][destino] == 1) {
		mat->adj[origem][destino] = 0;
		mat->adj[destino][origem] = 0;
		mat->arcos--;
	}

}
