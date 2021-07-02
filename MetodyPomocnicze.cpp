#pragma once
#include "MetodyPomocnicze.h"
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::wczytajLinie()
{
    cin.ignore();
    string wejscie = "";
    cin >> wejscie;
    return wejscie;
    
}
