#include "Societe.h"
#include"Client.h"
#include"Ouvrier.h"
#include"Composant_interne.h"
#include"Ordinateur_fixe.h"
#include"Ordinateur_portable.h"
#include"Appareil_tactile.h"
#include"Support_stockage.h"
#include"Peripherique.h"
#include<fstream>
const string Societe::raison_sociale="info";
const string Societe::adresse="https://www.google.tn/maps/place/Ecole+Nationale+d'Ing%C3%A9nieurs+de+Carthage/@36.8517";
Societe::Societe(void)
{}

Societe::Societe(int capital,string email_contact,string URL_web)
{
    this->capital=capital;
    this->email_contact=email_contact;
    this->URL_web=URL_web;   
}
Societe::Societe(const Societe& s)
{
    Personne* p;
    Materiel* m;
    capital=s.capital;
    email_contact=s.email_contact;
    URL_web=s.URL_web;
    for(int i=0;i<s.tab_pers.size();i++)
    {
        if (typeid(s.tab_pers[i])==typeid(Client))
            p=new Client(static_cast<const Client&>(*tab_pers[i]));
        if (typeid(s.tab_pers[i])==typeid(Ouvrier))
            p=new Ouvrier(static_cast<const Ouvrier&>(*tab_pers[i]));
        tab_pers.push_back(p);

    }
    for (int j=0;j<s.tab_materiel.size();j++)
    {
        if (typeid(s.tab_materiel[j])==typeid(Composant_interne))
            m=new Composant_interne(static_cast<const Composant_interne & >(*tab_materiel[j]));
        if (typeid(s.tab_materiel[j])==typeid(Ordinateur_fixe))
            m=new Ordinateur_fixe(static_cast<const Ordinateur_fixe & >(*tab_materiel[j]));
        if (typeid(s.tab_materiel[j])==typeid(Ordinateur_portable))
            m=new Ordinateur_portable(static_cast<const Ordinateur_portable & >(*tab_materiel[j]));
        if (typeid(s.tab_materiel[j])==typeid(Appareil_tactile))
            m=new Appareil_tactile(static_cast<const Appareil_tactile & >(*tab_materiel[j]));
        if (typeid(s.tab_materiel[j])==typeid(Support_stockage))
            m=new Support_stockage(static_cast<const Support_stockage & >(*tab_materiel[j]));
        if (typeid(s.tab_materiel[j])==typeid(Peripherique))
            m=new Peripherique(static_cast<const Peripherique & >(*tab_materiel[j]));
        tab_materiel.push_back(m);

    }
}
Societe& Societe::operator=(const Societe s)
{
    Personne *p;
    Materiel* m;
    if (this!=&s)
    { 
        for (int i=0;i<tab_pers.size();i++)
        {
            delete tab_pers[i];
            tab_pers.clear();
            if (typeid(s.tab_pers[i])==typeid(Client))
                p=new Client(static_cast<const Client&>(*tab_pers[i]));
            if (typeid(s.tab_pers[i])==typeid(Ouvrier))
                p=new Ouvrier(static_cast<const Ouvrier&>(*tab_pers[i]));
            tab_pers.push_back(p);
        }
        for (int i=0;i<tab_materiel.size();i++)
        {
            delete tab_materiel[i];
            tab_materiel.clear();
            if (typeid(s.tab_materiel[i])==typeid(Ordinateur_portable))
                m=new Ordinateur_portable(static_cast<const Ordinateur_portable&>(*tab_materiel[i]));
            if (typeid(s.tab_materiel[i])==typeid(Ordinateur_fixe))
                m=new Ordinateur_fixe(static_cast<const Ordinateur_fixe&>(*tab_materiel[i]));
            tab_materiel.push_back(m);}}   return *this;
}

istream& operator>>(istream& in, Societe& L)
{
    char rep;
    int choix;int choix2; int choix3;
    do
    {
        cout<<"Entrer un choix:1pour ajouter une personne,2 pour ajouter un materiel";
        cin>>choix2;
    }while(choix2!=1 && choix2!=2);
    if(choix2==1)
    {	
        do
        {
            do
            {
                cout << "Entrer un choix: 1 pou ajouter un client,2 pour ajouter un ouvrier " << endl;
                cin >> choix;}while(choix!=1 && choix!=2);

                if (choix == 1)
                {
                    Client *c = new Client();
                    in >> *c;
                    L.tab_pers.push_back(c);
                }
                else if (choix == 2)
                {
                    Ouvrier *o = new Ouvrier();
                    in >> *o;
                    L.tab_pers.push_back(o);
                }
                cout << "Ajouter un autre personne?";
                cin >> rep;
    } while (rep == 'o' || rep == 'O');}
    else
    {
        do
        {
            do
            {
                cout << "choisir un numero pour ajouter:1 composant interne,2 support de stockage, 3 peripherique,4ordinateur fixe,5 ordinateur portable,6 appareil tactile " << endl;
                cin >> choix3;}while(choix3!=1 && choix3!=2 && choix3!=3 && choix3 !=4 && choix3!=5 && choix3!=6);
                if (choix3 == 1)
                {
                    Composant_interne *c = new Composant_interne();
                    in >> *c;
                    L.tab_materiel.push_back(c);
                }
                else if (choix3 == 2)
                {
                    Support_stockage *s = new Support_stockage();
                    in >> *s;
                    L.tab_materiel.push_back(s);
                }
                else if (choix3== 3)
                {
                    Peripherique *p= new Peripherique();
                    in >> *p;
                    L.tab_materiel.push_back(p);
                }
                else if (choix3 == 4)
                {
                    Ordinateur_fixe *f = new Ordinateur_fixe();
                    in >> *f;
                    L.tab_materiel.push_back(f);
                }
                else if (choix3 == 5)
                {
                    Ordinateur_portable *pc = new Ordinateur_portable();
                    in >> *pc;
                    L.tab_materiel.push_back(pc);
                }
                else if (choix3 == 6)
                {
                    Appareil_tactile *app = new Appareil_tactile();
                    in >> *app;
                    L.tab_materiel.push_back(app);
                }

                cout << "Ajouter une autre materiel? ";
                cin >> rep;
        } while (rep == 'o' || rep == 'O');}
    return in;
}

istream& operator>>(istream& in, Societe* L)
{
    char rep;
    int choix;int choix2; int choix3;
    do
    {
        cout<<"Entrer un choix:1pour ajouter une personne,2 pour ajouter un materiel";
        cin>>choix2;
    }while(choix2!=1 && choix2!=2);
    if(choix2==1)
    {	do
    {
        do
        {
            cout << "Entrer un choix: 1 pou ajouter un client,2 pour ajouter un ouvrier " << endl;
            cin >> choix;}while(choix!=1 && choix!=2);

            if (choix == 1)
            {
                Client *c = new Client();
                in >> *c;
                L->tab_pers.push_back(c);
            }
            else if (choix == 2)
            {
                Ouvrier *o = new Ouvrier();
                in >> *o;
                L->tab_pers.push_back(o);
            }
            cout << "Ajouter un autre personne?";
            cin >> rep;
    } while (rep == 'o' || rep == 'O');}
    else
    {
        do
        {
            do
            {
                cout << "choisir un numero pour ajouter:1 composant interne,2 support de stockage, 3 peripherique,4ordinateur fixe,5 ordinateur portable,6 appareil tactile " << endl;
                cin >> choix3;}while(choix3!=1 && choix3!=2 && choix3!=3 && choix3 !=4 && choix3!=5 && choix3!=6);
                if (choix3 == 1)
                {
                    Composant_interne *c = new Composant_interne();
                    in >> *c;
                    L->tab_materiel.push_back(c);
                }
                else if (choix3 == 2)
                {
                    Support_stockage *s = new Support_stockage();
                    in >> *s;
                    L->tab_materiel.push_back(s);
                }
                else if (choix3== 3)
                {
                    Peripherique *p= new Peripherique();
                    in >> *p;
                    L->tab_materiel.push_back(p);
                }
                else if (choix3 == 4)
                {
                    Ordinateur_fixe *f = new Ordinateur_fixe();
                    in >> *f;
                    L->tab_materiel.push_back(f);
                }
                else if (choix3 == 5)
                {
                    Ordinateur_portable *pc = new Ordinateur_portable();
                    in >> *pc;
                    L->tab_materiel.push_back(pc);
                }
                else if (choix3 == 6)
                {
                    Appareil_tactile *app = new Appareil_tactile();
                    in >> *app;
                    L->tab_materiel.push_back(app);
                }

                cout << "Ajouter une autre materiel? ";
                cin >> rep;
        } while (rep == 'o' || rep == 'O');}
    return in;
}


ostream& operator<<(ostream& out, Societe&L)
{
    for (int i = 0; i<L.tab_pers.size(); i++)
    {
        if (typeid(*L.tab_pers[i]) == typeid(Client))
            out << static_cast<Client&>(*L.tab_pers[i]) << endl;
        else if (typeid(*L.tab_pers[i]) == typeid(Ouvrier))
            out << static_cast<Ouvrier&>(*L.tab_pers[i]) << endl;
    }
    return out;
}
ostream& operator<<(ostream& out, Societe* L)
{

    for (int i = 0; i<L->tab_pers.size(); i++)
    {
        if (typeid(*L->tab_pers[i]) == typeid(Client))
            out << "1 " << static_cast<Client&>(*L->tab_pers[i]) << endl;
        else if (typeid(*L->tab_pers[i]) == typeid(Ouvrier))
            out << "2 " << static_cast<Ouvrier&>(*L->tab_pers[i]) << endl;
    }
    return out;

}
void Societe::fopen1(fstream &f)
{
    f.open("Liste_personne.txt",ios::out|ios::app|ios::in);
    if (!f.is_open())exit(-1);
}
void Societe::fopen2(fstream &f)
{
    f.open("Liste_materiel.txt",ios::out|ios::app);
    if (!f.is_open())exit(-1);
}
void Societe::enregistrer_fichier()
{
    ofstream fo("Liste_personne.txt",ios::out|ios::app);
    if (!fo)

        cout << "\n erreur\n" << endl;
    int i;
    for (i = 0; i<tab_pers.size(); i++)
    {
        if (typeid(*tab_pers[i]) == typeid(Client))
            fo << "1 " << static_cast<Client&>(*tab_pers[i]) << endl;
        else if (typeid(*tab_pers[i]) == typeid(Ouvrier))
            fo << "2 " << static_cast<Ouvrier&>(*tab_pers[i]) << endl;
    }
    fo.close();
}
void Societe::enregistrer_fichier2()            
{
    ofstream fo("Liste_materiel.txt",ios::out|ios::app);
    if (!fo)

        cout << "\n erreur\n" << endl;
    int i;
    for (i = 0; i<tab_materiel.size(); i++)
    {
        if (typeid(*tab_materiel[i]) == typeid(Support_stockage))
            fo << "1 " << static_cast<Support_stockage&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Peripherique))
            fo << "2 " << static_cast<Peripherique&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Composant_interne))
            fo << "3 " << static_cast<Composant_interne&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Ordinateur_portable))
            fo << "4 " << static_cast<Ordinateur_portable&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Ordinateur_fixe))
            fo << "5 " << static_cast<Ordinateur_fixe&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Appareil_tactile))
            fo << "6 " << static_cast<Appareil_tactile&>(*tab_materiel[i]) << endl;
    }
    fo.close();
}
void Societe::enregistrer_fichier_new()
{
    ofstream fo("Liste_personne.txt",ios::out|ios::trunc);
    if (!fo)

        cout << "\n erreur\n" << endl;
    int i;
    for (i = 0; i<tab_pers.size(); i++)
    {
        if (typeid(*tab_pers[i]) == typeid(Client))
            fo << "1 " << static_cast<Client&>(*tab_pers[i]) << endl;
        else if (typeid(*tab_pers[i]) == typeid(Ouvrier))
            fo << "2 " << static_cast<Ouvrier&>(*tab_pers[i]) << endl;
    }
    fo.close();
}
void Societe::enregistrer_fichier2_new()            
{
    ofstream fo("Liste_materiel.txt",ios::out|ios::trunc);
    if (!fo)

        cout << "\n erreur\n" << endl;
    int i;
    for (i = 0; i<tab_materiel.size(); i++)
    {
        if (typeid(*tab_materiel[i]) == typeid(Support_stockage))
            fo << "1 " << static_cast<Support_stockage&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Peripherique))
            fo << "2 " << static_cast<Peripherique&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Composant_interne))
            fo << "3 " << static_cast<Composant_interne&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Ordinateur_portable))
            fo << "4 " << static_cast<Ordinateur_portable&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Ordinateur_fixe))
            fo << "5 " << static_cast<Ordinateur_fixe&>(*tab_materiel[i]) << endl;
        else if (typeid(*tab_materiel[i]) == typeid(Appareil_tactile))
            fo << "6 " << static_cast<Appareil_tactile&>(*tab_materiel[i]) << endl;
    }
    fo.close();
}


void Societe::lire_fichier()
{


    ifstream fi("Liste_personne.txt",ios::in);
    fi.seekg(0);
    int val;
    while (1)
    {
        fi >> val;
        if (fi.eof())break;
        if (val == 1)
        {
            Client* p = new Client();
            fi >> *p;
            tab_pers.push_back(p);


        }
        else if (val == 2)
        {
            Ouvrier* p = new Ouvrier();
            fi >> *p;
            tab_pers.push_back(p);

        }
    }
    fi.close();
}
void Societe::lire_fichier2()
{

    ifstream fi("Liste_materiel.txt",ios::in);
    fi.seekg(0);
    int val;
    while (1)
    {
        fi >> val;
        if (fi.eof())break;
        if (val== 1)
        {

            Support_stockage *s = new Support_stockage();
            fi >> *s;
            tab_materiel.push_back(s);
        }
        else if (val == 2)
        {
            Peripherique *p= new Peripherique();
            fi >> *p;
            tab_materiel.push_back(p);

        }
        else if (val== 3)
        {
            Composant_interne *c = new Composant_interne();
            fi>> *c;
            tab_materiel.push_back(c);

        }
        else if (val == 4)
        {
            Ordinateur_portable *pc = new Ordinateur_portable();
            fi>> *pc;
            tab_materiel.push_back(pc);

        }
        else if (val == 5)
        {
            Ordinateur_fixe *f = new Ordinateur_fixe();
            fi >> *f;
            tab_materiel.push_back(f);

        }
        else if (val== 6)
        {
            Appareil_tactile *app = new Appareil_tactile();
            fi >> *app;
            tab_materiel.push_back(app);
        }
    }
}

void Societe::afficher_materiel()
{
    for(int i=0;i<tab_materiel.size();i++)
    {  
        if (typeid(*tab_materiel[i]) == typeid(Ordinateur_fixe))

        {
            cout<<"\n********************Ordinateur fixe********************\n";

        }
        else 
            if (typeid(*tab_materiel[i]) == typeid(Ordinateur_portable))
            {
                cout<<"\n********************Ordinateur portable********************\n";
            }
            else if (typeid(*tab_materiel[i]) == typeid(Appareil_tactile))
            { cout<<"\n********************Appareil tacile********************\n";}

            else if (typeid(*tab_materiel[i]) == typeid(Support_stockage))
                cout<<"\n********************Support de stockage********************\n";

            else if (typeid(*tab_materiel[i]) == typeid(Composant_interne))
                cout<<"\n*********************Composant interne********************\n";

            else if (typeid(*tab_materiel[i]) == typeid(Peripherique))
                cout<<"\n********************Peripherique********************\n";




            tab_materiel[i]->afficher();

            cout<<"\n";}
}


void Societe::supprimer_personne()
{
    long c;
    cout << "Donner le cin de personne a supprimer" << endl;
    cin >> c;

    for (int i = 0; i<tab_pers.size(); i++)
    {
        long id;
        id = tab_pers[i]->getcin();
        if (id == c)
        {
            tab_pers.erase(tab_pers.begin() + i);
        }

    }

}
int Societe::recherche_client(long c)
{
    for(int i=0;i<tab_pers.size();i++)
    {
        if(tab_pers[i]->getcin()==c)
            return i;
        else
            return -1;
    }
}
void Societe::rechercher_personne()
{
    long c;
    cout<<"Saisir le CIN de personne"<<endl;
    cin>>c;
    int j=0;
    for(int i=0;i<tab_pers.size();i++)
    {
        long id;
        id = tab_pers[i]->getcin();
        if (id == c)
        {
            j=1;
            tab_pers[i]->afficher();
            break;
        }}
    if(j==0)
        cout<<"le personne n existe pas2"<<endl;
}



void Societe::modifier_personne()
{
    long c;
    cout<<"Saisir le CIN de l ouvrier a modifier"<<endl;
    cin>>c;
    int j=0;
    string ch1,ch2;
    long id;
    for(int i=0;i<tab_pers.size();i++)
    {
        id = tab_pers[i]->getcin();
        if (id == c)
        {   cout<<"Donner le nom"<<endl;
        cin>>ch1;
        cout<<"Donner le prenom"<<endl;
        cin>>ch2;
        j=1;
        tab_pers[i]->setnom(ch1);
        tab_pers[i]->setprenom(ch2);

        break;
        }}
    if(j==0)
        cout<<"le personne n existe pas2"<<endl;
}


void Societe::supprimer_materiel()
{
    long c;
    cout << "Donner le numero de serie de materiel a supprimer" << endl;
    cin >> c;

    for (int i = 0; i<tab_materiel.size(); i++)
    {
        long id;
        id = tab_materiel[i]->getserialnumb();
        if (id == c)
        {
            tab_materiel.erase(tab_materiel.begin() + i);
        }

    }

}
void Societe::rechercher_materiel()
{
    int k=0;
    do{
        long x;
        cout<<"Donner le numero de serie de materiel recherche"<<endl;
        cin>>x;

        for(int i=0;i<tab_materiel.size();i++)
        {
            if(tab_materiel[i]->getserialnumb()==x)
            { 
                float prix=tab_materiel[i]->getprix();
                int rem=tab_materiel[i]->getremise();
                k=1;
                cout<<"Le prix apres remise est: "<<(prix-(float)(prix*rem/100))<<endl;
            }

        }
        if(k==0)
            cout<<"Le materiel n existe pas"<<endl;
    }while(k==0);}



void Societe::afficher_personne()
{
    for(int i=0;i<tab_pers.size();i++)
    {
        tab_pers[i]->afficher();
        cout<<"\n********************\n";
    }
}


Societe::~Societe()
{ 
    for(int i=0;i<tab_pers.size();i++)

        delete tab_pers[i];
    for(int i=0; i<tab_materiel.size();i++)
        delete tab_materiel[i];
}














