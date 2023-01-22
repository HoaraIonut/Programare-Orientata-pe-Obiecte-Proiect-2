#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED
#include <vector>
#include "restaurant.h"
#include <windows.h>


class meniu{
    bool v[100];
    int n;
    restaurant *A;
public:
    meniu();
    ~meniu();
    void setv(){
        for(int i = 0; i < 100; i++)
            v[i] = false;
    }
    static string conversie(string sir){
        for(int i = 0; i < sir.size(); i++)
            sir[i] = tolower(sir[i]);
        return sir;
    }
    void afisareDatePersonale();
    int afisareMeniu();
    void meniuRestaurant();
    void configurareaRestaurantului();
    void disponibilitateMese();
    void chelnerComanda();
    void plataNota();
    void generareNota();
};

meniu::meniu(){
    A = new restaurant();
    setv();
}

meniu::~meniu(){
    delete A;
}

void meniu::afisareDatePersonale(){
    cout << "~~~~~~~~~PROIECT RESTAURANT~~~~~~~~~" << endl << endl;
    cout << "Nume: Hoara Ionut   Grupa: 211" << endl;
    cout << "Tema: 2  Fisier: Teme 135 - 2014" << endl << endl;
    cout << "Se incarca..." << endl;
    Sleep(1500);
    system("CLS");
}

int meniu::afisareMeniu(){
    system("CLS");
    cout << "***********************************************************" << endl;
    cout << "MENIU " << endl << endl;
    cout << "1. CONFIGURARE RESTAURANT" << endl; ///mentionez cate mese vreau sa aiba restaurantul
    cout << "2. MENIUL RESTAURANTULUI" << endl; ///ce se poate cumpara
    cout << "3. VERIFICARE DISPONIBILITATE MESE" << endl; ///o statistica cu mesele ocupate
    cout << "4. CHELNERUL MERGE SA IA COMANDA" << endl; ///sunt citite datele
    cout << "5. ACHITAREA NOTELOR DE PLATA" << endl; ///plata individuala + plata colectiva
    cout << "6. NOTE DE PLATA" << endl;
    cout << "0. PARASIRE PROGRAM" << endl << endl;
    string o;
    try{
        cout << "Optiunea dumneavoastra: "; cin >> o;
        if(o != "0" && o != "1" && o != "2" && o != "3" && o != "4" && o != "5" && o != "6")
            throw 1;
    }
    catch(...){
        do{
            cout << "Optiunea trebuie cuprinsa intre 0 - 6." << endl;
            cout << "Optiunea dumneavoastra: "; cin >> o;
        }
        while(o != "0" && o != "1" && o != "2" && o != "3" && o != "4" && o != "5" && o != "6");
    }
    if(o == "0")
        return 0;
    if(o == "1")
        {configurareaRestaurantului(); return 1;}
    if(o == "2")
        {meniuRestaurant(); return 2;}
    if(o == "3")
        {disponibilitateMese(); return 3;}
    if(o == "4")
        {chelnerComanda(); return 4;}
    if(o == "5")
        {plataNota(); return 5;}
    if(o == "6")
        {generareNota(); return 6;}
}

void meniu::configurareaRestaurantului(){
    setv();
    system("CLS");
    cout << "Se pregateste configurarea restaurantului...";
    Sleep(750);
    system("CLS");
    cout << "***********************************************************" << endl;
    cout << "MENIU -> CONFIGURARE RESTAURANT" << endl << endl;
    cout << "Pentru a folosi aplicatia de administrare a RESTAURANTULUI DUMNEAVOASTRA, trebuie initial configurat RESTAURANTUL." << endl;
    cout << "Programul ajuta la administrarea unui restaurant ce isi cunoaste numarul de clienti pe baza de rezervare." << endl;
    cout << "Recomand utilizarea unui numar mic de mese pentru testare, dureaza mult introducerea datelor." << endl << endl;
    try{
        cout << "NU INTRODUCETI CARACTERE !!!" << endl;
        cout << "NUMAR MESE RESTAURANT: "; cin >> n;
        if(n < 1)
            throw 1;
    }
    catch(...){
        cout << "Numarul meselor din restaurant trebuie sa fie > 0." << endl;
        do{
            cout << "NU INTRODUCETI CARACTERE !!!" << endl;
            cout << "NUMAR MESE RESTAURANT: "; cin >> n;
        }
        while(n < 1);
    }
    cout << "Se pregateste configurarea fiecarei mese..." << endl;
    Sleep(750);
    A = new restaurant(n);
    system("CLS");
    cout << "Mesele restaurantului au fost configurate. Se pregateste intoarcerea la meniul principal..." << endl;
    Sleep(750);
    afisareMeniu();
}

void meniu::meniuRestaurant(){
    system("CLS");
    cout << "Se pregateste afisarea ofertei restaurantului...";
    Sleep(750);
    system("CLS");
    cout << "***********************************************************" << endl;
    cout << "MENIU -> MENIU RESTAURANT" << endl << endl;
    cout << "\t\tMENIUL RESTAURANTULUI" << endl << endl;
    cout << "CIORBA" << endl;
    cout << "\tCIORBA DE BURTA.....14 lei" << endl;
    cout << "\t\tARDEI/SMANTANA.....+2 lei" << endl;
    cout << "\tCIORBA DE LEGUME.....10 lei" << endl;
    cout << "\t\tARDEI/SMANTANA.....+2 lei" << endl;
    cout << "\tCIORBA DE CIUPERCI.....12 lei" << endl << endl;
    cout << "FEL PRINCIPAL" << endl;
    cout << "\tFEL PRINCIPAL PUI" << endl;
    cout << "\t\tFRIGARUI.....15 lei" << endl;
    cout << "\t\tTOCANA.....20 lei" << endl;
    cout << "\tFEL PRINCIPAL VITA" << endl;
    cout << "\t\tCHATEAUBRIAND STROGANOFF.....30 lei" << endl;
    cout << "\t\tCHATEAUBRIAND FILE....35 lei" << endl << endl;
    cout << "GARNITURA (doar pentru FEL PRINCIPAL)" << endl;
    cout << "\tGARNITURA CARTOFI" << endl;
    cout << "\t\tCARTOFI PRAJITI.....14 lei" << endl;
    cout << "\t\tCARTOFI PIURE.....13 lei" << endl;
    cout << "\tGARNITURA OREZ" << endl;
    cout << "\t\tOREZ SARBESC.....15 lei" << endl;
    cout << "DESERT" << endl;
    cout << "\tDESERT INGHETATA" << endl;
    cout << "\t\tINGHETATA LA CUPA(3-5 cupe).....3 lei cupa" << endl;
    cout << "\tDESERT TORT" << endl;
    cout << "\t\tTORT KRANTZ.....7 lei" << endl << endl;
    cout << "BAUTURI" << endl;
    cout << "\tVIN VARSAT" << endl;
    cout << "\t\tVIN VARSAT ALB.....9 lei(pahar)" << endl;
    cout << "\t\tVIN VARSAT ROSU.....7 lei(pahar)" << endl;
    cout << "\tVIN STICLA" << endl;
    cout << "\t\tBORDEUX DIN 1996.....50 lei" << endl;
    cout << "\t\tCASTEL BOLOVANU 2004.....30 lei" << endl;
    cout << "\tBERE" << endl;
    cout << "\t\tBERE CU ALCOOL.....6 lei" << endl;
    cout << "\t\tBERE FARA ALCOOL.....8 lei" << endl;
    cout << "\tAPA" << endl;
    cout << "\t\tAPA MINERALA.....4 lei(sticla)" << endl;
    cout << "\tSPRIT" << endl;
    cout << "\t\tPACHETUL SPRIT VIN ROSU(3 pahare vin rosu + 1 sticla apa minerala).....20 lei" << endl;
    cout << "\t\tPACHETUL SPRIT VIN ALB(3 pahare vin alb + 1 sticla apa minerala).....30 lei" << endl << endl;
    cout << "Introduceti orice pentru a reveni la meniul principal...";
    string s;
    cin >> s;
    system("CLS");
    cout << "Se pregateste revenirea la meniul principal...";
    Sleep(750);
    system("CLS");
    afisareMeniu();
}

void meniu::disponibilitateMese(){
    system("CLS");
    cout << "Se pregateste afisarea disponibilitatii restaurantului...";
    Sleep(750);
    system("CLS");
    cout << "***********************************************************" << endl;
    cout << "MENIU -> DISPONIBILITATE MESE" << endl << endl;
    if((*A).get_nrMese() == 0)
        cout << "RESTAURANTUL NU A FOST CONFIGURAT" << endl;
    else
        (*A).afisareCapacitate();
    cout << endl;
    cout << "Introduceti orice pentru a reveni la meniul principal...";
    string s;
    cin >> s;
    system("CLS");
    cout << "Se pregateste revenirea la meniul principal...";
    Sleep(750);
    system("CLS");
    afisareMeniu();
}

void meniu::chelnerComanda(){
    system("CLS");
    cout << "Se pregateste afisarea disponibilitatii restaurantului...";
    Sleep(750);
    system("CLS");
    cout << "***********************************************************" << endl;
    cout << "MENIU -> CHELNER IA COMANDA" << endl << endl;
    if((*A).get_nrMese() == 0){
        cout << "RESTAURANTUL INCA NU A FOST CONFIGURAT" << endl;
        cout << "Introduceti orice pentru a reveni la meniul principal...";
        string s;
        cin >> s;
        system("CLS");
        cout << "Se pregateste revenirea la meniul principal...";
        Sleep(750);
        system("CLS");
        afisareMeniu();
    }
    else{
        int nr;
        try{
            cout << "NUMAR MESE: " << (*A).get_nrMese() << endl << endl;

            bool ok = false;
            for(int i = 1; i <= (*A).get_nrMese(); i++)
                if(v[i] == false)
                    ok = true;
            if(ok){
                cout << "In momentul in care introduceti numele celor ce stau la masa, aveti grija sa folositi id-uri diferite pentru persoanele introduse." << endl;
                cout << "Nu introduceti caractere!!!" << endl;
                cout << "Masa la care merge chelnerul: "; cin>>nr;
                if(nr < 1 || nr > (*A).get_nrMese() || v[nr] != false)
                    throw 1;
            }
            else{
                cout << "Chelnerul a luat comanda de la toate masele." << endl;
                cout << "Introduceti orice pentru a reveni la meniul principal...";
            string s;
            cin >> s;
            system("CLS");
            cout << "Se pregateste revenirea la meniul principal...";
            Sleep(750);
            system("CLS");
            afisareMeniu();
            }
        }
        catch(...){
            do{
                if(nr < 1 || nr > (*A).get_nrMese()){
                    cout << "Numarul introdus trebuie sa corespunda unei mese." << endl;
                    cout << "Masa la care merge chelnerul: "; cin>>nr;
                }
                else{
                    cout << "Chelnerul a luat deja comanda la masa " << nr << "." << endl;
                    cout << "Masa la care merge chelnerul: "; cin>>nr;
                }
            }
            while(nr < 1 || nr > (*A).get_nrMese() || v[nr] != false);

        }
        v[nr] = true;
        (*A).vineChelner(nr);
        afisareMeniu();
    }
}

void meniu::plataNota(){
    system("CLS");
    cout << "Se pregateste afisarea meniului achitarea notei...";
    Sleep(750);
    system("CLS");
    cout << "***********************************************************" << endl;
    cout << "MENIU -> ACHITAREA NOTELOR" << endl << endl;
    bool ok = false;
    for(int i = 1; i <= (*A).get_nrMese(); i++)
        if(v[i] == true)
            ok = true;
    if((*A).get_nrMese() == 0 || ok == false){
        if((*A).get_nrMese() == 0)
            cout << "RESTAURANTUL INCA NU A FOST CONFIGURAT" << endl;
        else
            cout << "Chelnerul nu a luat comanda de la mese." << endl;
        cout << "Introduceti orice pentru a reveni la meniul principal...";
        string s;
        cin >> s;
        system("CLS");
        cout << "Se pregateste revenirea la meniul principal...";
        Sleep(750);
        system("CLS");
        afisareMeniu();
    }
    else{
        int nr;
        try{
            cout << "NUMAR MESE: " << (*A).get_nrMese() << endl << endl;
            cout << "Nu introduceti caractere!!!" << endl;
            cout << "Masa la care se achita: "; cin>>nr;
            if(nr < 1 || nr > (*A).get_nrMese() || v[nr] != true)
                    throw 1;
            }
        catch(...){
            do{
                if(nr < 1 || nr > (*A).get_nrMese()){
                    cout << "Numarul introdus trebuie sa corespunda unei mese." << endl;
                    cout << "Masa la care merge chelnerul: "; cin>>nr;
                }
                else{
                    cout << "Chelerul nu a luat comanda la masa " << nr << "." << endl;
                    cout << "Masa la care merge chelnerul: "; cin>>nr;
                }
            }
            while(nr < 1 || nr > (*A).get_nrMese() || v[nr] != true);
        }
        system("CLS");
        cout << "Nota la masa " << nr << "." << endl << endl;
        string raspuns;
        try{
            cout << "Cum se achita? INDIVIDUAL/COLECTIV ?" << endl;
            cout << "Utilizator: "; cin >> raspuns;
            raspuns = conversie(raspuns);
            if(raspuns != "individual" && raspuns != "colectiv")
                throw 1;
        }
        catch(...){
            do{
                cout << "Se poate raspunde doar cu INDIVIDUAL sau COLECTIV." << endl;
                cout << "Utilizator: "; cin >> raspuns;
                raspuns = conversie(raspuns);
            }
            while(raspuns != "individual" && raspuns != "colectiv");
        }
        cout << endl;
        if(raspuns == "colectiv")
            (*A).plataColectivMasa(nr);
        if(raspuns == "individual")
            (*A).plataIndividualMasa(nr);
        system("CLS");
        cout << "Se pregateste intoarcerea la meniul principal..." << endl;
        Sleep(750);
        afisareMeniu();
    }
}

void meniu::generareNota(){
    system("CLS");
    cout << "Se pregateste afisarea meniului achitarea notei...";
    Sleep(750);
    system("CLS");
    cout << "***********************************************************" << endl;
    cout << "MENIU -> AFISAREA NOTELOR DE PLATA" << endl << endl;
    bool ok = true;
    for(int i = 1; i <= (*A).get_nrMese(); i++)
        if(v[i] == true)
            {
                cout << "MASA NUMARUL " << i << ": " << endl;
                (*A).generareNotaMasa(i);
                ok = false;
                cout << endl << endl;
            }
    if(ok)
        cout << "INCA NU A FOST CONFIGURAT RESTAURANTUL sau CHELNERUL NU A LUAT COMENZI" << endl;
    cout << endl;
    cout << "Introduceti orice pentru a reveni la meniul principal...";
    string s;
    cin >> s;
    system("CLS");
    cout << "Se pregateste revenirea la meniul principal...";
    Sleep(750);
    system("CLS");
    afisareMeniu();
}



#endif // MENIU_H_INCLUDED
