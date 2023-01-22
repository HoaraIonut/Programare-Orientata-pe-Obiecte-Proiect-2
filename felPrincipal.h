#ifndef FELPRINCIPAL_H_INCLUDED
#define FELPRINCIPAL_H_INCLUDED

using namespace std;

class felPrincipal{
protected:
    string tip;
    float pret;
public:
    felPrincipal(string);
    ~felPrincipal();
    float get_pret(){return pret;}
};

felPrincipal::felPrincipal(string tipFel = "pui")
{
    try{
    if(tipFel != "pui" && tipFel != "vita")
        throw 1;
    else
        tip = tipFel;
    }
    catch(...){
        cout << "Felul principal introdus nu este in meniul nostru." << endl;
    }
}

felPrincipal::~felPrincipal(){
    tip = "";
    pret = 0;
}

class felPrincipalPui : public felPrincipal{
    string tipPui;
public:
    felPrincipalPui(string);
    ~felPrincipalPui();
    void afisareFelPrincipalPui(){cout << "Felul principal de pui ales este " << tipPui << ", iar pretul acestuia este " << pret;}
};

felPrincipalPui::felPrincipalPui(string tipPuiFel){
    try{
        if(tipPuiFel != "frigarui" && tipPuiFel != "tocana")
            throw 1;
        else
            tipPui = tipPuiFel;
        if(tipPui == "frigarui")
            pret = 15;
        if(tipPui == "tocana")
            pret = 20;
    }
    catch(...){
        cout << "Tipul de Fel Principal-Pui nu exista in meniul nostru." << endl;
    }
}

felPrincipalPui::~felPrincipalPui(){
    tipPui = "";
}

class felPrincipalVita : public felPrincipal{
    string tipCB;
public:
    felPrincipalVita(string);
    ~felPrincipalVita();
    void afisareFelPrincipalVita(){cout << "Felul principal de vita este Chateaubriand, iar pretul acestuia este " << pret;};
};

felPrincipalVita::felPrincipalVita(string tipChB){
    try{
        if(tipChB != "stroganoff" && tipChB != "file")
            throw 1;
        else
            tipCB = tipChB;
        if(tipCB == "stroganoff")
            pret = 30;
        if(tipCB == "file")
            pret = 35;
    }
    catch(...){
        cout << "Nu preparam Chateaubriand ul in modul mentionat." << endl;
    }
}

felPrincipalVita::~felPrincipalVita(){
    tipCB = "";
}


#endif // FELPRINCIPAL_H_INCLUDED
