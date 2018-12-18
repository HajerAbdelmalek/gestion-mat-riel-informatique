#pragma once
#include"Materiel.h"
class Support_stockage:public Materiel
{
private:
    string type;
    int capacite;

public:
    Support_stockage(){ }
    Support_stockage(string,string,long,float,int,string,int);
    friend istream & operator>>(istream&,Support_stockage&);
    friend ostream& operator <<(ostream&,Support_stockage&);
    virtual void saisir();
    virtual void afficher();
    virtual ~Support_stockage(void);
};

