#include <iostream>
#include "meniu.h"

using namespace std;

/*** schema fisiere header proiect ***/

/**
                                              -> Ciorba
                                              -> Fel Principal
        Meniu -> Restaurant -> Masa -> Client -> Garnitura
                                              -> Desert
                                              -> Bautura
**/


int main()
{
    meniu A;
    A.afisareDatePersonale();
    A.afisareMeniu();
}
