#include "plikZAdresatami.h"
#include "Adresat.h"
#include <windows.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
	    
        fstream plikTekstowy;
        char znak = ' ';

        plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

        if (plikTekstowy.good() == true)
        {

            plikTekstowy.seekg(0, ios::end);
            if (plikTekstowy.tellg() == 0) {
                return 0; // if empty file return id = 0;
            }

            plikTekstowy.seekg(-3, ios_base::end); // set cursor at one char before end of file and get the char
            plikTekstowy.get(znak);

            while (znak != '\n') {
                plikTekstowy.seekg(-3, std::ios_base::cur);

                if ((int)(plikTekstowy.tellg()) <= 1) { //if there is only one line in file and you can't find end of line sign         
                    plikTekstowy.seekg(0);
                    plikTekstowy.get(znak);

                    return (int)(znak - 48);

                }

                plikTekstowy.get(znak);

            }

            string lastLine="";
            getline(plikTekstowy, lastLine);
            plikTekstowy.close();

            return (int)(lastLine[0] - 48);

        }
        else {
            return 0; // if the file is created first time
        }
    
}


bool PlikZAdresatami::czyPlikJestPusty(fstream& plikTekstowy)
{

    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {

    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;

}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat){

    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (PlikTekstowy::czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata;
        }

 
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;

}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika){

    Adresat adresat;
    vector<Adresat> adresaci;
    idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return adresaci;
    }
    else
        return adresaci;
}


int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch (numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while (isdigit(tekst[pozycjaZnaku]))
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku++;
    }
    return liczba;
}


bool PlikZAdresatami::usunAdresataZPliku(int idUsuwanegoAdresata) {

    fstream plikTekstowy, tymczasowyPlikTekstowy;
    const char* nazwaTymczasowegoPlikuTekstowego_ = nazwaTymczasowegoPlikuTekstowego.c_str();
    string pojedynczaLiniaWPliku="";

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuTekstowego, ios::out);

        while (getline(plikTekstowy, pojedynczaLiniaWPliku)) {

            stringstream ss(pojedynczaLiniaWPliku);
            string IdAdresataWydzieloneZLinii;
            getline(ss, IdAdresataWydzieloneZLinii, '|');

            if (tymczasowyPlikTekstowy.good() == true) {

                    if (IdAdresataWydzieloneZLinii == to_string(idUsuwanegoAdresata)) {
                        // Do nothing
                    }
                    else {

                        if (!czyPlikJestPusty(tymczasowyPlikTekstowy) == true) {

                            tymczasowyPlikTekstowy << endl;
                        }

                        tymczasowyPlikTekstowy << pojedynczaLiniaWPliku;
                    }
            }

        }
    }
    tymczasowyPlikTekstowy.close();
    plikTekstowy.close();

    

    if ((remove(pobierzNazwePliku().c_str()) != 0)) {
            perror("Blad usuwania bazy danych");
            return false;

    } else 

    if (rename(nazwaTymczasowegoPlikuTekstowego_, pobierzNazwePliku().c_str()) != 0) {
            perror("Blad zmiany nazwy pliku bazy danych");
            return false;
    }

    else {
        return true;
        
    }


}

bool PlikZAdresatami::edytujDaneAdresataWPliku(int idEdytowanegoAdresata, Adresat& adresat, int idZalogowanegoUzytkownika) {

    fstream plikTekstowy, tymczasowyPlikTekstowy;
    string nazwaTymczasowegoPlikuTekstowego = "Adresaci_temp.txt";
    const char* nazwaTymczasowegoPlikuTekstowego_ = nazwaTymczasowegoPlikuTekstowego.c_str();
    string pojedynczaLiniaWPliku = "";

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true) {

        tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuTekstowego, ios::out);

        while (getline(plikTekstowy, pojedynczaLiniaWPliku)) {

            stringstream ss(pojedynczaLiniaWPliku);
            string IdAdresataWydzieloneZLinii;
            getline(ss, IdAdresataWydzieloneZLinii, '|');

            if (tymczasowyPlikTekstowy.good() == true) {

                if (IdAdresataWydzieloneZLinii == to_string(idEdytowanegoAdresata)) {
                    
                    if (!czyPlikJestPusty(tymczasowyPlikTekstowy) == true)
                    {
                        tymczasowyPlikTekstowy << endl;
                    }

                    tymczasowyPlikTekstowy << idEdytowanegoAdresata  << "|";
                    tymczasowyPlikTekstowy << idZalogowanegoUzytkownika << "|";
                    tymczasowyPlikTekstowy << adresat.pobierzImie() << "|";
                    tymczasowyPlikTekstowy << adresat.pobierzNazwisko() << "|";
                    tymczasowyPlikTekstowy << adresat.pobierzNumerTelefonu() << "|";
                    tymczasowyPlikTekstowy << adresat.pobierzEmail() << "|";
                    tymczasowyPlikTekstowy << adresat.pobierzAdres() << "|";
                }
                else {
                   

                    if (czyPlikJestPusty(tymczasowyPlikTekstowy) == true)
                    {
                        tymczasowyPlikTekstowy << pojedynczaLiniaWPliku;
                    }
                    else
                    {
                        tymczasowyPlikTekstowy << endl << pojedynczaLiniaWPliku;
                    }
                    
                }
            }

        }
    }
    tymczasowyPlikTekstowy.close();
    plikTekstowy.close();

    if ((remove(pobierzNazwePliku().c_str()) != 0)) {
        perror("Blad usuwania bazy danych");
        return false;

    }
    else

        if (rename(nazwaTymczasowegoPlikuTekstowego_, pobierzNazwePliku().c_str()) != 0) {
            perror("Blad zmiany nazwy pliku bazy danych");
            return false;
        }

        else {
            
            return true;
        }


}