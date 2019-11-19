#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "verificacoes.h"
#include "ranking.h"

 FILE *fptr;

void Escreve(int pontos) //Informa ao jogador a pontuação atingida e solicita um nick ao mesmo.
{

    int pontuacao;
    char nome[255];

    fptr=fopen("rank.txt", "a");


        pontuacao=pontos;

        printf("Sua pontuacao foi: %d\n", pontuacao);
        printf("Digite seu Nick: "); gets(nome);

    fprintf(fptr, "%s\t\t\t%d\n", nome, pontuacao);

    fclose(fptr);
}

void Organizar_Por_Pontuacao(int pontuacao[20],char nomes[20][255], int tamanho) //Utilizada para ordenar o ranking
                                                                                 //Em ordem decrescente de pontuação.
{
    int i,j;
    int trocou;
    for(j=tamanho-1; (j>=1) && (trocou==1); j--)
    {
        trocou = 0;
        for(i=0; i<j; i++)
        {
        if (pontuacao[i] > pontuacao[i+1])
        {
            int p;
            char n[255];
            p = pontuacao[i];
            strcpy(n, nomes[i]);
            pontuacao[i] = pontuacao[i+1];
            strcpy(nomes[i], nomes[i+1]);
            pontuacao[i+1] = p;
            strcpy(nomes[i+1], n);
            trocou = 1;
        }
        }
    }
}

void Leitura_Ranking() //Realiza a leitura do arquivo do ranking e
                       //printa o ranking já com a ordem decrescente.
{
    int tamanho = 0;
    int pontuacao;
    char nomes[20][255];
    int pontuacoes[20];
    char nome[255];
    int i;


fptr=fopen("rank.txt", "r");

    while(fscanf(fptr, "%s\t\t\t%d\n", nome, &pontuacao) != EOF)
    {
        strcpy(nomes[tamanho],nome);
        pontuacoes[tamanho] = pontuacao;
        tamanho++;
    }

    Organizar_Por_Pontuacao(pontuacoes, nomes, tamanho);
    gotoxy(15,0);
    printf("Nome\t\t\tPontuacao\n");

    for (i=0; i<tamanho; i++)
    {
        gotoxy(15,i+1);
        printf("%s\t\t\t%d\n", nomes[i], pontuacoes[i]);
    }
    printf("\n\n\n\nAperte qualquer teclar para voltar para o menu principal...");

  fclose(fptr);
}
