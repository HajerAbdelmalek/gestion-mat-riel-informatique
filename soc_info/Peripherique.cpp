#include "Peripherique.h"


Peripherique::Peripherique(string CAB,string marq,long serial_number,float prix,int remise,string type,string type_connectivite):Materiel(CAB,marq,serial_number,prix,remise)
{
    this->type=type;
    this->type_connectivite=type_connectivite;
}
istream& operator>>(istream& in, Peripherique& p)
{
    Materiel *m=&p;
    in>>*m;
    in>>p.type;
    in>>p.type_connectivite;
    return in;
}
ostream& operator<<(ostream& out,Peripherique& p)
{
    Materiel *m=&p;
    out<<*m<<setw(7)<<p.type<<setw(7)<<p.type_connectivite<<endl;
    return out;
}
void Peripherique::afficher()
{
    Materiel::afficher();
    cout<<" Type: "<<type<<" Type de connectivite: "<<type_connectivite<<endl;
}
void Peripherique::saisir()
{
    Materiel::saisir();
    cout<<"Donner le type de peripherique ";
    cin>>type;
    cout<<"Donner le type de connectivite ";
    cin>>type_connectivite;
}
Peripherique::~Peripherique(void)
{
}
