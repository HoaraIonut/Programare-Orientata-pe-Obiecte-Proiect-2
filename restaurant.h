#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED
#include <vector>
#include <windows.h>
#include "masa.h"

using namespace std;

class restaurant{
    vector<masa*> R;
    int nrMese;
public:
    restaurant(int);
    static string conversie(string sir){
        for(int i = 0; i < sir.size(); i++)
            sir[i] = tolower(sir[i]);
        return sir;
    }
    float get_notaMasa(int nr){
        int c = 1;
        for(auto i = R.begin(); i != R.end(); ++i)
        {
            if(c == nr)
                return (*i)->get_notaMasa();
            c++;
        }
    }
    void afisareCapacitate();
    void generareNotaMasa(int);  ///imi arata cat mai e de platit din comanda la masa
    void plataIndividualMasa(int); ///imi plateste individual client/masa
    void plataColectivMasa(int); ///imi plateste nota la o masa
    void vineChelner(int); ///e luata comanda la o masa
    int get_nrMese(){return nrMese;}
    ~restaurant();
};


restaurant::restaurant(int nr_mese = 0){
    if(nr_mese < 0)
        nrMese = 0;
    else
        nrMese = nr_mese;
    system("CLS");
    for(int i = 1; i <= nrMese; i++)
    {
        cout << "***********************************************************" << endl;
        cout << "MENIU -> CONFIGURARE RESTAURANT" << endl << endl;
        string raspuns;
        try{
            cout << "Masa " << i << " din restaurant ce tip este? " << endl;
            cout << "Posibile raspunsuri: NORMALA, INTALNIRE, PRIETENI" << endl << endl;
            cout << "MASA NORMALA POATE AVEA 3 sau 4 locuri." << endl;
            cout << "MASA INTALNIRE este perfecta pentru un cuplu de INDRAGOSTITI, exista posibilitate achizitionarii unui buchet de flori. (2 locuri)" << endl;
            cout << "MASA PRIETENI este perfecta pentru un grup de PRIETENI, din partea casei restaurantul ofera o bere la toti cei care stau la masa. (5 locuri)"<< endl;
            cout << endl;
            cout << "Utilizator: "; cin >> raspuns;
            raspuns = conversie(raspuns);
            if(raspuns != "normala" && raspuns != "intalnire" && raspuns != "prieteni")
                throw 1;
        }
        catch(...){
            do{
                cout << "Se poate raspunde doar cu: NORMALA, INTALNIRE, PRIETENI" << endl;
                cout << "Utilizator: "; cin >> raspuns;
            }
            while(raspuns != "normala" && raspuns != "intalnire" && raspuns != "prieteni");
        }
        cout << endl;
        if(raspuns == "normala"){
            try{
                cout << "Numarul de locuri MASA NORMALA. 3, 4?" << endl;
                cout << "Utilizator: "; cin >> raspuns;
                if(raspuns != "3" && raspuns != "4")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar cu 3, 4." << endl;
                    cout << "Utilizator: "; cin >> raspuns;
                }
                while(raspuns != "3" && raspuns != "4");
            }
            if(raspuns == "3")
            {
                cout << "Cati oameni sosesc la masa " << i << " cu 3 locuri. 1, 2 sau 3?" << endl;
                try{
                    cout << "Utilizator: "; cin >> raspuns;
                    if(raspuns != "1" && raspuns != "2" && raspuns != "3")
                        throw 1;
                }
                catch(...){
                    do{
                        cout << "Se poate raspunde doar cu 1, 2, 3." << endl;
                        cout << "Utilizator: "; cin >> raspuns;
                    }
                    while(raspuns != "1" && raspuns != "2" && raspuns != "3");
                }
                if(raspuns == "1")
                {
                    masa *A = new masa(1,3);
                    R.push_back(A);
                }
                if(raspuns == "2")
                {
                    masa *A = new masa(2,3);
                    R.push_back(A);
                }
                if(raspuns == "3")
                {
                    masa *A = new masa(3,3);
                    R.push_back(A);
                }
            }
            if(raspuns == "4")
            {
                cout << "Cati oameni sosesc la masa " << i << " cu 4 locuri. 1, 2, 3 sau 4?" << endl;
                try{
                    cout << "Utilizator: "; cin >> raspuns;
                    if(raspuns != "1" && raspuns != "2" && raspuns != "3" && raspuns != "4")
                        throw 1;
                }
                catch(...){
                    do{
                        cout << "Se poate raspunde doar cu 1, 2, 3 sau 4." << endl;
                        cout << "Utilizator: "; cin >> raspuns;
                    }
                    while(raspuns != "1" && raspuns != "2" && raspuns != "3" && raspuns != "4");
                }
                if(raspuns == "1")
                {
                    masa *A = new masa(1,4);
                    R.push_back(A);
                }
                if(raspuns == "2")
                {
                    masa *A = new masa(2,4);
                    R.push_back(A);
                }
                if(raspuns == "3")
                {
                    masa *A = new masa(3,4);
                    R.push_back(A);
                }
                if(raspuns == "4")
                {
                    masa *A = new masa(4,4);
                    R.push_back(A);
                }
            }
        }
        if(raspuns == "intalnire"){
            cout << "Masa " << i << " este de tip INTALNIRE (2 locuri)" << endl;
            cout << "Doriti flori la MASA INTALNIRE? (Raspuns DA/NU)" << endl;
            cout << "Pretul acestora este de 20 lei, sunt achitate de PRIMA PERSOANA CARE PLATESTE INDIVIDUAL sau PLATA COLECTIVA." << endl;
            try{
                cout << "Utilizator: "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "da" && raspuns != "nu")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar cu DA sau NU" << endl;
                    cout << "Utilizator: "; cin >> raspuns;
                }
                while(raspuns != "da" && raspuns != "nu");
            }
            if(raspuns == "da"){
                masaIntalnire *A = new masaIntalnire(true);
                R.push_back(A);
            }
            if(raspuns == "nu"){
                masaIntalnire *A = new masaIntalnire(false);
                R.push_back(A);
            }
        }
        if(raspuns == "prieteni"){
            cout << "Masa " << i << " este de tip PRIETENI (5 locuri)" << endl;
            cout << "Doriti bere gratis la MASA PRIETENI? (Raspuns DA/NU)" << endl;
            cout << "Se ofera 1 bere gratis fiecarui om ce sta la masa." << endl;
            try{
                cout << "Utilizator: "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "da" && raspuns != "nu")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar cu DA sau NU" << endl;
                    cout << "Utilizator: "; cin >> raspuns;
                }
                while(raspuns != "da" && raspuns != "nu");
            }
            if(raspuns == "da"){
                masaPrieteni *A = new masaPrieteni(true);
                R.push_back(A);
            }
            if(raspuns == "nu"){
                masaPrieteni *A = new masaPrieteni(false);
                R.push_back(A);
            }
        }
        cout << "Se salveaza..." << endl;
        Sleep(500);
        system("CLS");
    }
}

restaurant::~restaurant(){
    nrMese = 0;
}

void restaurant::afisareCapacitate(){
    int nr = 1;
    for(auto i = R.begin(); i != R.end(); ++i){
        cout << "Masa numarul " << nr << " are " << (*i)->get_nrClienti() << " locuri ocupate din " << (*i)->get_nrLoc() << " locuri ocupabile." << endl;
        nr++;
    }
}

void restaurant::vineChelner(int nr = 0){
    cout << "Vine Chelnerul la masa " << nr << "..." << endl;
    Sleep(1000);
    system("CLS");
    if(nr <= 0 || nr > nrMese)
        {cout << "Parametrul a fost introdus gresit."; nr = 0;}
    if(nr > 0){
        int c = 1;
        for(auto i = R.begin(); i != R.end(); ++i){
            if(c == nr)
               (*i) -> adaugareClienti();
            c++;
        }
    }
}

void restaurant::generareNotaMasa(int nr){
    if(nr > nrMese || nr <= 0)
        cout << "Parametrul a fost introdus gresit." << endl;
    else{
        int c = 1;
        for(auto i = R.begin(); i != R.end(); ++i){
            if(c == nr)
                (*i) -> actualizareNotaMasa();
            c++;
        }
    }
}

void restaurant::plataIndividualMasa(int nr){
    if(nr > nrMese || nr <= 0)
        cout << "Parametrul a fost introdus gresit." << endl;
    else{
        int c = 1;
        for(auto i = R.begin(); i != R.end(); ++i){
            if(c == nr)
                (*i) -> actualizareNotaMasa();
            c++;
        }
        cout << endl;
        string nume;
        cout << "Persoana care doreste sa achite este: "; cin >> nume;
        c = 1;
        for(auto i = R.begin(); i != R.end(); ++i){
            if(c == nr)
                (*i) -> plataNotaIndividual(nume);
            c++;
        }
    }
}

void restaurant::plataColectivMasa(int nr){
    if(nr > nrMese || nr <= 0)
        cout << "Parametrul a fost introdus gresit." << endl;
    else{
        int c = 1;
        for(auto i = R.begin(); i != R.end(); ++i){
            if(c == nr)
                (*i) -> plataNotaColectiv();
            c++;
        }
    }
}


#endif // RESTAURANT_H_INCLUDED
