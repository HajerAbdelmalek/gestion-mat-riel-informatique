#pragma once
#include"Materiel.h"
class Composant_interne:public Materiel
{
private:
    string type;
    string caracteristique;
public:
    Composant_interne(){ }
    Composant_interne(string,string,long,float,int,string,string);
    friend istream& operator >>(istream&,Composant_interne&);
    friend ostream& operator<<(ostream&,Composant_interne&);
    virtual void saisir();
    virtual void afficher();
    virtual ~Composant_interne(void);
};

