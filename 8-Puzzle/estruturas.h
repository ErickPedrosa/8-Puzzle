#define ERRO_1 -1
#define SUCESSO 0
#define TAMANHO 9
#define NUM_DE_EMBARALHAMENTOS 500

#define TRUE 1
#define FALSE 0

typedef int Vertice;
typedef int Bool;


//Implementa��es de estruturas de grafo;
struct grafos_matriz_adj {

    Vertice vert;
    int arcos;
    Bool** adj;

};
typedef struct grafos_matriz_adj Grafos_mat;

// Lista encadeada & funções
typedef struct p_ListaEncad
{
    int valor;
    struct p_ListaEncad *prox;
} Lista;

void lista_libera(Lista *fonte);
Lista *lista_insere(Lista *fonte, int valor);
int lista_procura(Lista* list, int alvo)

//Grafos de Matriz de Adjac�ncias N�o-Orientada.
Grafos_mat* aloca_grafo_m(void);
void libera_grafo_m(Grafos_mat* mat);
void insere_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino);
void retira_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino);
void imprime_matriz(Grafos_mat* mat);


