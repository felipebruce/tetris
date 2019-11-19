#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "verificacoes.h"
#include "desenhos.h"
#define FREE 0
#define PECAS 5
#define LARG 20
#define ALT 24

extern int matriz[LARG][ALT];
extern char pecas[7][4][PECAS][PECAS];


void Desenhar_Peca_Visualizada(int peca, int rot, int b, int a)
{
int i, j;

int realy=a;

for (i=0; i<5;i++)
 {
    for(j=0;j<5;j++)
  {
    {
     if(pecas[peca][rot][j][i]!=0)
     {
        gotoxy(b,a);
        printf("%c",pecas[peca][rot][j][i]);
     }
        a++;
    }
  }

  b++;
  a=realy;
 }
}

void Desenhar_Peca (int peca, int rot, int b, int a)
{
int i, j;

int realy=a;

for (i=0; i<5;i++)
 {
    for(j=0;j<5;j++)
  {
    {
     if(pecas[peca][rot][j][i]!=0)
     {
        if(peca==0 && rot==1)
            gotoxy(b,a+1);
        else if(peca==0 && rot==0)
            gotoxy(b,a-1);
        else if(peca==1)
            gotoxy(b,a-1);
        else if ((peca==2 ||peca==3 || peca==4 || peca==5 || peca==6) && rot==2)
            gotoxy(b,a-1);
        else
            gotoxy(b,a);
        printf("%c",pecas[peca][rot][j][i]);
     }
        a++;
    }
  }

  b++;
  a=realy;
 }
}

void Matriz_Inicial() // Inicia a matriz do jogo com todas as posições livres.
{
    int i, j;

    for (i = 0; i < ALT; i++)
    {
        for (j = 0; j < LARG; j++)
        matriz[i][j]= FREE;
    }
}

void Matriz_Atualizada() // Matriz com peças armazenadas.
{
    int i,j;

    for(i=0;i<ALT;i++)
    {
        for(j=0;j<LARG;j++)
        {
            if(i==0 || i==ALT-1 || j==0 || j==LARG-1)
                putchar(178);

            else
                printf("%c", matriz[i][j]);
        }
        putchar('\n');
    }
}

void Titulo_Menu() //Utilizada para printar o nome do jogo no menu.
{
    gotoxy(15,0);
    printf("  _________ _______ _________ _______ _________ _______\n");
    gotoxy(15,1);
    printf("  \\__   __/(  ____ \\\\__   __/(  ____ )\\__   __/(  ____ \\ \n");
    gotoxy(15,2);
    printf("     ) (   | (    \\/   ) (   | (    )|   ) (   | (    \\/\n");
    gotoxy(15,3);
    printf("     | |   | (__       | |   | (____)|   | |   | (_____\n");
    gotoxy(15,4);
    printf("     | |   |  __)      | |   |     __)   | |   (_____  )\n");
    gotoxy(15,5);
    printf("     | |   | (         | |   | (\\ (      | |         ) |\n");
    gotoxy(15,6);
    printf("     | |   | (____/\\   | |   | ) \\ \\_____) (___/\\____) |\n");
    gotoxy(15,7);
    printf("     )_(   (_______/   )_(   |/   \\__/\\_______/\\_______)\n\n\n");
}

