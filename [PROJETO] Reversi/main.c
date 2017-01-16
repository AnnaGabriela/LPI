#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

int main()
{
    coord play;
    play.l = 0;
    play.c = 0;
    setlocale(LC_ALL, "Portuguese");
    printf("\n\n %c REVERSI %c\n\n\n", 26, 27);
    menu();
    return 0;
}
