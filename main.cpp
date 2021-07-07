#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

   // ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wczytajAdresatowZPliku();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //ksiazkaAdresowa.wylogowanieUzytkownika();
    //ksiazkaAdresowa.logowanieUzytkownika();
   // ksiazkaAdresowa.wczytajAdresatowZPliku();
   // ksiazkaAdresowa.dodajAdresata();
   // ksiazkaAdresowa.wyswietlWszystkichAdresatow();


    return 0;
}
