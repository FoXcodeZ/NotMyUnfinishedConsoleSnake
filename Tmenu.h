#pragma once
// Ograniczal liczbę includów, niektóre pewnie dodajesz kilka razy, co niepotrzebnie zwiększa rozmiar pliku .exe
// oraz czas komnpilacji programu
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <iomanip>


#define getch() _getch();

// To zły nawyk. Może prowadzić do błędów. napisanie std:: nie zabiera dużo czasu,
// a można też użyć np. using std::string;
using namespace std;

class TMenu
{
public:
    TMenu(string _Title);
    TMenu(void);    // Brak implementacji  tej funkcji.

    void add(string _Name, void (*procedure) ());
    void view();
    void SetTitle(string _Title);   // Brak implementacji tej fukcji


private:
    // Konstruktor nie inicjalizuje tych zmiennych (struktury TItem), co może prowadzić do błędów.
    struct TItem
    {
        string Name;
        void (*procedure)();
    };
    string Title;
    string Max;
    string spac;

    int max;
    int index;

    vector <TItem> List;
};

// _Title jest zarezerwowanym słówkiem przez string, a w parametrach uyżywamy camelCase.
// Warto używać przedrostka w parametrach np. TMenu::TMenu(std::string t_title)
TMenu::TMenu(string _Title)
{
    // Przekazujesz duży obiekt (jakim jest string) przez wartość, a nie przez referencję.
    // Możesz użyć:
    // Title = std::move(_Title);
    // ale lepszym rozwiązaniem jest zmiana nagłówka tego konstruktora na:
    // TMenu::TMenu(const std::string& t_title)
    Title = _Title;
    // Konwersja typów z unsigned long long do int (możliwa utrata danych)
    // A jeśli wiesz, że chcesz konwersji to: max = static_cast<unsigned long long>(Title.size() + 4)
    max = Title.size() + 4;

    index = 0;
}

//
void TMenu::add(string Name, void (*procedure) ())
{
    // W string jest coś takiego jak funkcja empty.
    // Powinno być: if (!Name.empty())
    if (Name != "")
    {
        TItem item;
        item.Name = Name;
        item.procedure = procedure;

        List.push_back(item);
        // Znów konwersja unsigned long long (zmienna Name.size()) na int (zmienna max)
        max = (Name.size() + 4 > max) ? Name.size() + 4 : max;

        Max = "";
        spac = "";
        for (int i = 0; i < max; i++)
        {
            Max += '-';
            spac += ' ';
        }
    }
}

void TMenu::view()
{
    // Konwersja z int do char
    // Użyłeś też złego slasha
    //
    char c = '\0';
    do
    {
        system("cls");

        cout << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "  +" << Max << '+' << endl;

        cout << "  |"
            << spac.substr(0, (max - Title.size()) / 2)
            << Title
            << spac.substr(0, max - Title.size() - ((max - Title.size()) / 2))
            << '|' << endl;

        cout << "  +" << Max.substr(0, max) << '+' << endl;

        for (int i = 0; i < List.size(); i++)
        {
            cout << "  |";
            if (i == index)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }

            cout << spac.substr(0, (max - List[i].Name.size()) / 2)
                << List[i].Name
                << spac.substr(0, (max - (List[i].Name.size()) - (max - List[i].Name.size()) / 2));

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            cout << '|' << endl;
        }

        cout << "  +" << Max << "+";

        c = getch();
        if (c == 72 && index > 0) //dol
        {
            index--;
        }

        if (c == 80 && index < List.size() - 1) //gura
        {
            index++;
        }
    } while (c != 13 && c != 27);

    if (c == 27)
    {
        system("exit");
    }

    if (c == 13)
    {
        //cout << index << endl; //80 dol
        system("cls");
        (*List[index].procedure)();
    }
}