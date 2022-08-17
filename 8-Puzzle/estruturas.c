#include "jogo.h"

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
void insere_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino) {

	if (mat->adj[origem][destino] == 0) {
		mat->adj[origem][destino] = 1;
		mat->adj[destino][origem] = 1;
		mat->arcos++;
	}

}
void retira_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino) {

	if (mat->adj[origem][destino] == 1) {
		mat->adj[origem][destino] = 0;
		mat->adj[destino][origem] = 0;
		mat->arcos--;
	}

}
void imprime_matriz(Grafos_mat* mat) {
	printf("\nMatriz de Adjac�ncias\n");
	printf("\t");
	for (int i = 0; i < mat->vert; i++) {
		printf("%i\t", i);
	}
	printf("\n");

	for (int j = 0; j < mat->vert; j++) {
		printf("%i\t", j);
		for (int k = 0; k < mat->vert; k++) {
			printf("%i\t", mat->adj[j][k]);
		}
		printf("\n");
	}
}

