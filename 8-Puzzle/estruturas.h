#define ERRO_1 -1
#define SUCESSO 0
#define TAMANHO 9
#define NUM_DE_EMBARALHAMENTOS 500
#define TAM_FILA 10000

#define TRUE 1
#define FALSE 0

typedef int Vertice;
typedef int Bool;


//Implementa��es de estruturas de grafo;
struct grafos_matriz_adj {

    Vertice vert;
    int arcos;
    Bool** adj;
    int dist_local;
    int dist_global;
    struct grafos_matriz_adj *parente;
};
typedef struct grafos_matriz_adj Grafos_mat;

// Lista encadeada & funções
typedef struct p_ListaEncad
{
    int valor;
    Grafos_mat *grafo;
    struct p_ListaEncad *prox;
} Lista;

int obter_codigo(Grafos_mat *tabela);

Grafos_mat *lista_pega(Lista *fonte, int valor);
void lista_altera(Lista *lista, int alvo, Grafos_mat* valor);
void lista_libera(Lista *fonte);
Lista *lista_insere(Lista *fonte, Grafos_mat *info);
int lista_procura(Lista* list, int alvo);

// Fila & funções
typedef struct p_filaNodo
{
    Grafos_mat *grafo;
    struct p_filaNodo *prox;
} filaNodo;
typedef struct p_fila
{
    filaNodo *inicio;
    filaNodo *fim;
} Fila;

Fila *Fila_cria();
void Fila_insere(Fila *fonte, Grafos_mat *info);
Grafos_mat *Fila_retira(Fila *fonte);
void Fila_libera(Fila *fonte);

//Grafos de Matriz de Adjac�ncias N�o-Orientada.
Grafos_mat* aloca_grafo_m(void);
void grafo_copia(Grafos_mat *dest, Grafos_mat *fonte);
void libera_grafo_m(Grafos_mat* mat);
void insere_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino);
void retira_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino);


