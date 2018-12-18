#pragma once
#include"Personne.h"
class Ouvrier:public Personne
{
private:
	long rib;
	float salaire;
public:
    Ouvrier(void);
	Ouvrier(string,string,long,string,long,float);
	friend istream& operator>>(istream&,Ouvrier&);
	friend ostream& operator<<(ostream&,Ouvrier&);
    friend istream& operator>>(istream&,Ouvrier*);
	friend ostream& operator<<(ostream&,Ouvrier*);
    virtual void saisir();
    virtual void afficher();
    void setsalaire(float s){salaire=s;}
    ~Ouvrier(void) {};
};

