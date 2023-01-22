#ifndef GARNITURA_H_INCLUDED
#define GARNITURA_H_INCLUDED

using namespace std;


class garnitura{
protected:
    string tip;
    float pret;
public:
    garnitura(string);
    ~garnitura();
    float get_pret(){return pret;}

};

garnitura::garnitura(string tipGarnitura = "orez"){
    try{
        if(tipGarnitura != "orez" && tipGarnitura != "cartofi")
            throw 1;
        else
            tip = tipGarnitura;
        if(tip == "orez")
            pret = 15;
    }
    catch(...){
        cout << "Tipul de garnitura introdus nu este in meniul nostru." << endl;
    }
}

garnitura::~garnitura(){
    tip = "";
    pret = 0;
}

class garnituraCartofi : public garnitura{
    string tipCartofi;
public:
    garnituraCartofi(string);
    ~garnituraCartofi();
};

garnituraCartofi::garnituraCartofi(string felCartofi){
    try{
        if(felCartofi != "piure" && felCartofi != "prajiti")
            throw 1;
        else
            tipCartofi = felCartofi;
        if(felCartofi == "piure")
            pret = 13;
        if(felCartofi == "prajiti")
            pret = 14;
    }
    catch(...){
        cout << "Tipul de cartofi introdus nu este in meniul nostru." << endl;
    }
}

garnituraCartofi::~garnituraCartofi(){
    tipCartofi = "";
}



class garnituraOrez : public garnitura{
public:
    garnituraOrez();
    ~garnituraOrez();
};


garnituraOrez::garnituraOrez(){
    tip = "orez";
    pret = 15;
}

garnituraOrez::~garnituraOrez(){
    pret = 0;
}

#endif // GARNITURA_H_INCLUDED
