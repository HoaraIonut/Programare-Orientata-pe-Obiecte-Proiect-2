#ifndef DESERT_H_INCLUDED
#define DESERT_H_INCLUDED

using namespace std;

class desert{
    int nr = 0;
    float pret;
public:
    desert(string, int);
    ~desert();

    float get_pret(){return pret;}

};

desert::desert(string tip, int nr = 0){
    try{
        if(tip != "tort" && tip != "inghetata")
            throw 1;
        else
        {
            if(nr == 0)
                pret = 7;
            else{
                if(nr < 3 || nr > 5)
                    nr = 3;
                pret = 3 * nr;
            }
        }
    }
    catch(...){
        cout << "Desertul introdus nu este in meniu." << endl;
    }
}

desert::~desert(){
    pret = 0;
    nr = 0;
}


#endif // DESERT_H_INCLUDED
