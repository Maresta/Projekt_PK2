#ifndef REKOMENDACJA_H_INCLUDED
#define REKOMENDACJA_H_INCLUDED
#include"lista.h"

//Fukcja wywo�uje rekomendacj� dla argument�w podanych w wierszu polece�,
//jej argumentami s� ilo�� argument� podanych w wierszu polece�, same argumenty oraz wska�nik na pierwszy element listy osoba
void rekomendacja_wiersz(int argc, char*argv[], struct osoba*glowa);

//Funkcja ta pobiera imi� i nazwisko osoby dla,kt�rej ma zosta� wykonana rekomendacja, a nast�pnie wywo�uje funkcj� znajdz i przeka�uj� jej wynik do funkcji sasiedzi,
//jej argumentem jest wska�nik na pierwszy element listy osoba
void rekomendacja(struct osoba*glowa);

//Funkcja szuka w li�cie osoby osoby o podanym imieniu i nazwisku, a nast�pnie zwraca wska�nik elementu zawieraj�cego dan� osob�(W przypadku nie znalezienia zwracana jest warto�� NULL),
//jej argumentami s� wska�nik na pierwszy element listy osoba, imi� i nazwisko szukanej osoby
struct osoba* znajdz(struct osoba*wsk,char imie[100],char nazwisko[100]);

//Funkcja oblicza procentow� zgodno�� wybranego u�ytkownika z reszt� u�ytkownik�w, a nastepnie wywo�uje Funkcje najblizszi_sasiedzi i rekomendowane_zespoly,
//jej argumentami s� wska�nik na pierwszy element listy osoba oraz wska�nik na element u�ytkownika, dla kt�rego tworzona jest rekomendacja
void sasiedzi(struct osoba*user, struct osoba*glowa);

//Funkcja zliacza liczb� ulubionych zespo��w podanego u�ytkownika, a nast�pnie zwraca t� liczb�,
//jej argumentem jest wska�nik na element listy osoba, kt�rego zespo�y maj� zosta� policzone
int licz_zespoly(struct osoba* user);

//Funkcja na podstawie danych wyliczonych przez funckj� sasiedzi wyznacza 10 u�ytkownik�w z najwi�ksz� zgodno�ci� z u�ytkownikiem, dla kt�rego tworzona jest rekomendacja,
//jej argumentami s� tablica wska�nik�w na 10 u�ytownik�w z najwi�ksz� zgodno�ci�, tablica wynik�w zgodno�ci, tablica wska�nik�w na u�ytkownik�w, liczba u�ytkownik�w
 void najblizszi_sasiedzi(struct osoba*bliscy_sasiedzi[],float tab_sasiedzi[],struct osoba* tab_sasiedzi_wsk[],int iterator);

 //Funkcja oblicza ilo�� wyst�pie� ka�ego zespo�u wsr�d "najbli�szych" do u�ytkownika, dla kt�rego tworzona jest rekomendacja, a nast�pnie wywo�uje funkcj� najlepsze_zespoly,
//jej argumentami s� wska�nik na element u�ytkownika, dla kt�rego tworzona jest rekomendacja oraz tablica wska�nik�w na 10 "najbli�szych" u�ytkownik�w
 void rekomendowane_zespoly(struct osoba*user, struct osoba*bliscy_sasiedzi[]);

 //Funkcja wybiera 5 najcz�ciej pojawiaj�cych si� zespo��w wsr�d "najblizszych", a nastepni� wypipusje je na ekran,
//jej argumentami s� tablica z nazwami zespo��w, tablica wynik�w liczby wyst�pie� ka�dego zespo�u wsr�d "najblizszych", liczba tych zespo��w
 void najlepsze_zespoly(char**zespoly[],int wynik_zespoly[],int licznik);


#endif // REKOMENDACJA_H_INCLUDED
