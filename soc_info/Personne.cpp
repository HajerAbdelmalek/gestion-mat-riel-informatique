#include "Personne.h"
#include<iomanip>

Personne::Personne(void)
{}
Personne::Personne(string nom,string prenom,long CIN,string date)
{
	this->nom=nom;
	this->prenom=prenom;
	this->CIN=CIN;
    this->date=date;
	
}
ostream& operator<<(ostream& out,Personne& p)
{
	out<<p.nom<<setw(7)<<p.prenom<<setw(7)<<p.CIN<<setw(7)<<p.date;
	return out;
}
istream& operator>>(istream& in,Personne& p)
{
	in>>p.nom;
	in>>p.prenom;
	in>>p.CIN;
	in>>p.date;
       return in ;
}
void Personne::saisir()
{
	cout<<"donner le nom ";
	cin>>nom;
	cout<<"donner le prenom ";
	cin>>prenom;
	cout<<"donner le numero de CIN ";
	cin>>CIN;
	cout<<"donner la date de naissance ";
	cin>>date;
}
void Personne::afficher()
{
    cout<<"Nom:"<<nom<<endl;
    cout<<"Prenom:"<<nom<<endl;
    cout<<"CIN: "<<CIN<<endl;
    cout<<"Date: "<<date<<endl;
}
bool Personne::recherche(long c)
{
	return(this->CIN==c);
}
Personne::~Personne(void)
{
}
