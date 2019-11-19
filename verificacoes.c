#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define FREE 0
#define PECAS 5
#define CX 8
#define CY 1
#define LARG 20
#define ALT 24
#include "peca.h"
#include "verificacoes.h"
#include "desenhos.h"
#include "jogo.h"
#include "menu.h"

extern int matriz[LARG][ALT];
extern char pecas[7][4][PECAS][PECAS];

char Sem_Blocos_Matriz (int x, int y) //Verifica se a posição x e y da matriz é livre.
{
    if (matriz [x][y] == 0)
    return 't';
    else return 'f';
}

char Check(int x, int y, int peca, int rot) //Verifica se o movimento é válido, de a cordo com a mudança
                                            //dos parâmetros.
{
    int i1,i2;
    int j1,j2;

    for (j1 = y, j2 = 0; j1 < y + 4; j1++, j2++)
    {
        for (i1 = x, i2 = 0; i1 < x + 5; i1++, i2++)
        {

            if (i1 < 0 || i1 > LARG-1 || j1 > ALT-1)
            {
                if (Tipo_Do_Bloco(peca,rot,j2,i2)!=0)
                    return 'f';
            }

            if (j1 >= 0)
            {
                if (Tipo_Do_Bloco(peca, rot, j2, i2)!=0 && Sem_Blocos_Matriz(j1-1, i1)=='f')
                    return 'f';
            }
        }
    }
    return 't';
}

char Verificar_fim_jogo() //Verifica se a linha do topo do jogo está ocupada.
{
    int i;
    for(i=0;i<LARG;i++)
       {
           if(matriz[3][i]!=0)
            return 't';
       }
    return 'f';
}

void Deletar_Linha(int lin)//Auxilia a função de deletar a linha.
{
    int i,j;
    for (j = lin; j > 0; j--)
    {
        for (i = 1; i < LARG-1; i++)
            matriz[j][i] = matriz[j-1][i];
    }
}

void gotoxy(int x,int y)
{
  COORD coord;
  coord.Y = y;
  coord.X = x;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
