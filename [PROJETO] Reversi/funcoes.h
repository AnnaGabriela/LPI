#ifndef FUNCOES
#define FUNCOES


typedef struct coordenada {
    int l, c;
    } coord;

void menu ();
void instrucao ();
void menuDoMenu ();
void jogo ();

/*Inicia o tabuleiro*/
void inicia_tabu(char tabu[8][8]);

/*Imprime o tabuleiro atual*/
void imprime_tabu(char tabu[8][8], coord *nova, int p);

/*Verifica validade do movimento*/
int check(char tabu[8][8], coord *move, int p);

/*Verifica se ha movimentos possiveis*/
int movposs(char tabu[8][8], int p);

/*Transforma as pecas*/
void mudarPeca(char tabu[8][8], coord *nova, int p);

/*Verifica se o jogo terminou*/
int fimDoJogo(char tabu[8][8]);

/*Faz a jogada*/
void jogador(char tabu[8][8], int p, coord *move);

#endif // FUNCOES
