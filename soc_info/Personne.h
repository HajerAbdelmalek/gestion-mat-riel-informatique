#pragma once
#include<iostream>
#include<string>
using namespace std;
class Personne
{
protected:
	string nom;
	string prenom;
	long CIN;
	string date;

public:
    Personne(void);
    Personne(string,string,long, string);
	bool recherche(long);
	friend ostream& operator<<(ostream&,Personne&);
	friend istream& operator>>(istream&,Personne&);
    virtual void saisir();
    virtual void afficher();

    void setnom(string n){nom=n;}
	string getnom(){return nom;}
	string getprenom(){return prenom;}
    void setprenom(string p){prenom=p;}
    long getcin(){ return CIN; };
	virtual ~Personne(void);
};
