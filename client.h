#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <cstring>
#include "ciorba.h"
#include "felPrincipal.h"
#include "garnitura.h"
#include "desert.h"
#include "bautura.h"

using namespace std;

class client{
    string nume = "";
    float nota = 0;
public:
    client(string);
    ~client();
    int comandaClient();
    float get_nota(){return nota;}
    void set_nota(float n){nota = n;}
    string get_nume(){return nume;}
    static string conversie(string sir){
        for(int i = 0; i < sir.size(); i++)
            sir[i] = tolower(sir[i]);
        return sir;
    }
};

client::client(string nu = ""){
    if(nu == "")
    {
       cout << "Numele clientului este: "; cin >> nume;
       cout << endl;
    }
    else nume = nu;
}

client::~client(){
    nume = "";
}

int client::comandaClient(){ ///dialog chelner - client
    string raspuns;
    cout << "Vine chelnerul la masa..." << endl << endl;
    cout << "Chelner: Buna ziua! Va pot lua comanda? (Raspuns DA/NU)" << endl;
    try{
        cout << nume << ": "; cin >> raspuns;
        raspuns = conversie(raspuns);
        if(raspuns != "da" && raspuns != "nu")
            throw 1;
    }
    catch(...){
        do{
            cout << "Se poate raspunde doar cu DA sau NU" << endl;
            cout << nume << ": "; cin >> raspuns;
            raspuns = conversie(raspuns);
        }
        while(raspuns != "da" && raspuns != "nu");
    }
    if(raspuns == "nu")
        {cout << "Chelnerul pleaca de la masa..."; return 1;}
    cout << endl << endl;
    cout << "Chelner: Doriti sa va aduc ciorba? (Raspuns DA/NU)" << endl;
    try{
        cout << nume << ": "; cin >> raspuns;
        raspuns = conversie(raspuns);
        if(raspuns != "da" && raspuns != "nu")
            throw 1;
    }
    catch(...){
        do{
            cout << "Se poate raspunde doar cu DA sau NU" << endl;
            cout << nume << ": "; cin >> raspuns;
            raspuns = conversie(raspuns);
        }
        while(raspuns != "da" && raspuns != "nu");
    }
    cout << endl << endl;
    if(raspuns == "da")
        {
            cout << "Chelner: Ce fel de ciorba doriti? In meniul nostru exista: Ciorba de legume, Ciorba de burta, Ciorba de ciuperci." << endl;
            cout << "Posibile raspunsuri: LEGUME/BURTA/CIUPERCI" << endl;
            try{
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "legume" && raspuns != "burta" && raspuns != "ciuperci")
                    throw 1;
            }
            catch(...){
                do{
                cout << "Se poate raspunde doar cu LEGUME, BURTA sau CIUPERCI" << endl;
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                }
            while(raspuns != "legume" && raspuns != "burta" && raspuns != "ciuperci");
            }
            cout << endl << endl;
            bool sm, ar;
            if(raspuns == "legume")
                {
                    try{
                        cout << "Chelner: Doriti smantana in ciorba de legume? (Raspuns DA/NU)"<<endl;
                        cout << nume << ": "; cin >> raspuns;
                        raspuns = conversie(raspuns);
                        if(raspuns != "da" && raspuns != "nu")
                            throw 1;
                        }
                    catch(...){
                        do{
                        cout << "Se poate raspunde doar cu DA sau NU" << endl;
                        cout << nume << ": "; cin >> raspuns;
                        raspuns = conversie(raspuns);
                        }
                        while(raspuns != "da" && raspuns != "nu");
                    }
                    cout << endl << endl;
                        if(raspuns == "da")
                            sm = true;
                        else
                            sm = false;
                    try{
                        cout << "Chelner: Doriti ardei in ciorba de legume? (Raspuns DA/NU)"<<endl;
                        cout << nume << ": "; cin >> raspuns;
                        raspuns = conversie(raspuns);
                        if(raspuns != "da" && raspuns != "nu")
                            throw 1;
                    }
                    catch(...){
                        do{
                            cout << "Se poate raspunde doar cu DA sau NU" << endl;
                            cout << nume << ": "; cin >> raspuns;
                            raspuns = conversie(raspuns);
                        }
                        while(raspuns != "da" && raspuns != "nu");
                    }
                    cout << endl << endl;
                    if(raspuns == "da")
                        ar = true;
                    else
                        ar = false;
                    ciorbaLegumeBurta A("legume", sm, ar);
                    nota = nota + A.get_pret();
                }
            if(raspuns == "burta")
                {
                    try{
                        cout << "Chelner: Doriti smantana in ciorba de burta? (Raspuns DA/NU)"<<endl;
                        cout << nume << ": "; cin >> raspuns;
                        raspuns = conversie(raspuns);
                        if(raspuns != "da" && raspuns != "nu")
                            throw 1;
                        }
                    catch(...){
                        do{
                        cout << "Se poate raspunde doar cu DA sau NU" << endl;
                        cout << nume << ": "; cin >> raspuns;
                        raspuns = conversie(raspuns);
                        }
                        while(raspuns != "da" && raspuns != "nu");
                    }
                        cout << endl << endl;
                        if(raspuns == "da")
                            sm = true;
                        else
                            sm = false;
                    try{
                        cout << "Chelner: Doriti ardei in ciorba de burta? (Raspuns DA/NU)"<<endl;
                        cout << nume << ": "; cin >> raspuns;
                        raspuns = conversie(raspuns);
                        if(raspuns != "da" && raspuns != "nu")
                            throw 1;
                    }
                    catch(...){
                        do{
                            cout << "Se poate raspunde doar cu DA sau NU" << endl;
                            cout << nume << ": "; cin >> raspuns;
                            raspuns = conversie(raspuns);
                        }
                        while(raspuns != "da" && raspuns != "nu");
                    }
                    cout << endl << endl;
                    if(raspuns == "da")
                        ar = true;
                    else
                        ar = false;
                    ciorbaLegumeBurta A("burta", sm, ar);
                    nota = nota + A.get_pret();
                }
            if(raspuns == "ciuperci")
                {
                    ciorba A;
                    nota = nota + A.get_pret();
                }
            cout << "Noua valoare a notei dupa adaugarea ciorbei este: " << nota << " lei. " << endl;
            cout << endl << endl;
        }
    cout << "Chelner: Doriti sa va aduc fel principal? (Raspuns DA/NU)" << endl;
    try{
        cout << nume << ": "; cin >> raspuns;
        raspuns = conversie(raspuns);
        if(raspuns != "da" && raspuns != "nu")
            throw 1;
    }
    catch(...){
        do{
            cout << "Se poate raspunde doar cu DA sau NU" << endl;
            cout << nume << ": "; cin >> raspuns;
            raspuns = conversie(raspuns);
        }
        while(raspuns != "da" && raspuns != "nu");
    }
    cout << endl << endl;
    bool garnitura = false;
    if(raspuns == "da")
    {
        garnitura = true;
        cout << "Chelner: Ce fel de fel principal doriti? In meniul nostru exista fel principal de pui sau fel principal de vita(Chateaubriand)." << endl;
        cout << "Posibile raspunsuri: PUI/VITA" << endl;
        try{
            cout << nume << ": "; cin >> raspuns;
            raspuns = conversie(raspuns);
            if(raspuns != "pui" && raspuns != "vita")
                throw 1;
        }
        catch(...){
            do{
                cout << "Se poate raspunde doar cu PUI sau VITA" << endl;
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
            }
            while(raspuns != "pui" && raspuns != "vita");
        }
        cout << endl << endl;
        if(raspuns == "pui")
        {
            try{
                cout << "Chelner: Ce fel de fel principal cu pui doriti? In meniul nostru exista TOCANA sau FRIGARUI." << endl;
                cout << "Se poate raspunde doar cu TOCANA sau FRIGARUI" << endl;
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "tocana" && raspuns != "frigarui")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar cu TOCANA sau FRIGARUI" << endl;
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                }
                while(raspuns != "tocana" && raspuns != "frigarui");
            }
            cout << endl << endl;
            if(raspuns == "tocana")
            {
                felPrincipalPui A(raspuns);
                nota = nota + A.get_pret();
            }
            if(raspuns == "frigarui")
            {
                felPrincipalPui A(raspuns);
                nota = nota + A.get_pret();
            }
        }
        if(raspuns == "vita"){
            try{
                cout << "Chelner: Cum sa fie facut Chateaubriandul? Stroganoff sau File?" << endl;
                cout << "Se poate raspunde doar cu STROGANOFF sau FILE." << endl;
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "stroganoff" && raspuns != "file")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar cu STROGANOFF sau FILE" << endl;
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                }
                while(raspuns != "stroganoff" && raspuns != "file");
            }
            cout << endl << endl;
            if(raspuns == "stroganoff")
            {
                felPrincipalVita A(raspuns);
                nota = nota + A.get_pret();
            }
            if(raspuns == "file")
            {
                felPrincipalVita A(raspuns);
                nota = nota + A.get_pret();
            }
        }
        cout << "Noua valoare a notei dupa adaugarea felului principal este: " << nota << " lei. " << endl;
        cout << endl;
    }
    if(garnitura)
    {
        cout << "Chelner: Din moment ce ati cumparat un fel principal va putem sugera o garnitura. Doriti? (Raspuns DA/NU)" << endl;
        try{
            cout << nume << ": "; cin >> raspuns;
            raspuns = conversie(raspuns);
            if(raspuns != "da" && raspuns != "nu")
                throw 1;
        }
        catch(...){
            do{
                cout << "Se poate raspunde doar cu DA sau NU" << endl;
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
            }
            while(raspuns != "da" && raspuns != "nu");
        }
        cout << endl << endl;
        if(raspuns == "da"){
            cout << "Chelner: In meniul nostru exista: cartofi sau orez sarbesc. (Raspuns CARTOFI/OREZ) " << endl;
            try{
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "cartofi" && raspuns != "orez")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar cu CARTOFI sau OREZ" << endl;
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                }
                while(raspuns != "cartofi" && raspuns != "orez");
            }
            cout << endl << endl;
            if(raspuns == "cartofi"){
                cout << "Chelner: Cartofii pot fi PRAJITI sau PIURE. (Raspuns PRAJITI/PIURE) " << endl;
                try{
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                    if(raspuns != "prajiti" && raspuns != "piure")
                        throw 1;
                }
                catch(...){
                do{
                    cout << "Se poate raspunde doar cu PRAJITI sau PIURE" << endl;
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                }
                while(raspuns != "prajiti" && raspuns != "piure");
                }
                cout << endl << endl;
                if(raspuns == "prajiti"){
                    garnituraCartofi A(raspuns);
                    nota = nota + A.get_pret();
                }
                if(raspuns == "piure"){
                    garnituraCartofi B(raspuns);
                    nota = nota + B.get_pret();
                }
            }
            else{
                garnituraOrez C;
                nota = nota + C.get_pret();
            }
            cout << "Noua valoare a notei dupa adaugarea garniturei este: " << nota << " lei. " << endl;
            cout << endl << endl;
        }
    }
    cout << "Chelner: Doriti sa va aduc desert? (Raspuns DA/NU)" << endl;
    try{
        cout << nume << ": "; cin >> raspuns;
        raspuns = conversie(raspuns);
        if(raspuns != "da" && raspuns != "nu")
            throw 1;
    }
    catch(...){
        do{
            cout << "Se poate raspunde doar cu DA sau NU" << endl;
            cout << nume << ": "; cin >> raspuns;
            raspuns = conversie(raspuns);
        }
        while(raspuns != "da" && raspuns != "nu");
    }
    cout << endl << endl;
    if(raspuns == "da")
    {
        cout << "Chelner: Ca si desert avem INGHETATA LA CUPA si TORT KRANTZ. Ce sa aduc? (Raspuns INGHETATA/TORT)" << endl;
        try{
            cout << nume << ": "; cin >> raspuns;
            raspuns = conversie(raspuns);
            if(raspuns != "inghetata" && raspuns != "tort")
                throw 1;
        }
        catch(...){
            do{
                cout << "Se poate raspunde doar cu INGHETATA sau TORT" << endl;
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
            }
            while(raspuns != "inghetata" && raspuns != "tort");
        }
        cout << endl << endl;
        if(raspuns == "inghetata")
        {
            cout << "Chelner: Cate cupe sa aiba inghetata? 3,4 sau 5? (Raspuns 3/4/5)" << endl;
            try{
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "3" && raspuns != "4" && raspuns != "5")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar cu 3, 4 sau 5" << endl;
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                }
            while(raspuns != "3" && raspuns != "4" && raspuns != "5");
            }
            cout << endl << endl;
            if(raspuns == "3"){
                desert A("inghetata", 3);
                nota = nota + A.get_pret();
            }
            if(raspuns == "4"){
                desert A("inghetata", 4);
                nota = nota + A.get_pret();
            }
            if(raspuns == "5"){
                desert A("inghetata", 5);
                nota = nota + A.get_pret();
            }
        }
        else
        {
            desert A("tort");
            nota = nota + A.get_pret();
        }
        cout << "Noua valoare a notei dupa adaugarea desertului este: " << nota << " lei. " << endl;
        cout << endl << endl;
    }
    cout << "Chelner: Trecand peste mancare, doriti ceva de baut? (Raspuns DA/NU)" << endl;
    try{
        cout << nume << ": "; cin >> raspuns;
        raspuns = conversie(raspuns);
        if(raspuns != "da" && raspuns != "nu")
            throw 1;
    }
    catch(...){
        do{
            cout << "Se poate raspunde doar cu DA sau NU" << endl;
            cout << nume << ": "; cin >> raspuns;
            raspuns = conversie(raspuns);
        }
        while(raspuns != "da" && raspuns != "nu");
    }
    cout << endl << endl;
    if(raspuns == "da")
    {
        cout << "Chelner: Oferta noastra cuprinde VIN VARSAT, VIN LA STICLA, BERE, APA, SPRIT" << endl;
        cout << "Se poate raspunde cu VINVARSAT, VINSTICLA, BERE, APA, SPRIT" << endl;
        try{
            cout << nume << ": "; cin >> raspuns;
            raspuns = conversie(raspuns);
            if(raspuns != "vinvarsat" && raspuns != "vinsticla" && raspuns != "bere" && raspuns != "apa" && raspuns != "sprit")
                throw 1;
        }
        catch(...){
            do{
                cout << "Se poate raspunde doar cu VINVARSAT, VINSTICLA, BERE, APA sau SPRIT." << endl;
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
            }
            while(raspuns != "vinvarsat" && raspuns != "vinsticla" && raspuns != "bere" && raspuns != "apa" && raspuns != "sprit");
        }
        cout << endl << endl;
        if(raspuns == "vinvarsat"){
            cout << "Chelner: Vin varsat ROSU sau ALB? (Raspuns ROSU/ALB)" << endl;
            try{
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "rosu" && raspuns != "alb")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar cu ROSU sau ALB." << endl;
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                }
                while(raspuns != "rosu" && raspuns != "alb");
            }
            cout << endl << endl;
            if(raspuns == "rosu"){
                vinVarsat A(true);
                nota = nota + A.get_pret();
            }
            if(raspuns == "alb"){
                vinVarsat A(false);
                nota = nota + A.get_pret();
            }
        }
        if(raspuns == "vinsticla"){
            cout << "Chelner: Restaurantul nostru are 2 optiuni foarte bune de vin la sticla. BORDEUX din 1996 sau CASTEL BOLOVANU din 2004." << endl;
            cout << "Se poate raspunde cu BORDEUX sau BOLOVANU" << endl;
            try{
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "bordeux" && raspuns != "bolovanu")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar cu BORDEUX sau BOLOVANU." << endl;
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                }
                while(raspuns != "bordeux" && raspuns != "bolovanu");
            }
            cout << endl << endl;
            if(raspuns == "bordeux")
            {
                vinSticla A(true);
                nota = nota + A.get_pret();
            }
            else
            {
                vinSticla B(false);
                nota = nota + B.get_pret();
            }
        }
        if(raspuns == "bere"){
            cout << "Chelner: Bere CU alcool sau FARA alcool? (Raspuns CU/FARA)" << endl;
            try{
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "cu" && raspuns != "fara")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar folosind CU sau FARA." << endl;
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                }
                while(raspuns != "cu" && raspuns != "fara");
            }
            cout << endl << endl;
            if(raspuns == "cu"){
                bere A(true);
                nota = nota + A.get_pret();
            }
            else
            {
                bere A(false);
                nota = nota + A.get_pret();
            }
        }
        if(raspuns == "apa"){
            int n;
            cout << "Chelner: Cate sticle de apa? (Pentru numere negative se pune implicit 0)" << endl;
            cout << nume << ": "; cin >> n;
            apa A(n);
            nota = nota + A.get_pret();
            cout << endl << endl;
        }
        if(raspuns == "sprit"){
            cout << "Chelner: Sprit cu vin ROSU sau ALB? (Raspuns ROSU/ALB)" << endl;
            try{
                cout << nume << ": "; cin >> raspuns;
                raspuns = conversie(raspuns);
                if(raspuns != "rosu" && raspuns != "alb")
                    throw 1;
            }
            catch(...){
                do{
                    cout << "Se poate raspunde doar folosind ROSU sau ALB." << endl;
                    cout << nume << ": "; cin >> raspuns;
                    raspuns = conversie(raspuns);
                }
                while(raspuns != "rosu" && raspuns != "alb");
            }
            cout << endl << endl;
            if(raspuns == "rosu"){
                sprit A(true);
                nota = nota + A.get_pret();
            }
            if(raspuns == "alb"){
                sprit A(false);
                nota = nota + A.get_pret();
            }
        }
        cout << "Noua valoare a notei dupa adaugarea bauturii este: " << nota << " lei. " << endl;
        cout << endl << endl;
        return 0;
    }
}

#endif // CLIENT_H_INCLUDED
