#pragma once
#include"Machine.h"
class Ordinateur_portable:public Machine
{
private:
    int camera;
    string graphique;
    int lecteur_carte_mem;
    int lecteur_cd;
    int nbre_ports_HDMI;
    int nbre_ports_USB;
public:
    Ordinateur_portable(){ }
    Ordinateur_portable(string,string,long,float,int,string,int,int,string,string,double,string,double,int,string,int,int,int,int);
    friend istream& operator>>(istream&,Ordinateur_portable&);
    friend ostream& operator<<(ostream&,Ordinateur_portable&);
    virtual void saisir();
    virtual void afficher();
    virtual ~Ordinateur_portable(void);
};

