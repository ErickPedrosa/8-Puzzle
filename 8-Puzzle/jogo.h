#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

typedef enum p_Direc
{
    Cima = 0,
    Direita = 1,
    Baixo = 2,
    Esquerda = 3
} Direcao;

int obter_lugar(Grafos_mat *jogo, int valor);
void fazer_movimento(Grafos_mat *jogo, Direcao direc);
// int 1(Grafos_mat *tabela);
int jogo_resolver(Grafos_mat *jogo);

Grafos_mat* matriz_referencia(void);
Grafos_mat* matriz_embaralhada(void);
int possivel_resolver(Grafos_mat*);
Grafos_mat* jogo_impossivel_exemplo(void);
void inicia_jogo(void);
int verifica_se_acabou(Grafos_mat*); 
void imprime_jogo(Grafos_mat*);
void faz_jogada(Grafos_mat*);