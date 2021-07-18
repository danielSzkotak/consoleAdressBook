#include "UzytkownikManager.h"
#include "PlikZUzytkownikami.h"


int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}


void UzytkownikManager::wypiszWszystkichUzytkownikow() {

    for (int i = 0; i < uzytkownicy.size(); i++) {

        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }

}

bool UzytkownikManager::czyIstniejeLogin(string login)
{

    for (int i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {

            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;

}


void UzytkownikManager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
   
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);


    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}



int UzytkownikManager::pobierzIdZalogowanegoUzytkownika() {

    return idZalogowanegoUzytkownika;

}

int UzytkownikManager::logowanieUzytkownika() {

    string login = "", haslo = "";

    cout << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < uzytkownicy.size(); i++) {

        if (uzytkownicy[i].pobierzLogin() == login) {

            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                //haslo = MetodyPomocnicze::wczytajLinie();
                cin >> haslo;

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;

        }
    }

    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;

}

bool UzytkownikManager::czyUzytkownikJestZalogowany() {

    if (idZalogowanegoUzytkownika != 0)
        return true;
    else
        return false;
}

void UzytkownikManager::zmianaHaslaZalogowanegoUzytkownika() {

    string noweHaslo = "";
    cout << " >>> ZMIANA HASLA <<<" << endl << endl;
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr->pobierzId() == idZalogowanegoUzytkownika)
        {
            itr->ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }

    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);

}

void UzytkownikManager::wylogowanieUzytkownika() {

    idZalogowanegoUzytkownika = 0;
    cout << "Wylogowales sie" << endl << endl;
    system("pause");

}
