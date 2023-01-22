#ifndef BAUTURA_H_INCLUDED
#define BAUTURA_H_INCLUDED

using namespace std;

class bautura{
protected:
    float pret = 0;
    string denumire;
public:
    bautura(string);
    ~bautura();
    float get_pret(){return pret;}
};

bautura::bautura(string den = "apa"){
    try{
        if(den != "vinVarsat" && den != "vinSticla" && den != "apa" && den != "bere" && den != "sprit")
            throw 1;
        else
            denumire = den;
    }
    catch(...){
        cout << "Bautura introdusa nu este in meniu." << endl;
    }
}

bautura::~bautura(){
    denumire = "";
    pret = 0;
}

class vinVarsat : virtual public bautura{
protected:
    bool rosualb;
public:
    vinVarsat(bool);
    ~vinVarsat();
};

vinVarsat :: vinVarsat(bool ra = "true"){
    rosualb = ra;
    if(ra)
        {pret = 7;}
    else
        {pret = 9;}
    denumire = "vinVarsat";
}

vinVarsat :: ~vinVarsat(){
    rosualb = false;
}

class vinSticla : public bautura{
public:
    vinSticla(bool);
    ~vinSticla();
};

vinSticla :: vinSticla(bool tip = true){
    denumire = "vinSticla";
    if(tip)
        pret = 50;
    if(!tip)
        pret = 30;
}
vinSticla :: ~vinSticla(){
    pret = 0;
}

class bere : public bautura{
    bool alcool;
public:
    bere(bool);
    ~bere();
};

bere::bere(bool al = true){
    denumire = "bere";
    if(al)
        pret = 6;
    else
        pret = 8;
}

bere::~bere(){
    pret = 0;
}

class apa : virtual public bautura{
protected:
    int nr_sticle;
public:
    apa(int);
    ~apa();
};

apa::apa(int nr = 0){
    if(nr < 0)
        nr_sticle = 0;
    else
        nr_sticle = nr;
    pret = 4 * nr_sticle;
}

apa::~apa(){
    pret = 0;
}

class sprit : public apa, public vinVarsat{
public:
    sprit(bool);
    ~sprit();
};

sprit::sprit(bool tip_vin){
    denumire = "sprit";
    rosualb = tip_vin;
    nr_sticle = 1;
    if(rosualb)
        pret = 20;
    else
        pret = 30;
}

sprit::~sprit(){
    pret = 0;
}


#endif // BAUTURA_H_INCLUDED
