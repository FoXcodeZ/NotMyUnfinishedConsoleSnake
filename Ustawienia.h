#pragma once
#include <iostream>
#include <conio.h>
#define sleep() _sleep();


void sterowanie(), sterowanie2(), jedno_osobowa(), wielo_osobowa(), idzdoxy();
void zapisano_dane_mapy(), losowy_wymiar(), wymiar_planszy(), pustamapa();
int szerokosc, wysokosc;
int gora, dol, lewo, prawo, gora2, dol2, lewo2, prawo2;
char wieloosobowa, mapa[35][35];


void idzdoxy(int x, int y)//funkcja przenoszaca kursor w wybrane pozycje
{
    HANDLE pozycja;
    COORD poz;

    // Konwersja z int do short (możliwa utrata danych)
    // Jesli już cchemy konwertować te zmienne to w C++ robimy to np.
    // poz.x = static_cast<short>(x);
    poz.X = x;
    poz.Y = y;

    pozycja = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(pozycja, poz);
}

void losowy_wymiar(int& x) // generowanie losowego rozmiaru mapy
{
    cout << "\tWpisales wartosc poza zakresem, sproboj jeszcze raz";
    cin >> x;

    if (x > 10 || x < 30)
    {
        // Nie używamy przestarzałej wartości NULL na wskaźnikach.
        // W nowym C++ jest coś takiego jak nullptr, to NIE jest to samo co NULL.
        // Poza tym jest nowa funkcja generująca liczby pseudolosowe.
        srand(time(NULL));
        x = rand() % (30 - 11) + 11;
        cout << "\tZnow zle, zrobilem to za ciebie\n";
    }
}

void wymiar_planszy() // podajemy wymiary mapy
{
    cout << "\n\n\tPodaj szerokosc planszy w zakresie od 10 do 30 ";
    cin >> szerokosc;
    if (szerokosc < 10 || szerokosc > 30) losowy_wymiar(szerokosc);

    cout << "\tPodaj wysokosc mapy w zaksesie od 10 do 30 ";
    cin >> wysokosc;
    if (wysokosc < 10 || wysokosc > 30)
    {
        losowy_wymiar(wysokosc);
        Sleep(1000);
    }
    zapisano_dane_mapy();
}

void zapisano_dane_mapy()
{
    system("cls");
    cout << "\n\n\tTwoje dane zosta�y zapisane\n";
    cout << "\tSzerokosc mapy wynosi " << szerokosc << endl;
    cout << "\tWysokosc mapy wynosi " << wysokosc << endl;
    cout << "\tWcisnij dowolny przycisk aby kontynuowac ";
    pustamapa();
    Sleep(1000);

    getch();
    if (wieloosobowa == 'n') jedno_osobowa();
    if (wieloosobowa == 't') wielo_osobowa();
}

void pustamapa() // mapa jako pusta tablica
{
    for (int i = 0; i < szerokosc; i++)
    {
        for (int j = 0; j <= wysokosc; j++)
            mapa[j][i] = 'p';
    }
}

void sterowanie() // sterowanie
{
    system("cls");
    cout << "\n\n\tPodaj klawisze kt�rymi chces sterowac\n";

    cout << "\tGORA\n";
    gora = getch();
    if (gora == 224) gora = gora + getch();
    if (gora == 0) gora = gora - getch();

    cout << "\tDOL\n";
    dol = getch();
    if (dol == 224) dol = dol + getch();
    if (dol == 0) dol = dol - getch();

    cout << "\tLEWO\n";
    lewo = getch();
    if (lewo == 224) lewo = lewo + getch();
    if (lewo == 0) lewo = lewo + getch();

    cout << "\tPRAWO\n";
    prawo = getch();
    if (prawo == 224) prawo = prawo + getch();
    if (prawo == 0) prawo = prawo - getch();

    cout << "\tTwoje klawisze zostaly zapisane\n";
    getch();
    if (wieloosobowa == 'n') jedno_osobowa();
    if (wieloosobowa == 't') wielo_osobowa();
}

void sterowanie2()
{
    system("cls");
    cout << "\n\n\tPodaj klawisze gtorymi bedzie sterowac gracz 2\n";

    cout << "\tGORA\n";
    gora2 = getch();
    if (gora2 == 224) gora2 = gora2 + getch();
    if (gora2 == 0) gora2 = gora2 - getch();

    cout << "\tDOL\n";
    dol2 = getch();
    if (dol2 == 224) dol2 = dol2 + getch();
    if (dol2 == 0) dol2 = dol2 - getch();

    cout << "\tLEWO\n";
    lewo2 = getch();
    if (lewo2 == 224) lewo2 = lewo2 + getch();
    if (lewo2 == 0) lewo2 = lewo2 + getch();

    cout << "\tPRAWO\n";
    prawo2 = getch();
    if (prawo2 == 224) prawo2 = prawo2 + getch();
    if (prawo2 == 0) prawo2 = prawo2 - getch();

    cout << "\tTwoje klawisze zostaly zapisane\n";
    getch();
    wielo_osobowa();
}