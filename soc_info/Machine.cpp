#include "Machine.h"


Machine::Machine(string CAB,string marq,long serial_number,float prix,int remise,string processeur,int RAM,int mem_externe,string batterie,string couleur,double poids,string systeme,double taille_ecran):Materiel(CAB,marq,serial_number,prix,remise)
{
    this->processeur=processeur;
    this->RAM=RAM;
    this->mem_externe=mem_externe;
    this->batterie=batterie;
    this->couleur=couleur;
    this->poids=poids;
    this->systeme=systeme;
    this->taille_ecran=taille_ecran;  
}
istream& operator>>(istream& in,Machine& mach)
{
    Materiel *m=&mach;
    in>>*m;
    in>>mach.processeur;
    in>>mach.RAM;
    in>>mach.mem_externe;
    in>>mach.batterie;
    in>>mach.couleur;
    in>>mach.poids;
    in>>mach.systeme;
    in>>mach.taille_ecran;
    return in;
}
ostream& operator<<(ostream& out,Machine& mach)
{
    Materiel *m=&mach;
    out<<*m<<setw(7)<<mach.processeur<<setw(7)<<mach.RAM<<setw(7)<<mach.mem_externe<<setw(7)<<mach.batterie<<setw(7)<<mach.couleur<<setw(7)<<mach.poids<<setw(7)<<mach.systeme<<setw(7)<<mach.taille_ecran;
    return out;
}
ostream& operator<<(ostream& out,Machine* mach)
{
    Materiel *m=mach;
    out<<*m<<setw(7)<<mach->processeur<<setw(7)<<mach->RAM<<setw(7)<<mach->mem_externe<<setw(7)<<mach->batterie<<setw(7)<<mach->couleur<<setw(7)<<mach->poids<<setw(7)<<mach->systeme<<setw(7)<<mach->taille_ecran;
    return out;
}
void Machine::saisir()
{
    Materiel::saisir();
    cout<<"Donner le type de processeur ";
   cin>>processeur;
    cout<<"Donner le taille de RAM ";
    cin>>RAM;
    cout<<"Donner la taille de la memoire externe ";
    cin>>mem_externe;
    cout<<"Donner le performence de batterie ";
    cin>>batterie;
    cout<<"Donner la couleur ";
    cin>>couleur;
    cout<<"Donner le poids";
    cin>>poids;
    cout<<"Donner le systeme d exploitation ";
    cin>>systeme;
    cout<<"Donner la taille de l ecran ";
    cin>>taille_ecran;
}

 void Machine::afficher()
{
    Materiel::afficher();
    cout<<" Processeur: "<<processeur<<" RAM: "<<RAM<<" Memoire externe: "<<mem_externe<<" Batterie: "<<batterie<<" Couleur: "<<couleur<<" Poids: "<<poids<<" Systeme: "<<systeme<<" Taille: "<<taille_ecran;
}

Machine::~Machine(void)
{
}
