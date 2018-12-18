#include "Composant_interne.h"
Composant_interne::Composant_interne(string CAB,string marq,long serial_number,float prix,int remise,string type,string caracteristique):Materiel(CAB,marq,serial_number,prix,remise)
{
    this->type=type;
    this->caracteristique=caracteristique;
}
istream& operator >>(istream& in ,Composant_interne& c)
{
    Materiel *m=&c;
    in>>*m;
    in>>c.type;
    in>>c.caracteristique;
    return in;
}
ostream& operator<<(ostream& out,Composant_interne & c)
{
    Materiel *m=&c;
    out<<*m<<setw(7)<<c.type<<setw(7)<<c.caracteristique<<endl;
    return out;
}
void Composant_interne::saisir()
{
    Materiel::saisir();
    cout<<"Donner le type de composant ";
    cin>>type;
    cout<<"Donner les caracteristiques de composant ";
    cin>>caracteristique;
}


void Composant_interne::afficher()
{
    Materiel::afficher();
    cout<<" Type: "<<type<<" Caracteristiques: "<<caracteristique<<endl;
}

Composant_interne::~Composant_interne(void)
{
}
