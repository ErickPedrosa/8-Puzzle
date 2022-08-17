#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


Grafos_mat* matriz_referencia(void);
Grafos_mat* matriz_embaralhada(void);
int possivel_resolver(Grafos_mat*);
Grafos_mat* jogo_impossivel_exemplo(void);
void inicia_jogo(void);
int verifica_se_acabou(Grafos_mat*); 
void imprime_jogo(Grafos_mat*);
void faz_jogada(Grafos_mat*);