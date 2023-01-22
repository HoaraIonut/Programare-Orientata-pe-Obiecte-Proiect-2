#ifndef CIORBA_H_INCLUDED
#define CIORBA_H_INCLUDED

using namespace std;


class ciorba{
protected:
    string tip;
    float pret;
public:
    ciorba();
    ~ciorba();
    float get_pret(){return pret;}
};

ciorba::ciorba(){
    pret = 12;
    tip = "ciuperci";
}

ciorba::~ciorba(){
    pret = 0;
    tip = "";
}

class ciorbaLegumeBurta : public ciorba{
    bool ardei = false;
    bool smantana = false;
public:
    ciorbaLegumeBurta(string, bool, bool);
    ~ciorbaLegumeBurta();
};

ciorbaLegumeBurta::ciorbaLegumeBurta(string tip_ciorba, bool ardeib, bool smantanab){
    try{
        if(tip_ciorba != "legume" && tip_ciorba != "burta")
            throw 1;
        else
            tip = tip_ciorba;
        if(tip == "legume")
            pret = 10;
        if(tip == "burta")
            pret = 14;
        if(ardeib)
            {ardei = ardeib; pret += 2;}
        if(smantanab)
            {smantana = smantanab; pret += 2;}
    }
    catch(...){
        cout << "Tipul de ciorba introdus nu este meniu." << endl;
    }
}

ciorbaLegumeBurta::~ciorbaLegumeBurta(){
    ardei = false;
    smantana = false;
}


#endif // CIORBA_H_INCLUDED
