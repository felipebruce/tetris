#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "ranking.h"
#include "gameover.h"

extern int pontuacao;

void Game_Over() //Fun��o que ocorre logo ap�s a sa�da do loop do jogo.
                 //Solicita ao jogador o nick.
{
     system("cls");
     printf("#Euperdi\n\n");
     Escreve(pontuacao);
     system("cls");
     Leitura_Ranking();
     getch();
     Menu();
}
