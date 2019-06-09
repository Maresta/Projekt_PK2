#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include"sqlite3.h"

typedef struct osoba
{
	char imie[100];
	char nazwisko[100];
	struct zespoly *ulubione;
	struct osoba*next;

}osoba;

typedef struct zespoly
{
	char nazwa[100];
	struct zespoly *next;


}zespoly;

//Funkcja przygotowuje plik "Uzytkownicy.db" do odczytu danych, a nastÍpnie wywo≥uje funkcjÍ wczytajOsoba,
//jej argumentem jest wskaünik na pierwszy element listy osoba
void wczytaj(osoba ** glowa);

//Funkcja wczytuje dane uøytkownikÛw i zapisuje je do list,
//jej argumentami sπ wskaünik na otwarty plik "Uzytkownicy.db", liczba kolumn pliku, wskaünik na pierwszy element listy osoba
void wczytajOsobe(sqlite3_stmt *stmt,int kol, osoba**glowa);

//Funkcja wstawia nowo utworzony elemnt listy zespoly na poczπtek listy,
//jej argumentami sπ wskaünik na pierwszy element listy oraz wskaünik na nowo utworzony element
void dodajwezelzespoly(struct osoba* nowa, zespoly *nowy);

//Funkcja wstawia nowo utworzony elemnt listy osoba na poczπtek listy,
//jej argumentami sπ wskaünik na pierwszy element listy oraz wskaünik na nowo utworzony element
void dodajwezelosoby(osoba** glowa, osoba* nowa);

//Funkcja dodaje nowy element do listy zespoly,
//jej argumentami sπ pierwszy elemnt listy osoba oraz nazwa zespolu
void dodajzespol(osoba** nowa, char nazwa[100]);

//Funkcja wyúwietla listÍ uøytkownikÛw("osoba"),
//jej argumentem jest wskaünik na pierwszy element listy osoba
void wyswietl(struct osoba *glowa);

//Funckja wyúwietla ulubione zespo≥y danego uøytkownika,
//jej argumentem jest wskaünik na pierwszy element listy zespoly
void wyswietlUlub(struct zespoly*glowa);

//Funckja usuwa listÍ ulubinych zespo≥Ûw danego uøytkownika,
//jej argumentem jest wskaünik na pierwszy element listy zespo≥y
void usunZespoly(struct zespoly* glowa);

//Funkcja usuwa listÍ uøytkownikÛw("osoba"),
//jej argumentem jest wskaünik na pierwszy element listy
void usun(struct osoba* glowa);




#endif // LISTA_H_INCLUDED
