#include "jogo.h"

Grafos_mat* matriz_referencia(void) {

    Grafos_mat* grafo_jogo = aloca_grafo_m();

    // Insere o valor dos vertices;
    for (int i = 0; i < grafo_jogo->vert; i++)
    {
        grafo_jogo->adj[i][i] = i + 1;
    }
    grafo_jogo->adj[8][8] = NULL;


    insere_arco_m(grafo_jogo, 0, 1);
    insere_arco_m(grafo_jogo, 0, 3);
    insere_arco_m(grafo_jogo, 1, 2);
    insere_arco_m(grafo_jogo, 1, 4);
    insere_arco_m(grafo_jogo, 2, 5);
    insere_arco_m(grafo_jogo, 3, 4);
    insere_arco_m(grafo_jogo, 3, 6);
    insere_arco_m(grafo_jogo, 4, 5);
    insere_arco_m(grafo_jogo, 4, 7);
    insere_arco_m(grafo_jogo, 5, 8);
    insere_arco_m(grafo_jogo, 6, 7);
    insere_arco_m(grafo_jogo, 7, 8);

    return grafo_jogo;
}
Grafos_mat* matriz_embaralhada(void) {
    
    Grafos_mat* grafo_jogo = matriz_referencia();
    int i, j, buffer;

    srand(time(NULL));
    
    do {

        for (int k = 0; k < NUM_DE_EMBARALHAMENTOS; k++)
        {
            i = rand() % 9;
            j = rand() % 9;

            buffer = grafo_jogo->adj[i][i];
            grafo_jogo->adj[i][i] = grafo_jogo->adj[j][j];
            grafo_jogo->adj[j][j] = buffer;

        }
    } while (possivel_resolver(grafo_jogo) == FALSE);



    return grafo_jogo;
}

int possivel_resolver(Grafos_mat* grafo_jogo) {

    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (grafo_jogo->adj[j][j] && grafo_jogo->adj[i][i] && grafo_jogo->adj[i][i] > grafo_jogo->adj[j][j]) {
                inv_count++;
            }
        }
    }

    return (inv_count % 2 == 0);
}

Grafos_mat* jogo_impossivel_exemplo(void) {
    Grafos_mat* g = matriz_referencia();

    g->adj[0][0] = 8;
    g->adj[1][1] = 1;
    g->adj[2][2] = 2;
    g->adj[3][3] = 0;
    g->adj[4][4] = 4;
    g->adj[5][5] = 3;
    g->adj[6][6] = 7;
    g->adj[7][7] = 6;
    g->adj[8][8] = 5;

    return g;
}

void inicia_jogo(void) {

    Grafos_mat* grafo_jogo = matriz_embaralhada();
    char resposta = 'S';

    printf("\e[0;47;40m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[1;36;40m╔══════════════════════════════════╗\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[1;36;40m║           \e[1;31;34mJOGO DOS OITO\e[0;36;40m          ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[1;36;40m╚══════════════════════════════════╝\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┠──────────────────────────────────────────────────────────────────────────────────────────────────────────────┨\033[0;0m\n");
    printf("\e[0;47;40m┃\e[1;31;34mREGRAS:\e[0;47;40m                                                                                                       ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                                                                                              ┃\033[0;0m\n");
    printf("\e[0;47;40m┃\e[0;36;40mDado um tabuleiro 3x3 com 8 peças (cada peça tem um número de 1 a 8) e um espaço vazio.\e[0;47;40m                       ┃\033[0;0m\n");
    printf("\e[0;47;40m┃\e[0;36;40mO objetivo é colocar os números nas peças em ordem de forma que fique igual à configuração final.\e[0;47;40m             ┃\033[0;0m\n");
    printf("\e[0;47;40m┃\e[0;36;40mPodemos deslizar quatro peças adjacentes (esquerda, direita, acima e abaixo) no espaço vazio.\e[0;47;40m                 ┃\033[0;0m\n");
    printf("\e[0;47;40m┃\e[0;36;40mO espaço vazio é representado como 0 para facilitar a visualização.\e[0;47;40m                                           ┃\033[0;0m\n");
	printf("\e[0;47;40m┃\e[0;36;40mVocê pode apertar Ctrl+C para encerrar o programa.\e[0;47;40m                                                            ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                                                                                              ┃\033[0;0m\n");
    printf("\e[0;47;40m┠──────────────────────────────────────────────────────────────────────────────────────────────────────────────┨\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m╔══════════════════════════════════╗\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m║        \e[1;31;34mConfiguração final:\e[0;36;40m       ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m║          \033[1;35m┌───┬───┬───┐\e[0;36;40m           ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m║          \033[1;35m│ 1 │ 2 │ 3 │\e[0;36;40m           ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m║          \033[1;35m├───┼───┼───┤\e[0;36;40m           ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m║          \033[1;35m│ 4 │ 5 │ 6 │\e[0;36;40m           ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m║          \033[1;35m├───┼───┼───┤\e[0;36;40m           ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m║          \033[1;35m│ 7 │ 8 │ 0 │\e[0;36;40m           ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m║          \033[1;35m└───┴───┴───┘\e[0;36;40m           ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                     \e[0;36;40m╚══════════════════════════════════╝\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┠──────────────────────────────────────────────────────────────────────────────────────────────────────────────┨\033[0;0m\n");
    printf("\e[0;47;40m┃\e[0;36;40mDeseja começar o jogo: S/N\e[0;47;40m                                                                                    ┃\033[0;0m\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    scanf(" %c", &resposta);

    if (resposta == 'S' || resposta == 's') {
		printf("\e[0;47;40m┃                                                                                                              ┃\033[0;0m\n");
        while (verifica_se_acabou(grafo_jogo) == FALSE)
        {
            imprime_jogo(grafo_jogo);
            faz_jogada(grafo_jogo);
        }

        imprime_jogo(grafo_jogo);

		printf("\e[0;47;40m┠──────────────────────────────────────────────────────────────────────────────────────────────────────────────┨\033[0;0m\n");
		printf("\e[0;47;40m┃                                                                                                              ┃\033[0;0m\n");
        printf("\e[0;47;40m┃                                  \e[0;36;40m!!!PARABÉNS VOCÊ VENCEU O JOGO DOS OITO!!!\e[0;47;40m                                  ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                                                                                              ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣉⡥⠶⢶⣿⣿⣿⣿⣷⣆⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⣿⣿⣿⣿⣿⡿⢡⡞⠁⠀⠀⠤⠈⠿⠿⠿⠿⣿⠀⢻⣦⡈⠻⣿⣿⣿⣿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⣿⣿⣿⣿⣿⡇⠘⡁⠀⢀⣀⣀⣀⣈⣁⣐⡒⠢⢤⡈⠛⢿⡄⠻⣿⣿⣿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⣿⣿⣿⣿⣿⡇⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠉⠐⠄⡈⢀⣿⣿⣿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⣿⣿⣿⣿⣿⠇⢠⣿⣿⣿⣿⡿⢿⣿⣿⣿⠁⢈⣿⡄⠀⢀⣀⠸⣿⣿⣿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⣿⣿⡿⠟⣡⣶⣶⣬⣭⣥⣴⠀⣾⣿⣿⣿⣶⣾⣿⣧⠀⣼⣿⣷⣌⡻⢿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⠟⣋⣴⣾⣿⣿⣿⣿⣿⣿⣿⡇⢿⣿⣿⣿⣿⣿⣿⡿⢸⣿⣿⣿⣿⣷⠄⢻                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⡏⠰⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⢂⣭⣿⣿⣿⣿⣿⠇⠘⠛⠛⢉⣉⣠⣴⣾                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣷⣦⣬⣍⣉⣉⣛⣛⣉⠉⣤⣶⣾⣿⣿⣿⣿⣿⣿⡿⢰⣿⣿⣿⣿⣿⣿⣿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡘⣿⣿⣿⣿⣿⣿⣿⣿⡇⣼⣿⣿⣿⣿⣿⣿⣿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                        ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⢸⣿⣿⣿⣿⣿⣿⣿⠁⣿⣿⣿⣿⣿⣿⣿⣿⣿                                        ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                                                                                              ┃\033[0;0m\n");
		printf("\e[0;47;40m┃                                                                                                              ┃\033[0;0m\n");
		printf("\e[0;47;40m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0;0m\n");
    }else{
		printf("\e[0;47;40m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0;0m\n");
	}

    libera_grafo_m(grafo_jogo);
}


int verifica_se_acabou(Grafos_mat* grafo_jogo) {
    Grafos_mat* ref = matriz_referencia();

    for (int i = 0; i < ref->vert; i++)
    {
        if (ref->adj[i][i] != grafo_jogo->adj[i][i]) {
            return FALSE;
        }
    }

    return TRUE;
}


void imprime_jogo(Grafos_mat* grafo_jogo) {

    printf("\e[0;47;40m┃                                      \e[0;36;40m╔═════════════════════════════════╗\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                      \e[0;36;40m║          \033[1;35m┌───┬───┬───┐\e[0;36;40m          ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                      \e[0;36;40m║          \033[1;35m│ %d │ %d │ %d │\e[0;36;40m          ║\e[0;47;40m                                     ┃\033[0;0m\n", grafo_jogo->adj[0][0], grafo_jogo->adj[1][1], grafo_jogo->adj[2][2]);
    printf("\e[0;47;40m┃                                      \e[0;36;40m║          \033[1;35m├───┼───┼───┤\e[0;36;40m          ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                      \e[0;36;40m║          \033[1;35m│ %d │ %d │ %d │\e[0;36;40m          ║\e[0;47;40m                                     ┃\033[0;0m\n", grafo_jogo->adj[3][3], grafo_jogo->adj[4][4], grafo_jogo->adj[5][5]);
    printf("\e[0;47;40m┃                                      \e[0;36;40m║          \033[1;35m├───┼───┼───┤\e[0;36;40m          ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                      \e[0;36;40m║          \033[1;35m│ %d │ %d │ %d │\e[0;36;40m          ║\e[0;47;40m                                     ┃\033[0;0m\n", grafo_jogo->adj[6][6], grafo_jogo->adj[7][7], grafo_jogo->adj[8][8]);
    printf("\e[0;47;40m┃                                      \e[0;36;40m║          \033[1;35m└───┴───┴───┘\e[0;36;40m          ║\e[0;47;40m                                     ┃\033[0;0m\n");
    printf("\e[0;47;40m┃                                      \e[0;36;40m╚═════════════════════════════════╝\e[0;47;40m                                     ┃\033[0;0m\n");
    
}


void faz_jogada(Grafos_mat *grafo_jogo) {
    int movimento;

	printf("\e[0;47;40m┃                                                                                                              ┃\033[0;0m\n");
    printf("\e[0;47;40m┠──────────────────────────────────────────────────────────────────────────────────────────────────────────────┨\033[0;0m\n");
	printf("\e[0;47;40m┃\e[0;36;40mQual peça você deseja mover:\e[0;47;40m                                                                                  ┃\033[0;0m\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    scanf(" %i", &movimento);
	printf("\e[0;47;40m┃                                                                                                              ┃\033[0;0m\n");
    
	// Procura pelo campo vazio;
    for (int i = 0; i < grafo_jogo->vert; i++){
        if (grafo_jogo->adj[i][i] == NULL) {

            // Procura pelo pe�a indicada;
            for (int j = 0; j < grafo_jogo->vert; j++) {
                if (grafo_jogo->adj[j][j] == movimento) {


                    // Verifica se � poss�vel fazer aquele movimento;
                    if (grafo_jogo->adj[i][j] == 1) {

                        // Troca de lugar o espa�o vazio;
                        grafo_jogo->adj[i][i] = grafo_jogo->adj[j][j];
                        grafo_jogo->adj[j][j] = NULL;

                        // Terminou a troca;
                        return;
                    }
                }
            }

            
        }
    }
	printf("\e[0;47;40m┃\e[0;36;40mEsse movimento é impossível!\e[0;47;40m                                                                                  ┃\033[0;0m\n");
}
