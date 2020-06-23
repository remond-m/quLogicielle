/************************************************************** 
* CLASSE       : CCommande 
* PRESENTATION : commandes de base de la partie commande du robiot 
* 
* METHODES PUBLIQUES : 
* CCommande::CCommande : constructeur de CCommande par defaut
* CCommande::CCommande : constructeur de CCommande
* CCommande::getArbreCourant : Obtention de la position l'arbre courant dans la liste
* CCommande::arbreSuivant : selection de l'arbre suivant
* CCommande::deplacement : suivi des coordonnees de déplacement et actions sur le moteur pour déplacement du robot
* CCommande::dijkstra : precalcul le chemin à parcourir
* CCommande::getTempsParcours : Obtenir la valeur du temps d'un parcours
* CCommande::setNbMesures : modifie la valeur de nb_mesures
* CCommande::getNbMesures : Obtention du nombre total de mesures effectuées
* CCommande::getCapacity : renvoie la valeur simulée de la capacité la batterie
* CCommande::affichage : affiche toutes les valeurs de la simulation
* CCommande::getCompas : permet d'obtenir le compas de la classe CCommande
* CCommande::~CCommande : destructeur de la classe CCommande
* 
* OBSERVATIONS :  **************************************************************/

#pragma once
#include "cmoteur.h"
#include "ccompas.h"
#include "cbatterie.h"
#include "ccapteur.h"

#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class CCommande
{
public:
	CCommande();
	CCommande(string,string);
	~CCommande();
	void getListe(void);
	void affichage(void);
	int getArbreCourant(void);
	void setNbMesures(int);
	double getTempsParcours(void);
	double getNbMesures(void);
	double getCapacity(void);
	vector<int> arbreSuivant();
	void deplacement(vector<vector<int>>);
	vector<vector<int>> dijkstra(vector<int>);
	int vecteurpresent(vector<int>, vector<vector<int>>);
	CCompas getCompas();
private :
	CMoteur moteur;
	CCompas compas;
	CBatterie batterie;
	CCapteur capteur;
	vector<vector<int>> arbres_coord;
	int arbre_courant;
	int nb_mesures;
};

