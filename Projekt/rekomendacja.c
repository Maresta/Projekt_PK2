#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"rekomendacja.h"
#include"lista.h"

void rekomendacja_wiersz(int argc, char*argv[], struct osoba*glowa)
{
    struct osoba*wsk=glowa;
    wsk=znajdz(wsk,argv[1],argv[2]);
     if(wsk==NULL)
        return;
    sasiedzi(wsk,glowa);
    return;


}

void rekomendacja(struct osoba*glowa)
{
    char imie[100];
    char nazwisko[100];
    printf("Podaj imie: ");
    scanf("%s", imie);
    printf("Podaj nazwisko: ");
    scanf("%s", nazwisko);
    struct osoba*wsk=glowa;
    wsk=znajdz(wsk,imie,nazwisko);
    if(wsk==NULL)
        return;
    sasiedzi(wsk,glowa);
    return;

}


struct osoba* znajdz(struct osoba*wsk,char imie[100],char nazwisko[100])
{
    while (wsk != NULL)
	{
	    if(strncmp(wsk->imie,imie,strlen(imie))==0&&strncmp(wsk->nazwisko,nazwisko,strlen(nazwisko))==0){
            return wsk;
    }
		wsk = wsk->next;
	}
    printf("Nie istnieje taki uzytkownik\n");
    return NULL;
}


int licz_zespoly(struct osoba* user)
{
    int i=0;
    struct zespoly*wsk=user->ulubione;

    while(wsk!=NULL)
    {
        i=i+1;
        wsk=wsk->next;
    }
    return i;
}


void sasiedzi(struct osoba*user, struct osoba*glowa)
{
    typedef int ( * liczenieT)(struct osoba*);
    liczenieT pliczenie=licz_zespoly;
    float *tab_sasiedzi;
    tab_sasiedzi=(float*)malloc(sizeof(*tab_sasiedzi));
    struct osoba **tab_sasiedzi_wsk;
    tab_sasiedzi_wsk=(struct osoba *)malloc(sizeof(*tab_sasiedzi_wsk));
    int iterator=0;
    int liczba_zespolow=pliczenie(user);
    struct zespoly*wsk_zespoly_user=user->ulubione;
    struct osoba *wsk_osoby=glowa;

    while(wsk_osoby!=NULL)
    {
        float suma=0;
        struct zespoly* wsk_zespoly_osoby=wsk_osoby->ulubione;

       if(wsk_osoby!=user)
       {
        while(wsk_zespoly_osoby!=NULL)
        {
            while(wsk_zespoly_user!=NULL)
            {
                if(strcmp(wsk_zespoly_user->nazwa,wsk_zespoly_osoby->nazwa)==0)
                {
                    suma=suma+1;
                }
                wsk_zespoly_user=wsk_zespoly_user->next;
            }
                wsk_zespoly_user=user->ulubione;
            wsk_zespoly_osoby=wsk_zespoly_osoby->next;
        }
        suma=suma/liczba_zespolow;
        tab_sasiedzi[iterator]=suma;
        tab_sasiedzi_wsk[iterator]=wsk_osoby;
        iterator=iterator+1;
        tab_sasiedzi=realloc(tab_sasiedzi,(iterator+1)*sizeof(*tab_sasiedzi));
        tab_sasiedzi_wsk=realloc(tab_sasiedzi_wsk,(iterator+1)*sizeof(*tab_sasiedzi_wsk));
       }
        wsk_osoby=wsk_osoby->next;
    }
    struct osoba*bliscy_sasiedzi[10]={0};

    najblizszi_sasiedzi(bliscy_sasiedzi, tab_sasiedzi, tab_sasiedzi_wsk,iterator);
    rekomendowane_zespoly(user,bliscy_sasiedzi);

    free(tab_sasiedzi);
    free(tab_sasiedzi_wsk);
   return;
}

void rekomendowane_zespoly(struct osoba*user, struct osoba*bliscy_sasiedzi[])
{

    char ** zespoly=(char**) malloc(sizeof(char*));
    zespoly[0]=(char*)malloc(40*sizeof(char));
    int *wynik_zespoly=(int*) malloc(sizeof(int));
    wynik_zespoly[0]=0;
    struct zespoly*wsk_user=user->ulubione;
    int licznik=0;
    for(int i=0; i<10;i++)
    {
        struct zespoly*wsk_sasiad=bliscy_sasiedzi[i]->ulubione;
        while(wsk_sasiad!=NULL)
        {
        int powtorzenie=0;
        while(wsk_user!=NULL)
        {

                     if(strcmp(wsk_user->nazwa,wsk_sasiad->nazwa)==0)
                     {
                         powtorzenie=1;
                     }
              wsk_user=wsk_user->next;
        }
        wsk_user=user->ulubione;
         if(powtorzenie==0)
        {
            int wynik=0;
            for(int k=0;k<licznik;k++)
            {
                if(strcmp(zespoly[k],wsk_sasiad->nazwa)==0)
                {
                    wynik_zespoly[k]=wynik_zespoly[k]+1;
                    wynik=1;
                }
            }
            if(wynik==0)
            {
                zespoly[licznik]=wsk_sasiad->nazwa;
                wynik_zespoly[licznik]=wynik_zespoly[licznik]+1;
                zespoly=realloc(zespoly,(licznik+2)*sizeof(char*));
                zespoly[licznik+1]=(char*)malloc(40*sizeof(char));
                wynik_zespoly=realloc(wynik_zespoly,(licznik+2)*sizeof(int*));
                wynik_zespoly[licznik+1]=0;
                licznik=licznik+1;

            }
        }
        powtorzenie=0;
        wsk_sasiad=wsk_sasiad->next;
        }
    }
najlepsze_zespoly(zespoly,wynik_zespoly,licznik);

for(int i=0;i<licznik;i++)
{
    zespoly[i]=0;

}

for(int i=0;i<licznik+1;i++)
    {
        free(zespoly[i]);
    }

    free(zespoly);
    free(wynik_zespoly);

return;
}

void najlepsze_zespoly(char** zespoly[],int wynik_zespoly[],int licznik)
{
    int indeks[5]={0};

    for(int i=0;i<5;i++)
    {
        for(int k=0;k<licznik;k++)
        {
            if(wynik_zespoly[indeks[i]]<wynik_zespoly[k])
            {
                indeks[i]=k;
            }

        }
        wynik_zespoly[indeks[i]]=0;
    }
   printf("Rekomendowane zespoly: \n");
    for(int i=0;i<5;i++)
    {
        printf("%s\n", zespoly[indeks[i]]);
    }
    return;
}


 void najblizszi_sasiedzi(struct osoba*bliscy_sasiedzi[],float tab_sasiedzi[],struct osoba* tab_sasiedzi_wsk[],int iterator)
{
    int indeks[10]={0};
    for(int k=0;k<10;k++)
    {
    for(int i=0; i<iterator;i++)
    {
             if(tab_sasiedzi[indeks[k]]<tab_sasiedzi[i])
        {
            indeks[k]=i;
        }
    }
    tab_sasiedzi[indeks[k]]=0;
    }
    for(int i=0;i<10;i++)
    {
        bliscy_sasiedzi[i]=tab_sasiedzi_wsk[indeks[i]];
    }
    return;
}



