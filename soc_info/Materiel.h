#pragma once
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
class Materiel
{
protected:
    string CAB;
    string marq;
    long serial_number;
    float prix; 
    int remise;
public:
    Materiel(){ }
    int getremise(){return remise;}
    float getprix(){return prix;}
    long getserialnumb(){return serial_number;}
    Materiel(string,string,long,float,int);
    virtual void saisir();
    virtual void afficher();
    friend istream& operator>>(istream&,Materiel&);
    friend ostream& operator<<(ostream&,Materiel&);
    virtual ~Materiel();

};

