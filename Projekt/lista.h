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

//Funkcja przygotowuje plik "Uzytkownicy.db" do odczytu danych, a nast�pnie wywo�uje funkcj� wczytajOsoba,
//jej argumentem jest wska�nik na pierwszy element listy osoba
void wczytaj(osoba ** glowa);

//Funkcja wczytuje dane u�ytkownik�w i zapisuje je do list,
//jej argumentami s� wska�nik na otwarty plik "Uzytkownicy.db", liczba kolumn pliku, wska�nik na pierwszy element listy osoba
void wczytajOsobe(sqlite3_stmt *stmt,int kol, osoba**glowa);

//Funkcja wstawia nowo utworzony elemnt listy zespoly na pocz�tek listy,
//jej argumentami s� wska�nik na pierwszy element listy oraz wska�nik na nowo utworzony element
void dodajwezelzespoly(struct osoba* nowa, zespoly *nowy);

//Funkcja wstawia nowo utworzony elemnt listy osoba na pocz�tek listy,
//jej argumentami s� wska�nik na pierwszy element listy oraz wska�nik na nowo utworzony element
void dodajwezelosoby(osoba** glowa, osoba* nowa);

//Funkcja dodaje nowy element do listy zespoly,
//jej argumentami s� pierwszy elemnt listy osoba oraz nazwa zespolu
void dodajzespol(osoba** nowa, char nazwa[100]);

//Funkcja wy�wietla list� u�ytkownik�w("osoba"),
//jej argumentem jest wska�nik na pierwszy element listy osoba
void wyswietl(struct osoba *glowa);

//Funckja wy�wietla ulubione zespo�y danego u�ytkownika,
//jej argumentem jest wska�nik na pierwszy element listy zespoly
void wyswietlUlub(struct zespoly*glowa);

//Funckja usuwa list� ulubinych zespo��w danego u�ytkownika,
//jej argumentem jest wska�nik na pierwszy element listy zespo�y
void usunZespoly(struct zespoly* glowa);

//Funkcja usuwa list� u�ytkownik�w("osoba"),
//jej argumentem jest wska�nik na pierwszy element listy
void usun(struct osoba* glowa);




#endif // LISTA_H_INCLUDED
