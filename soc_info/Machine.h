#pragma once
#include"Materiel.h"
class Machine:public Materiel
{
protected:
    string processeur;
    int RAM;
    int mem_externe;
    string batterie;
    string couleur;
    double poids;
    string systeme;
    double taille_ecran;
public:
    Machine(){ };
    Machine(string,string,long,float,int,string,int,int,string,string,double,string,double);
    friend istream& operator>>(istream&,Machine&);
    friend ostream& operator<<(ostream&,Machine&);
    friend ostream& operator<<(ostream&,Machine*);
    virtual void saisir();
    virtual void afficher();

    virtual ~Machine(void);
};

