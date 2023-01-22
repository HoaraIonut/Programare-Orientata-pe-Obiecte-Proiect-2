#ifndef MASA_H_INCLUDED
#define MASA_H_INCLUDED
#include <cstring>
#include <vector>
#include "ciorba.h"
#include "felPrincipal.h"
#include "garnitura.h"
#include "desert.h"
#include "bautura.h"
#include "client.h"

using namespace std;

class masa{
protected:
    vector<client> v;
    float notaMasa = 0;
    int nrClienti = 0;
    int nrLoc = 0;
    static float incasari;
    bool adaugareIncasari = false;
public:
    masa(int, int);
    ~masa();
    float get_notaMasa(){return notaMasa;}
    int get_nrLoc(){return nrLoc;}
    int get_nrClienti(){return nrClienti;}
    static float get_incasari(){return incasari;}
    void adaugareClienti();
    virtual void actualizareNotaMasa();
    virtual void plataNotaColectiv();
    virtual void plataNotaIndividual(string);
};

masa::masa(int nr_clienti = 1, int nr_loc = 4){
    nrLoc = nr_loc;
    if(nr_clienti < nrLoc)
        nrClienti = nr_clienti;
    else
        nrClienti = nrLoc;
}

masa::~masa(){
    notaMasa = 0;
    nrClienti = 0;
}

void masa::adaugareClienti(){
    for(int i = 0; i < nrClienti; i++){
        cout << "***********************************************************" << endl;
        client A;
        A.comandaClient();
        v.push_back(A);
        system("CLS");
    }
}

float masa::incasari = 0;

void masa::actualizareNotaMasa(){
    notaMasa = 0;
    for(auto i = v.begin(); i != v.end(); ++i){
        notaMasa = notaMasa + (*i).get_nota();
        cout << (*i).get_nume() << " trebuie sa achite in valoare de " << (*i).get_nota() << " lei." << endl;
    }
    cout << endl;
    cout << "Nota mesei este: " << notaMasa << " lei." << endl << endl;
    if(!adaugareIncasari)
    {
        incasari = incasari + notaMasa;
        adaugareIncasari = true;
    }
}

void masa::plataNotaColectiv(){
    for(auto i = v.begin(); i != v.end(); ++i){
        (*i).set_nota(0);
    }
    notaMasa = 0;
    cout << "Nota a fost achitata colectiv. " << endl;
}

void masa::plataNotaIndividual(string s){
    try{
        bool ok = false;
        for(auto i = v.begin(); i != v.end(); ++i)
            if((*i).get_nume() == s)
            {
                ok = true;
                notaMasa = notaMasa - (*i).get_nota();
                (*i).set_nota(0);
            }
        if(!ok)
            throw 1;
    }
    catch(...){
        cout << endl << endl << "Persoana introdusa nu se afla la masa. " << endl << endl;
    }
}

class masaIntalnire : public masa{
    bool flori = true;
public:
    masaIntalnire(bool);
    void actualizareNotaMasa();
    void plataNotaColectiv();
    void plataNotaIndividual(string);
    ~masaIntalnire();
};

masaIntalnire::masaIntalnire(bool ok = true){
    nrLoc = 2;
    nrClienti = 2;
    flori = ok;
    if(flori)
        notaMasa = 20;
    else
        notaMasa = 0;
}

masaIntalnire::~masaIntalnire(){
    flori = false;
}

void masaIntalnire::actualizareNotaMasa(){
    if(flori)
        notaMasa = 20;
    else
        notaMasa = 0;
    for(auto i = v.begin(); i != v.end(); ++i){
        notaMasa = notaMasa + (*i).get_nota();
        cout << (*i).get_nume() << " trebuie sa achite in valoare de " << (*i).get_nota() << " lei." << endl;
    }
    cout << endl;
    if(!flori)
        cout << "Nota mesei este: " << notaMasa << " lei." << endl << endl;
    else
        cout << "Nota mesei cu tot cu florile cumparate este: " << notaMasa << " lei." << endl << endl;
}

void masaIntalnire::plataNotaIndividual(string s){
     try{
        bool ok = false;
        for(auto i = v.begin(); i != v.end(); ++i)
            if((*i).get_nume() == s)
            {
                ok = true;
                notaMasa = notaMasa - (*i).get_nota();
                if(flori)
                    notaMasa = notaMasa - 20;
                (*i).set_nota(0);
                flori = false;
            }
        if(!ok)
            throw 1;
    }
    catch(...){
        cout << endl << endl << "Persoana introdusa nu se afla la masa. " << endl << endl;
    }
}

void masaIntalnire::plataNotaColectiv(){
    for(auto i = v.begin(); i != v.end(); ++i){
        (*i).set_nota(0);
    }
    notaMasa = 0;
    cout << "Nota a fost achitata colectiv. " << endl;
    flori = false;
}

class masaPrieteni : public masa{
    bool ofertaBere;
public:
    masaPrieteni(bool);
    ~masaPrieteni();
    void actualizareNotaMasa();
};

masaPrieteni::masaPrieteni(bool ok){
    ofertaBere = ok;
    nrLoc = 5;
    nrClienti = 5;
}

masaPrieteni::~masaPrieteni(){
    ofertaBere = false;
}

void masaPrieteni::actualizareNotaMasa(){
    notaMasa = 0;
    for(auto i = v.begin(); i != v.end(); ++i){
        notaMasa = notaMasa + (*i).get_nota();
        cout << (*i).get_nume() << " trebuie sa achite in valoare de " << (*i).get_nota() << " lei." << endl;
    }
    cout << endl;
    cout << "Nota mesei este: " << notaMasa << " lei." << endl << endl;
    if(!adaugareIncasari)
    {
        incasari = incasari + notaMasa;
        adaugareIncasari = true;
    }
    if(ofertaBere)
        cout << "Pe langa cele comandate fiecare om de la masa a primit si o bere!" << endl << endl;
}

#endif // MASA_H_INCLUDED
