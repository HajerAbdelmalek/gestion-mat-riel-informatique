#include "Materiel.h"


Materiel::Materiel(string CAB,string marq,long serial_number,float prix,int remise)
{
    this->CAB=CAB;
    this->marq=marq;
    this->serial_number=serial_number;
    this->prix=prix;
    this->remise=remise;

}
 istream& operator>>(istream& in,Materiel& mat)
 {
     in>>mat.CAB;
     in>>mat.marq;
     in>>mat.serial_number;
     in>>mat.remise;
     in>>mat.prix;
     return in;
 }
 ostream& operator<<(ostream& out,Materiel& mat)
 {
     out<<setw(7)<<mat.CAB<<setw(7)<<mat.marq<<setw(7)<<mat.serial_number<<setw(7)<<mat.prix<<setw(7)<<mat.remise;
     return out;
 }
 
 void Materiel::afficher()
 {
     cout<<" CAB: "<<CAB<<" Marque: "<<marq<<" Numero de serie: "<<serial_number<<" Prix: "<<prix<<" Remise: "<<remise;

 }
 void Materiel::saisir()
 {
      cout<<"Donne le code a bare ";
     cin>>CAB;
     cout<<"Donner la marque ";
     cin>>marq;
     cout<<"Donner le numero de serie";
     cin>>serial_number;
     cout<<"Donner le pourcentage de remise possible ";
     cin>>remise;
 }
 
Materiel::~Materiel(void)
{
}
