#ifndef REKOMENDACJA_H_INCLUDED
#define REKOMENDACJA_H_INCLUDED
#include"lista.h"

//Fukcja wywo³uje rekomendacjê dla argumentów podanych w wierszu poleceñ,
//jej argumentami s¹ iloœæ argumentó podanych w wierszu poleceñ, same argumenty oraz wskaŸnik na pierwszy element listy osoba
void rekomendacja_wiersz(int argc, char*argv[], struct osoba*glowa);

//Funkcja ta pobiera imiê i nazwisko osoby dla,której ma zostaæ wykonana rekomendacja, a nastêpnie wywo³uje funkcjê znajdz i przeka¿ujê jej wynik do funkcji sasiedzi,
//jej argumentem jest wskaŸnik na pierwszy element listy osoba
void rekomendacja(struct osoba*glowa);

//Funkcja szuka w liœcie osoby osoby o podanym imieniu i nazwisku, a nastêpnie zwraca wskaŸnik elementu zawieraj¹cego dan¹ osobê(W przypadku nie znalezienia zwracana jest wartoœæ NULL),
//jej argumentami s¹ wskaŸnik na pierwszy element listy osoba, imiê i nazwisko szukanej osoby
struct osoba* znajdz(struct osoba*wsk,char imie[100],char nazwisko[100]);

//Funkcja oblicza procentow¹ zgodnoœæ wybranego u¿ytkownika z reszt¹ u¿ytkowników, a nastepnie wywo³uje Funkcje najblizszi_sasiedzi i rekomendowane_zespoly,
//jej argumentami s¹ wskaŸnik na pierwszy element listy osoba oraz wskaŸnik na element u¿ytkownika, dla którego tworzona jest rekomendacja
void sasiedzi(struct osoba*user, struct osoba*glowa);

//Funkcja zliacza liczbê ulubionych zespo³ów podanego u¿ytkownika, a nastêpnie zwraca t¹ liczbê,
//jej argumentem jest wskaŸnik na element listy osoba, którego zespo³y maj¹ zostaæ policzone
int licz_zespoly(struct osoba* user);

//Funkcja na podstawie danych wyliczonych przez funckjê sasiedzi wyznacza 10 u¿ytkowników z najwiêksz¹ zgodnoœci¹ z u¿ytkownikiem, dla którego tworzona jest rekomendacja,
//jej argumentami s¹ tablica wskaŸników na 10 u¿ytowników z najwiêksz¹ zgodnoœci¹, tablica wyników zgodnoœci, tablica wskaŸników na u¿ytkowników, liczba u¿ytkowników
 void najblizszi_sasiedzi(struct osoba*bliscy_sasiedzi[],float tab_sasiedzi[],struct osoba* tab_sasiedzi_wsk[],int iterator);

 //Funkcja oblicza iloœæ wyst¹pieñ ka¿ego zespo³u wsród "najbli¿szych" do u¿ytkownika, dla którego tworzona jest rekomendacja, a nastêpnie wywo³uje funkcjê najlepsze_zespoly,
//jej argumentami s¹ wskaŸnik na element u¿ytkownika, dla którego tworzona jest rekomendacja oraz tablica wskaŸników na 10 "najbli¿szych" u¿ytkowników
 void rekomendowane_zespoly(struct osoba*user, struct osoba*bliscy_sasiedzi[]);

 //Funkcja wybiera 5 najczêœciej pojawiaj¹cych siê zespo³ów wsród "najblizszych", a nastepniê wypipusje je na ekran,
//jej argumentami s¹ tablica z nazwami zespo³ów, tablica wyników liczby wyst¹pieñ ka¿dego zespo³u wsród "najblizszych", liczba tych zespo³ów
 void najlepsze_zespoly(char**zespoly[],int wynik_zespoly[],int licznik);


#endif // REKOMENDACJA_H_INCLUDED
