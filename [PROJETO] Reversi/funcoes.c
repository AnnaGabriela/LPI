#include "funcoes.h"

int i, j, p, a, var;
char tabu[8][8];

void jogo ()
{
        coord play;
        play.l = 0;
        play.c = 0;
        int j1 = 1, j2 = 2, inval;
        inicia_tabu(tabu);
        imprime_tabu(tabu, &play, 0);
        p = 1;
        do
        {
            inval = 0;
            if(movposs(tabu, p)==0)
            {
                printf("\n\n\t**Sem movimentos para jogador ");
                if(p == 1) printf("1 - O");
                else printf("2 - X");
                printf("**\n");
                p = -p;
                inval++;
            }
            if(movposs(tabu, p)==0 && inval==0)
            {
                printf("\n\t**Sem movimentos para o outro jogador, tambem.**\n");
                fimDoJogo(tabu);
                break;
            }

            else
            {
                if(p == 1)
                {
//                   printf("\n\tEm p == 1, j1 = %d\n", j1);
                    jogador(tabu, p, &play);
                }
                else
                {
//                   printf("\n\tEm p == -1, j2 = %d\n", j2);
                    jogador(tabu, p, &play);
                }

                mudarPeca(tabu, &play, p);
                imprime_tabu(tabu, &play, p);
                p = -p;
            }
        }
        while(!fimDoJogo(tabu));
}
void menu ()
{
    printf("1. Jogar\n2. Instrucoes\n3. Pontuacao\n4. Sair\n\nEscolha: ");
    scanf("%d", &p);
    switch (p)
    {
    case 1:
        system ("cls");
        printf("\n\n\n");
        jogo();
        break;
    case 2:
        system ("cls");
        instrucao();
        menuDoMenu ();
        break;

    case 3:
        ;
    case 4:
        exit(0);
    }
}
int check(char tabu[8][8], coord *move, int p)
{
    int dir = 0 , flag = 0, pcs;
    if(move->l < 0 || move->l >= 8 || move->c < 0 || move->c >= 8)
    {
        printf("Jogada inválida\n");
        return 0;
    }
    if(tabu[move->l][move->c] != 0) return 0;
    for(dir = 0; flag == 0 && dir < 8; dir++)
    {
        i = move->l;
        j = move->c;
        pcs = 0;
        switch (dir)
        {
        case 0:
            while(++j < 8 && tabu[i][j] == -p) pcs++;
            if(j >= 8) j = 8 - 1;
            if(tabu[i][j] == p && pcs) flag = 1;
            break;
        case 1:
            while(++j < 8 && --i >= 0 && tabu[i][j] == -p) pcs++;
            if(i < 0) i = 0;
            if(j >= 8) j = 8 - 1;
            if(tabu[i][j] == p && pcs) flag = 1;
            break;
        case 2:
            while(--i >= 0 && tabu[i][j] == -p) pcs++;
            if(i < 0) i = 0;
            if(tabu[i][j] == p && pcs) flag = 1;
            break;
        case 3:
            while(--j >= 0 && --i >= 0 && tabu[i][j] == -p) pcs++;
            if(i < 0) i = 0;
            if(j < 0) j = 0;
            if(tabu[i][j] == p && pcs) flag = 1;
            break;
        case 4:
            while(--j >= 0 && tabu[i][j] == -p) pcs++;
            if(j < 0) j = 0;
            if(tabu[i][j] == p && pcs) flag = 1;
            break;
        case 5:
            while(--j >= 0 && ++i < 8 && tabu[i][j] == -p) pcs++;
            if(i >= 8) i = 8 - 1;
            if(j < 0) j = 0;
            if(tabu[i][j] == p && pcs) flag = 1;
            break;
        case 6:
            while(++i < 8 && tabu[i][j] == -p) pcs++;
            if(i >= 8) i = 8 - 1;
            if(tabu[i][j] == p && pcs) flag = 1;
            break;
        case 7:
            while(++j < 8 && ++i < 8 && tabu[i][j] == -p) pcs++;
            if(i >= 8) i = 8 - 1;
            if(j >= 8) j = 8 - 1;
            if(tabu[i][j] == p && pcs) flag = 1;
            break;
        }
    }

    return flag;
}

int movposs(char tabu[8][8], int p)
{
    int jogadaValida = 0;
    coord mov;
    for (i = 0; i < 8 && !jogadaValida; i++)
    {
        for(j = 0; j < 8 && !jogadaValida; j++)
        {
            mov.l = i;
            mov.c = j;
            jogadaValida += check(tabu, &mov, p);
        }
    }
    return jogadaValida;
}

void jogador(char tabu[8][8], int p, coord *move)
{
    printf("\n\nPróximo movimento:  ");
    if(p == 1) printf("O");
    else printf("X");
    printf("\n");
    printf("Digite sua jogada\n");
    printf("(respectivamente, LINHA e COLUNA)\n");
    scanf("%d %d", &move->l, &move->c);

    while(!check(tabu, move, p))
    {
        printf("  **Movimento Inválido**\n");
        printf("Digite novamente as coordenadas de sua jogada\n");
        printf("(linha e coluna, nessa ordem)\n");
        scanf("%d %d", &move->l, &move->c);
    }
}

void inicia_tabu (char tabu[8][8])
{
    for (i=0; i<8; i++)
        for(j=0; j<8; j++)
            tabu[i][j] = 0;

    tabu[3][3] = 1;
    tabu[4][4] = 1;
    tabu[4][3] = -1;
    tabu[3][4] = -1;
}

void imprime_tabu(char tabu[8][8], coord *nova, int p)
{
    int i, j;
    system("cls");
    printf("\n\n\n ");
    printf("*REVERSI*\n\n");
    printf("    ");
    for(i = 0; i < 8; i++)
        printf("%d  ", i);
    printf("\n\n");
    for(i = 0; i < 8; i++)
    {
        printf("%d   ", i);
        for(j = 0; j < 8; j++)
        {
            if(nova->l != i || nova->c != j)
            {
                switch (tabu[i][j])
                {
                case 0:
                    printf(".  ");
                    break;
                case 1:
                    printf("o  ");
                    break;
                case -1:
                    printf("x  ");
                    break;
                }
            }
        }
        printf("\n");
    }
}
void instrucao()
{
    printf("\n\n\t\t\t%c Instruções do Jogo %c\n\n\n\n", 16, 17);
    printf("%c As peças iniciam-se alternadas no centro do tabuleiro.\n\n", 4);
    printf("%c As peças \"o\" comecam jogando, sendo \"x\" a cor contrária.\n\n", 4);
    printf("%c Uma peça e transformada (trocando de cor) quando estiver no\n", 4);
    printf("  espaço entre duas peças da cor contrária a sua, sendo uma\n");
    printf("  delas a última peça colocada no tabuleiro.\n\n");
    printf("%c Uma jogada válida e aquela em que, com a nova peça colocada,\n", 4);
    printf("  haja pelo menos uma peça adversária transformada.\n\n");
    printf("%c O jogador da vez escolhe uma casa vazia (que tem um \".\")\n", 4);
    printf("  contanto que seja uma jogada válida, e coloca sua peça ali,\n");
    printf("  fornecendo suas coordenadas (Linha e Coluna, nessa ordem).\n\n");
    printf("%c Após jogar, o outro jogador faz seu movimento também.\n\n", 4);
    printf("%c Caso não haja movimentos válidos para um dos jogadores,\n", 4);
    printf("  o outro jogador joga. Caso ambos fiquem sem\n");
    printf("  movimentos possíveis o jogo termina.\n\n");
    printf("%c Se não houverem espacos vazios, o jogo termina.\n\n", 4);
    printf("%c Se não houver pelo menos 1 peça de cada uma das cores, o jogo termina\n\n", 4);
    printf("%c Vence o jogador que, ao término do jogo, possuir mais peças.\n\n", 4);
    printf("\n\n\n\t\t\t%c Fim das instruções %c\n\n", 16, 17, 1);
}

void mudarPeca(char tabu[8][8], coord *nova, int p)
{
    int fim, dir, flag, i, j;
    tabu[nova->l][nova->c] = p;
    for(dir = 0; dir < 8; dir++)
    {
        i = nova->l;
        j = nova->c;
        fim = 0;
        switch (dir)
        {
        case 0:
            while(++j < 8 && tabu[i][j] == -p) fim++;
            if(j >= 8) j = 8 - 1;
            if(tabu[i][j] == p)
            {
                while(fim--)
                {
                    tabu[i][--j] = p;
                }
            }
            break;
        case 1:
            while(++j < 8 && --i >= 0 && tabu[i][j] == -p) fim++;
            if(j >= 8) j = 7;
            if(i < 0) i = 0;
            if(tabu[i][j] == p)
            {
                while(fim--)
                {
                    tabu[++i][--j] = p;
                }
            }
            break;
        case 2:
            while(--i >= 0 && tabu[i][j] == -p) fim++;
            if(i < 0) i = 0;
            if(tabu[i][j] == p)
            {
                while(fim--)
                {
                    tabu[++i][j] = p;
                }
            }
            break;
        case 3:
            while(--j >= 0 && --i >= 0 && tabu[i][j] == -p) fim++;
            if(i < 0) i = 0;
            if(j < 0) j = 0;
            if(tabu[i][j] == p)
            {
                while(fim--)
                {
                    tabu[++i][++j] = p;
                }
            }
            break;
        case 4:
            while(--j >= 0 && tabu[i][j] == -p) fim++;
            if(j < 0) j = 0;
            if(tabu[i][j] == p)
            {
                while(fim--)
                {
                    tabu[i][++j] = p;
                }
            }
            break;
        case 5:
            while(--j >= 0 && ++i < 8 && tabu[i][j] == -p) fim++;
            if(i >= 8) i = 8 - 1;
            if(j < 0) j = 0;
            if(tabu[i][j] == p)
            {
                while(fim--)
                {
                    tabu[--i][++j] = p;
                }
            }
            break;
        case 6:
            while(++i < 8 && tabu[i][j] == -p) fim++;
            if(i >= 8) i = 8 - 1;
            if(tabu[i][j] == p)
            {
                while(fim--)
                {
                    tabu[--i][j] = p;
                }
            }
            break;
        case 7:
            while(++j < 8 && ++i < 8 && tabu[i][j] == -p) fim++;
            if(i >= 8) i = 8 - 1;
            if(j >= 8) j = 8 - 1;
            if(tabu[i][j] == p)
            {
                while(fim--)
                {
                    tabu[--i][--j] = p;
                }
            }
            break;
        }
    }
}
void menuDoMenu ()
{
    printf ("Deseja voltar o menu? \n1 - Sim \n2 - Não\n\nEscolha: ");
    scanf("%d", &a);
    if (a == 1)
    {
        printf("\n\n");
        menu();
    }
    else if (a == 2) exit(0);
}


int fimDoJogo(char tabu[8][8])
{
    char empty = 0, o = 0,x = 0;
    char i, j, flag = 0;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            switch (tabu[i][j])
            {
            case -1:
                x++;
                break;
            case 0:
                empty++;
                break;
            case 1:
                o++;
                break;
            }
        }
    }
    printf("\n\t O = %d\n\t X = %d\n\n", o, x);

    if(!empty)
    {
        flag = 1;
        printf("\n\tSem casas possíveis.\n\tFIM DO JOGO!\n\n");
        if(o != x)
        {
            printf("O vencedor é....\n\n");
            if(o > x) printf("\t\t\   **Jogador 1!**\n\n");
            else printf("\t\t  **Jogador 2!**\n\n");
        }
        else printf("\n\nO jogo terminou empatado! /o/\n\n");
    }

    else if(!o)
    {
        flag = 1;
        printf("\nFim do jogo!\n\n");
        printf("Jogador 2 arrasou com o jogador 1!!\n\n");
    }

    else if(!x)
    {
        flag = 1;
        printf("\nFim do jogo!\n\n");
        printf("Jogador 1 arrasou com o jogador 2!!\n\n");
    }

    /*Se simplesmente nao houver jogadas possiveis para nenhum deles, fim tb.*/
    else if(!movposs(tabu, 1) && !movposs(tabu, -1))
    {
        printf("\n\nSem movimentos possiveis para ambos jogadores.\n");
        flag = 1;
        printf("Numero de pecas:\n");
        printf("\tO = %d\n", o);
        printf("\tX = %d\n\n\n", x);

        if(o > x)
        {
            printf("Venceu o Jogador 1!\n");
        }
        else if(o < x)
        {
            printf("Venceu o Jogador 2!\n");
        }
        else
        {
            printf("Houve um empate...!\n");
        }
    }
    return flag;
}
