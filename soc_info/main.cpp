#include<iostream>
#include<fstream>
#include"Societe.h"
#include"Client.h"
#include"Ouvrier.h";
#include"Appareil_tactile.h"
#include"Ordinateur_fixe.h"
#include"Ordinateur_portable.h"
#include"Composant_interne.h"
#include"Peripherique.h"
#include"Support_stockage.h"
using namespace std;
string date()//Retourner la date courante
{ 
    time_t temps;
    struct tm datetime;
    char format[32];
    time(&temps);
    datetime=*localtime(&temps);
    strftime(format,32,"%d-%m-%Y %H-%M",&datetime);
    return format;
}
void main()
{	Societe s;
    string d;
    d=date();
    cout<<"------------------------------------"<<d<<"--------------------------------"<<endl;//Affichage de la date courante
    cout<<"---------------------------------------BIENVENUE----------------------------------"<<endl;
    char ch1; 
    fstream f,ff;// une pour les personnes et l'autre pour les materiel
    s.fopen1(f);
    s.fopen2(ff);
    int choix;
    do//pour que le choix soit 1 ou 2
    {
        cout<<"Tapez 1 si vous etes un client et tapez 2 si vous etes un ouvrier "<<endl;
        cin>>choix;
    }
    while(choix!=1 && choix!=2);
    if(choix==1)//les taches que le client peut les faire
    {
        long ci;
        char rep;
        cout<<"donner le numero de votre CIN"<<endl;
        cin>>ci;
        s.lire_fichier();//charger le vecteur tab_personne a partir de fichier

        int x=s.recherche_client(ci);//Recherche du client a partir de son carte CIN
        if(x!=-1)//Si le client existe
            cout<<"bienvenue monsieur "<<s.tab_pers[x]->getnom()<< " "<<s.tab_pers[x]->getprenom()<<endl;
        else//Si le client n'existe pas
        { 
            Client *cc=new Client();
            cc->saisir();
            s.tab_pers.push_back(cc);
            s.enregistrer_fichier_new();//l'enregistrement de ce nouveau client
        }
        s.lire_fichier2();
        s.afficher_materiel();//afichage de liste de materiel
        cout<<"Voulez vous acheter un materiel "<<endl;
        cin>>rep;
        if(rep=='o' || rep=='O');
        {
            s.rechercher_materiel();//recherche le materiel en lui demandant de saisir son numero de serie

        }
    }
    if(choix==2)//l'utilisateur est un ouvrier
    {
        int code;
        do//repeter ce traitement jusqu'a saisir la mot de passe correcte
        {
            cout<<"saisir le mot de passe "<<endl;
            cin>>code;}
        while(code!=123456);
        int x;

        do //repeter ce traitement jusqu'a saisir un entier entre 1 et 7
        {
            cout<<"**************choisir la tache que vous voulez faire************"<<endl;
            cout<<"1/Pour ajouter une personne ou un materiel "<<endl;
            cout<<"2/Pour afficher la liste de personnes"<<endl;
            cout<<"3/Pour afficher la liste de materiel"<<endl;
            cout<<"4/Pour supprimer une personne "<<endl;
            cout<<"5/Pour modifier une personne "<<endl;
            cout<<"6/Pour chercher une personne a travers sa CIN "<<endl;
            cout<<"7/Pour supprimer un materiel "<<endl;
            cout<<"8/Pour rechercher un materiel "<<endl;
            cin>>x;
        }
        while(x<1||x>8);
        switch(x)//selon l'entier saisie
        {
        case 1:{
            cin>>s;//remplir le deux vecteur de materiel et de personne selon le choix 
            s.enregistrer_fichier();//Enregistrer les personnes ajoutees dans la fichier Liste_personne
            s.enregistrer_fichier2();//enrigistrer le vecteur dans la fichier Liste_materiel
               }break;
        case 2:{
            s.lire_fichier();
            s.afficher_personne();//Affichage de liste complete de personnes 
               }break;
        case 3:{
           s.lire_fichier2();
           s.afficher_materiel();//Affichage de liste complete de materiaux
               }break;
        case 4:{
            s.lire_fichier();//Recuperer la liste de personne enrigistrer dans la fichier Liste_personne
            s.afficher_personne();
            s.supprimer_personne();
            s.afficher_personne();
            s.enregistrer_fichier_new();// Enregistrer dans la fichier en retirant la personne supprimee de la liste
               }break;//suppression et affichage
        case 5:{
            s.lire_fichier();
            s.afficher_personne();
            s.modifier_personne();//modifier la personne
            s.enregistrer_fichier_new();// Enregistrer dans le fichier apres la modification
            cout<<"\n Liste de personne apres modification\n";
            s.afficher_personne();
               }break;//modification et affichage
        case 6:{
            s.lire_fichier();
            s.rechercher_personne();
               }break;//recherche d'un personne a l aide de cin
        case 7:{
            s.lire_fichier2();
            s.supprimer_materiel();
            s.afficher_materiel();
            s.enregistrer_fichier2_new();
               }break;//suppression de materiel et enregistrement de nouvelle liste
        case 8:{
            s.lire_fichier2();
            s.rechercher_materiel();
               } break;//rechercher le materiel par le numero de serie
        }
    }

    system("PAUSE");
}
