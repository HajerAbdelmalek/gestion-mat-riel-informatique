#include "Client.h"
#include<iomanip>


Client::Client(string nom,string prenom,long cin,string date,long num_carte_banc):Personne(nom,prenom,cin,date)
{
	this->num_carte_banc=num_carte_banc;
}
Client::Client(void)
{
}

istream& operator>>(istream& in,Client& c)
{
	Personne *p=&c;
	in>>*p;
	in>>c.num_carte_banc;
	return in;
}

ostream& operator<<(ostream& out,Client& c)
{
	Personne *p=&c;
	out<<*p<<" "<<c.num_carte_banc;
       return out ;
}
void Client::saisir()
{
    Personne::saisir();
    cout<<"Saisir le num de carte bancaire\n";
    cin>>num_carte_banc;
}
void Client::afficher()
{
    Personne::afficher();
    cout<<"Carte bancaire"<<num_carte_banc<<endl;
}

Client::~Client(void)
{
}
