#pragma once
#include<string>
#include"Personne.h"
#include"Materiel.h"
#include<vector>
class Societe
{
public:
	static const std::string  raison_sociale;
	static const string adresse;
private:
	int capital ;
	string email_contact;
	string URL_web;
public:
	vector<Personne*>tab_pers;
	vector<Materiel*>tab_materiel;


public:
	Societe(void);
	Societe(int,string,string);
	Societe(const Societe&);
	Societe& operator=(const Societe);
	friend istream& operator>>(istream&, Societe*);//Pour la lecture a partir du fichier
	friend ostream& operator<<(ostream&, Societe*);//Pour l'ecriture dans la fichier
	friend istream& operator>>(istream&, Societe&);
	friend ostream& operator<<(ostream&, Societe&);
    void fopen1(fstream&);//creer la fichier liste_personne
	void fopen2(fstream&);//creerla fichier liste_materiel 
	void enregistrer_fichier();//Ecriture dans la fichier Liste_personne en mode ajout (app)
	void enregistrer_fichier2();//Ecriture dans la fichier Liste_materiel en mode ajout (app)
    void enregistrer_fichier_new();//Ecriture dans la fichier Liste_personne (le contenu de fichier est perdu)
	void enregistrer_fichier2_new();//Ecriture dans la fichier Liste_materiel (le contenu de fichier est perdu)
	void lire_fichier();//lecture a partir de la fichier liste_personne 
	void lire_fichier2();//lecture a partir de la fichierliste_materiel 
    void supprimer_materiel();//a l aide de num de serie
	void afficher_materiel();//afficher la liste complete de materiaux qui existent
	void supprimer_personne();// a partir de cin
	void rechercher_personne();// a partir de cin
	void rechercher_materiel();
	void modifier_personne();
	int recherche_client(long);
    void afficher_personne();
	~Societe(void);
};

