#include "MetodyPomocnicze.h"
#include <windows.h>
#include <fstream>
#include <sstream>


string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
