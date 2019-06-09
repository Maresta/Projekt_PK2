#include <stdio.h>
#include <stdlib.h>
#include"rekomendacja.h"
#include"lista.h"

void program(int argc, char*argv[])
{

osoba*glowa=NULL;
int opcja;
char wybor;
wczytaj(&glowa);

if(argc>2)
{
    printf("%s %s\n",argv[1],argv[2]);
    rekomendacja_wiersz( argc, argv,glowa);
}

do
{
    printf(" \n MENU \n");
    printf("0. Wyjscie \n");
    printf("1. Wyswietl \n");
    printf("2. Rekomendacja\n");
    scanf(" %c", &wybor);
    opcja=wybor-'0';

    switch(opcja)
    {
    case 1:
                wyswietl(glowa);

        break;
    case 2:
                rekomendacja(glowa);

        break;

    }


}while(opcja!=0);

usun(glowa);

return;
}
