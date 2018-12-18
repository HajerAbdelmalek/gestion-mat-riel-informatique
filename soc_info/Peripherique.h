#pragma once
#include"Materiel.h"
class Peripherique:public Materiel
{
private:
    string type;
    string type_connectivite;
public:
    Peripherique(){ } 
    Peripherique(string,string,long,float,int,string,string);
    friend istream& operator>>(istream&,Peripherique&);
    friend ostream& operator<<(ostream&,Peripherique&);
    virtual void saisir();
    virtual void afficher();
    virtual ~Peripherique(void);
};

