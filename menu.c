#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "desenhos.h"
#include "jogo.h"
#include "menu.h"
#include "ranking.h"

extern int pontuacao;

void Menu() //Utilizada na main para possibilitar o início do jogo, instruções,
           //ranking ou mesmo sair do programa.
{
    pontuacao=0;

    char tecla;

    int y=0;

    system("cls");

    do
    {
        Titulo_Menu();
        if(y==0)
            printf(">> JOGAR\n   RANKING\n   INSTRUCOES\n   SAIR");

        else if(y==1)
            printf("   JOGAR\n>> RANKING\n   INSTRUCOES\n   SAIR");

        else if(y==2)
            printf("   JOGAR\n   RANKING\n>> INSTRUCOES\n   SAIR");

        else if (y==3)
            printf("   JOGAR\n   RANKING\n   INSTRUCOES\n>> SAIR");

        tecla=getch();
        system("cls");
        switch(tecla)
        {
            case 80  :
            case 's' :
            case 'S' : y++; break;

            case 72  :
            case 'w' :
            case 'W' : y--; break;


        }

        if (y>3)
            y=0;
        else if(y<0)
            y=3;

        if (y==0 && tecla==13)
            {system("cls");
            Iniciar_Jogo();
            Jogo();}
        if (y==1 && tecla==13)
            {
             system("cls");
             Leitura_Ranking();
             getch();
             system("cls");
             Menu();
            }
        if (y==2 && tecla==13)
            {
             system("cls");
             Instrucoes();
             getch();
             system("cls");
             Menu();
            }
        if (y==3 && tecla==13)
            exit(0);

    }
    while(1);
}
