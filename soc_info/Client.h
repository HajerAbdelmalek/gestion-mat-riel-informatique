#pragma once
#include"Personne.h"
class Client:public Personne
{
protected:
    long num_carte_banc;
public:
    Client();
	Client(string,string,long,string,long);
	friend istream& operator>>(istream&,Client&);
	friend ostream& operator<<(ostream&,Client&);
    virtual void saisir();
    virtual void afficher();

	~Client(void);
};
