#include "Ordinateur_portable.h"


Ordinateur_portable::Ordinateur_portable(string CAB,string marq,long serial_number,float prix,int remise,string processeur,int RAM,int mem_externe,string batterie,string couleur,double poids,string systeme,double taille_ecran,int camera,string graphique,int lecteur_carte_mem,int lecteur_cd,int nbre_ports_HDMI,int nbre_ports_USB):Machine(CAB,marq,serial_number,prix,remise,processeur,RAM,mem_externe,batterie,couleur,poids,systeme,taille_ecran)
{
    this->camera=camera;
    this->graphique=graphique;
    this->lecteur_carte_mem=lecteur_carte_mem;
    this->lecteur_cd=lecteur_cd;
    this->nbre_ports_HDMI=nbre_ports_HDMI;
    this->nbre_ports_USB=nbre_ports_USB;
}

istream& operator>>(istream& in,Ordinateur_portable& ord)
{
    Machine *m=&ord;
    in>>*m;
    in>>ord.camera;
    in>>ord.graphique;
    in>>ord.lecteur_carte_mem; 
    in>>ord.lecteur_cd;
    in>>ord.nbre_ports_HDMI;
    in>>ord.nbre_ports_USB;
    return in;
}
ostream& operator<<(ostream& out,Ordinateur_portable& ord)
{
    Machine *m=&ord;
    out<<*m<<setw(7)<<ord.camera<<setw(7)<<ord.graphique<<setw(7)<<ord.lecteur_carte_mem<<setw(7)<<ord.lecteur_cd<<setw(7)<<ord.nbre_ports_HDMI<<setw(7)<<ord.nbre_ports_USB<<endl;
    return out;
}
void Ordinateur_portable::saisir()
{
    Machine::saisir();
    do { 
        cout<<"Taper 1 s il existe une camera, 0 sinon " ;
        cin>>camera;
    }
    while(camera !=1 && camera !=0);
    cout<<"Donner les caracteristiques de carte graphique";
    cin>>graphique;
    do{ 
        cout<<"Taper 1 s il existe un lecteur carte memoire, sinon taper 0 ";
        cin>>lecteur_carte_mem;
    }
    while (lecteur_carte_mem !=0 && lecteur_carte_mem !=1);
    do{ 
        cout<<"Taper 1 s il existe un lecteur CD , sinon taper 0 ";
        cin>>lecteur_cd;
    }
    while (lecteur_cd !=0 && lecteur_cd !=1);
    cout<<"Donner le nombre de ports HDMI";
    cin>>nbre_ports_HDMI;
    cout<<"Donner le nombre de ports USB";
    cin>>nbre_ports_USB;
}

void Ordinateur_portable::afficher()
{
    Machine::afficher();
    cout<<" Camera: "<<camera<<" Graphique: "<<graphique<<" Lecteur carte memoire: "<<lecteur_carte_mem<<" Lecteur CD: "<<lecteur_cd<<" Nvre de ports HDMI: "<<nbre_ports_HDMI<<" Nbre ports USB: "<<nbre_ports_USB<<endl;
}

Ordinateur_portable::~Ordinateur_portable(void)
{
}
