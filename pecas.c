#include <stdio.h>
#include <windows.h>
#include <time.h>
#define FREE 0
#define PECAS 5
#define CX 8
#define CY 1
#define LARG 20
#define ALT 24
#include "peca.h"

extern int matriz[LARG][ALT];
extern char pecas[7][4][PECAS][PECAS];
extern int pontuacao;

int Tipo_Do_Bloco (int p, int r, int x, int y) // Retorna o tipo de bloco.
                                                              // Extremamente importante para armazenar a peça.
{
    return pecas[p][r][x][y];
}

void Armazenar_Peca(int x, int y, int peca, int rot) //Armazena a peça na matriz do jogo e aumenta
                                                               //e aumenta a pontuação do jogador em 10 pontos.
{
    int i1, i2,j1,j2;

    for (j1 = y, j2 = 0; j1 < y + 4; j1++, j2++)
    {
        for (i1 = x, i2 = 0; i1 < x + 5; i1++, i2++)
        {

            if (Tipo_Do_Bloco(peca, rot, j2, i2)!= 0)
                matriz[j1][i1] = 1;
        }
    }
    pontuacao+=10;
}
