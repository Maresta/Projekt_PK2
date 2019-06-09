#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"sqlite3.h"
#include"lista.h"


void dodajwezelzespoly(struct osoba* nowa, zespoly *nowy)
{
	if (nowa->ulubione == NULL)
	{
		nowa->ulubione = nowy;
		nowy->next = NULL;
	}
	else
	{
		zespoly*pom = nowa->ulubione;
		nowa->ulubione = nowy;
		nowy->next = pom;
	}
return;
}

void dodajwezelosoby(osoba** glowa, osoba* nowa)
{
	while (*glowa != NULL) glowa = &((*glowa)->next);
	*glowa = nowa;
	nowa->next = NULL;
return;
}

void dodajzespol(osoba** nowa, char nazwa[100])
{

	zespoly* nowy = (zespoly*)malloc(sizeof(zespoly));
	strcpy(nowy->nazwa, nazwa);
	dodajwezelzespoly(nowa, nowy);
return;
}

void wczytaj(osoba**glowa)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    sqlite3_open("Uzytkownicy.db", &db);
	if (db == NULL)
	{
		printf("Blad przy probie odczytu\n");
		return 1;
}
sqlite3_prepare_v2(db, "select * from users", -1, &stmt, NULL);
while (sqlite3_step(stmt) != SQLITE_DONE){
        int kol=sqlite3_column_count(stmt);
    wczytajOsobe(stmt,kol,glowa);
}
sqlite3_finalize(stmt);
sqlite3_close(db);
    return;
}

void wczytajOsobe(sqlite3_stmt *stmt, int kol, osoba**glowa)
{
    osoba* nowa = (osoba*)malloc(sizeof(osoba));
    nowa->ulubione=NULL;
     strcpy(nowa->imie,sqlite3_column_text(stmt,0));
     strcpy(nowa->nazwisko,sqlite3_column_text(stmt,1));
     int i;
     for(i=2;i<kol;i++)
     {
         char nazwa[100];
         strcpy(nazwa,sqlite3_column_text(stmt,i));
         if(nazwa[0]!=32);
         dodajzespol(nowa,nazwa);
     }
      dodajwezelosoby(glowa, nowa);
    return;
}


void wyswietl(struct osoba *glowa)
{
	osoba*wsk = glowa;
   printf("Uzytkownicy: ");
	while (wsk != NULL)
	{
		printf("\n\nImie: %s \n", wsk->imie);
		printf("Nazwisko: %s \n", wsk->nazwisko);
		printf("Ulubione: ");
		wyswietlUlub(wsk->ulubione);
		wsk = wsk->next;

	}


	return;
}

void wyswietlUlub(struct zespoly*glowa)
{
	zespoly*wsk = glowa;
	while (wsk != NULL)
	{
		printf("%s, ", wsk->nazwa);


		wsk = wsk->next;

	}
	return;


}

void usun(struct osoba* glowa)
{
	osoba*wsk = glowa;
	while (glowa != NULL)
	{
		if (glowa->ulubione == NULL)
		{
			wsk = glowa->next;
			free(glowa);
			glowa = wsk;

		}
		else
		{
			usunZespoly(glowa->ulubione);
			wsk = glowa->next;
			free(glowa);
			glowa = wsk;
		}
	}
	return;
}

void usunZespoly(struct zespoly* glowa)
{
	struct zespoly* wsk = glowa;
	while (glowa != NULL)
	{
		glowa = wsk->next;
		free(wsk);
		wsk = glowa;
	}
	return;

}

