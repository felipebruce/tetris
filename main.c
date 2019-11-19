#include<stdio.h>
#include<stdlib.h>
#include "menu.h"

#define PECAS 5
#define LARG 15
#define ALT 20

int matriz[LARG][ALT];
char pecas[7][4][PECAS][PECAS]=
{
//****
    {
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,1,2,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {0,0,2,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {1,1,2,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {0,0,2,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
       },
    },
//**
//**
    {
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,1,1,0},
        {0,0,1,2,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,1,1,0},
        {0,0,1,2,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,1,1,0},
        {0,0,1,2,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,1,1,0},
        {0,0,1,2,0},
        {0,0,0,0,0},
       },
    },
// *
//***
    {
        {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,1,2,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        },
        {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,0,2,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        },
        {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,1,2,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        },
        {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,1,2,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        },
    },
//*
//***
    {
       {
        {0,0,0,0,0},
        {0,1,0,0,0},
        {0,1,2,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,1,1,0},
        {0,0,2,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,1,2,1,0},
        {0,0,0,1,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,0,2,0,0},
        {0,1,1,0,0},
        {0,0,0,0,0},
       },
    },
//  *
//***
    {
       {
        {0,0,0,0,0},
        {0,0,0,1,0},
        {0,1,2,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,0,2,0,0},
        {0,0,1,1,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,1,2,1,0},
        {0,1,0,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,1,1,0,0},
        {0,0,2,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
       },
    },
//**
// **
    {
       {
        {0,0,0,0,0},
        {0,1,1,0,0},
        {0,0,2,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,0,1,0},
        {0,0,2,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,1,2,0,0},
        {0,0,1,1,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,1,2,0,0},
        {0,1,0,0,0},
        {0,0,0,0,0},
       },
    },
// **
//**
    {
       {
        {0,0,0,0,0},
        {0,0,1,1,0},
        {0,1,2,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,0,2,1,0},
        {0,0,0,1,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,2,1,0},
        {0,1,1,0,0},
        {0,0,0,0,0},
       },
       {
        {0,0,0,0,0},
        {0,1,0,0,0},
        {0,1,2,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
       },
    },

};
int pontuacao=0;

int main ()
{

    Menu();
    return 0;
}