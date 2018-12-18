#include "Appareil_tactile.h"


Appareil_tactile::Appareil_tactile(string CAB,string marq,long serial_number,float prix,int remise,string processeur,int RAM,int mem_externe,string batterie,string couleur,double poids,string systeme,double taille_ecran,string type,int camera,int camera_frontale):Machine(CAB,marq,serial_number,prix,remise,processeur,RAM,mem_externe,batterie,couleur,poids,systeme,taille_ecran)
{
    this->type=type;
    this->camera=camera;
    this->camera_frontale=camera_frontale;
}
istream& operator>>(istream& in,Appareil_tactile& app)
{
    Machine *m=&app;
    in>>*m;
    //cout<<"Donner le type de l'appareil ";
    in>>app.type;
    //cout<<"Donner les caracteristiques de camera ";
    in>>app.camera;
    //cout<<"Donner les caracteristiques de camera frontale";
    in>>app.camera_frontale;
    return in;
}
ostream& operator<<(ostream& out,Appareil_tactile& app)
{
    Machine *m=&app;
    
    out<<*m<<setw(7)<<app.type<<setw(7)<<app.camera<<setw(7)<<app.camera_frontale<<endl;
    return out;
}


void Appareil_tactile::saisir()
{
    Machine::saisir();
    cout<<"Donner le type de l'appareil ";
    cin>>type;
    cout<<"Donner les caracteristiques de camera ";
    cin>>camera;
    cout<<"Donner les caracteristiques de camera frontale";
    cin>>camera_frontale;
}

void Appareil_tactile::afficher()
{
    Machine::afficher();
    cout<<"Type: "<<type<<" Camera: "<<camera<<" Camera frontale: "<<camera_frontale<<endl;
}




Appareil_tactile::~Appareil_tactile()
{
}
