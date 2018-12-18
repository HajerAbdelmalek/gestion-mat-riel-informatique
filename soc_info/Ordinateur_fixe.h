#pragma once
#include"Machine.h"
class Ordinateur_fixe:public Machine
{
private:
    string graphique;
    int lecteur_carte_mem;
    int lecteur_cd;
    int nbre_ports_HDMI;
    int nbre_ports_USB;
public:
    Ordinateur_fixe(){ } 
    Ordinateur_fixe(string,string,long,float,int,string,int,int,string,string,double,string,double,string,int,int,int,int);
    friend istream& operator>>(istream&,Ordinateur_fixe&);
    friend ostream& operator<<(ostream&,Ordinateur_fixe&);
    virtual void saisir();
    virtual void afficher();
    virtual ~Ordinateur_fixe(void);
};

