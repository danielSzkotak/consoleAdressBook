#pragma once
#include "AdresatManager.h"
#include "plikZAdresatami.h"
#include "UzytkownikManager.h"

AdresatManager::AdresatManager() {

    idOstatniegoAdresata = 1;

}

void AdresatManager::dodajAdresata(int idZalogowanegoUzytkownika) {

    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);

    plikZAdresatami.dopiszAdresataDoPliku(adresat);
   
    ++idOstatniegoAdresata;
    
}

Adresat AdresatManager::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    adresat.ustawId(idOstatniegoAdresata);
   
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());

    //adresat.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.ustawImie());

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    //adresat.nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}



