#pragma once

using namespace std;

//----------definicja klas

// Te klasy mogły by być strukturami. (słówko kluczowe: struct) Nie zawierają żadnych metod, a wszystkie ich składowe są publiczne,
// co NIE jest zgodne z ideą programowania obiektowego.

// Nazwy klas z dużej litery, Snake
class snake
{
public:
	int wspxweza, wspyweza;
	int  dlugoscweza, wynik;
    // W niektórych konfiguracjach, tak duży rozmiar tablicy może nie zostać zarezerwowany,
    // co zakończy działanie programu błędem (przywieszeniem z powodu braku dostępnej pamięci)
    // Rozważył bym użycie innego typu danych, np. vector z biblioteki standardowej STL.
    // std::vector<int> all_positions_x;
    // Swoją drogą nie wiem, czy tego w ogóle potrzebujesz w tej grze.
    // Jeśli chodzi o zapisywanie "ogona" węża, to lepiej zapisywać pozycję jako typ danych, trzymany np. we wspomnianym wcześniej wektorze z STL

	int historiaxweza[10000], historiayweza[10000];
	char kierunek;
};


class jedzenie
{
public:
	int wspxjedzenia, wspyjedzenia;
	char jedzenie;
};