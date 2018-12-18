#include "Support_stockage.h"


Support_stockage::Support_stockage(string CAB,string marq,long serial_number,float prix,int remise,string type,int capacite):Materiel(CAB,marq,serial_number,prix,remise)
{
    this->type=type;
    this->capacite=capacite;
}
istream& operator >> (istream& in,Support_stockage& supp)
{
    Materiel *m=&supp;
    in>>*m;
    in>>supp.type;
    in>>supp.capacite;
    return in;
}
ostream& operator<<(ostream& out,Support_stockage& supp)
{
    Materiel *m=&supp;
    out<<*m<<setw(7)<<supp.type<<setw(7)<<supp.capacite<<endl;
    return out;
}
void Support_stockage::saisir()
{
    Materiel::saisir();
    cout<<"Donner le type ";
    cin>>type;
    cout<<"Donner la capacite ";
    cin>>capacite;

}
void Support_stockage::afficher()
{
    Materiel::afficher();
    cout<<" Type: "<<type<<" Capacite: "<<capacite<<endl;
}

Support_stockage::~Support_stockage(void)
{
}
