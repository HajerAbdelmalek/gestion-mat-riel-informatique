#pragma once
#include"Machine.h"
class Appareil_tactile:public Machine
{
private:
    string type;
    int camera ;
    int camera_frontale;
public:
    Appareil_tactile(){ }
    Appareil_tactile(string,string,long,float,int,string,int,int,string,string,double,string,double,string,int,int);
    friend istream& operator>>(istream&,Appareil_tactile&);
    friend ostream& operator<<(ostream&,Appareil_tactile&);
    virtual void  saisir();
    virtual void afficher();
    virtual ~Appareil_tactile(void);
};

