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
#include "ranking.h"
#include "gameover.h"

extern int matriz[LARG][ALT];
extern char pecas[7][4][PECAS][PECAS];
extern int pontuacao;

void Nova_Peca(int *c, int *d) //Gera uma nova peca aleatoria na posição inicial
{
  srand(time(NULL));
            *c=rand()%6;
            *d=rand()%3;
}

void Deletar() //Deleta as linhas ocupadas.
{
	int i,j;
    for (j = 1; j < ALT-1; j++)
    {
        for(i=1; i<=LARG-1; i++)
        {
            if(i == LARG-1)
                {Deletar_Linha(j);
                pontuacao+=100;}
            else if(matriz[j][i] != 1)
                break;
            else
                continue;
        }
    }

}

void Iniciar_Jogo() // Tela inicial Pré-Jogo
{
    int r,q;
    gotoxy(2,9);

    printf("Carregando...");

    gotoxy(1,10);
    for(r=1;r<=16;r++)
    {
        for(q=0;q<=100000000;q++);
        Sleep(100);
        printf("%c",177);
    }
    system("cls");
}

void Jogo() //Função principal do jogo.
{

    srand(time(NULL));
    char tecla;

    int a=0;
    int b=5;
    int c=rand()%6;
    int d=rand()%3;

    int e;
    int f;

    Matriz_Inicial();

    do
    {
        Nova_Peca(&e, &f);
    do
    {
        system("cls");

        Matriz_Atualizada();

        Desenhar_Peca (c,d,b,a);

        gotoxy(22,3);
        if (pontuacao<2)
            printf("%d ponto",pontuacao);
        else
            printf("%d pontos",pontuacao);

        gotoxy(22,5);

        gotoxy(22,13);
        printf  ("%c%c%c%c%c%c",178,178,178,178,178,178);
        gotoxy(22,14);
        printf ("%c    %c",178,178);
        gotoxy(22,15);
        printf ("%c    %c",178,178);
        gotoxy(22,16);
        printf ("%c    %c",178,178);
        gotoxy(22,17);
        printf ("%c    %c",178,178);
        gotoxy(22,18);
        printf  ("%c%c%c%c%c%c",178,178,178,178,178,178);
        Desenhar_Peca_Visualizada(e,f,22,14);

        Sleep(175);

        if(kbhit())
        {

            tecla=getch();
            if(tecla==27)
                break;

            switch(tecla)
            {

                case 75 :
                case 'a':
                case 'A':
                    if ((Check(b-2, a+2, c, d))=='t')
                         b--; break;

                case 77 :
                case 'd':
                case 'D':
                    if ((Check(b+2, a+2, c, d))=='t')

                         b++; break;

                case 80 :
                case 's':
                case 'S':
                    if(Check(b,a+2,c,d)=='t')
                        a++; break;

                case 'h':
                case 'H':
                    while (Check(b,a+3,c,d)=='t')
                         a++;
                         break;

                case 'j':
                case 'J':
                    if((Check(b+1,a+2,c,d+1))=='t' || (Check(b-1,a+2,c,d+1))=='t')
                    {
                        do
                        {
                          d++; break;

                        } while(d>=0 && d<4);

                        if(d>3)
                        {
                          d=0;break;
                        }
                   }
            }
        }

        a++;


    }while(Check(b,a+2,c,d)=='t');

            if(tecla==27)
            break;

            Armazenar_Peca(b,a,c,d);
            Deletar();

            srand(time(NULL));
            b=5;
            a=0;
            c=e;
            d=f;

    }while(Verificar_fim_jogo()!='t');

        Game_Over();



}

void Instrucoes() //Função utilizada no menu para fornecer informações
                  //úteis sobre o jogo.
{
    printf("Tecla\t\t\tFuncao\n\n");
    printf("d ou UP\t\t\tMover a peca para a direita\n");
    printf("a ou LEFT\t\tMover a peca para a esquerda\n");
    printf("s ou DOWN\t\tDescer a peca com maior velocidade\n");
    printf("k\t\t\tDescer a peca instantaneamente\n");
    printf("h\t\t\tRotacionar a peca\n");
    printf("ESC\t\t\tAbandonar o jogo com a pontuacao obtida");
    printf("\n\n\n\nAperte qualquer teclar para voltar para o menu principal...");
}


