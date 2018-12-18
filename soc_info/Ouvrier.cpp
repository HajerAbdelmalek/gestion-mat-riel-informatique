#include "Ouvrier.h"
#include<iomanip>
Ouvrier::Ouvrier(void)
{}
Ouvrier::Ouvrier(string nom,string prenom,long CIN,string date,long rib,float salaire):Personne(nom,prenom,CIN,date)
{
	this->rib=rib;
	this->salaire=salaire;
}
istream& operator>>(istream& in,Ouvrier& o)
{
	Personne *p=&o;
	in>>*p;
	in>>o.rib;
	in>>o.salaire;
	return in;
}
ostream& operator<<(ostream& out,Ouvrier& o)
{
	Personne *p=&o;
	out<<*p<<" "<<o.rib<<" "<<o.salaire;
	return out;
}
void Ouvrier::saisir()
{
    Personne::saisir();
    cout<<"donner le rib";
	cin>>rib;
	cout<<"donner la salaire";
	cin>>salaire;
}
void Ouvrier::afficher()
{
    Personne::afficher();
    cout<<"RIB: "<<rib<<endl;
    cout<<"Salaire: "<<salaire<<endl;
}
