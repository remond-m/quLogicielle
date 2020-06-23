/** /
*
* Copyright(c) CDTI -contrat n° XXXXXXXXX
* Reproduction et diffusion interdites.
* Developpe par CDTI NRT
* Projet Robiot
*
*SOUS - SYSTEME : Robiot
*
*SOURCE : ccommande.cpp
* PRESENTATION : commandes de base de la partie commande du robiot
*
*AUTEUR : NRT
* VERSION CVS : 1.0
* DATE : 15/06/2020
* ***/

#include "ccommande.h"
#include <math.h>
#include <algorithm>
#include <stdlib.h>
static const char* __cvs_id = "@(#) $Header$";

/**************************************************************
* METHODE      : CCommande::CCommande
* PRESENTATION : constructeur de CCommande par defaut
*
* ENTREES : void
*
* SORTIES : void
*
*  **************************************************************/
CCommande::CCommande() {

}

/************************************************************** 
* METHODE      : CCommande::CCommande 
* PRESENTATION : constructeur de CCommande 
* 
* ENTREES : adresse_cartographie : chemin du fichier de cartographie
*           adresse_liste_controle : chemin du fichier de liste de controle
* 
* SORTIES : void
* 
* EXCEPTIONS : probleme de lecture du fichier : error reading file 
*              
*  **************************************************************/

CCommande::CCommande(string adresse_cartographie, string adresse_liste_controle) {
	
	vector<vector<int>> posArbres;
	
	vector<int> tmp; //stock colonne
	ifstream mappy(adresse_liste_controle);
	if (mappy.is_open()) {
		cout << "Lecture liste de controle: OK" << endl;
		double valeur;
		int i = 0;
		while (mappy>>valeur) {
			if (i == 2) {
				posArbres.push_back(vector<int>(tmp));
				tmp.clear();
				i = 0;
			}

			tmp.push_back(valeur);
			i++;
		}
		posArbres.push_back(vector<int>(tmp));
	} else {
		cout << "error reading file" << endl;
	}
	
	this->capteur = CCapteur(adresse_cartographie);
	this->compas = CCompas();
	this->moteur = CMoteur();
	this->batterie = CBatterie();
	this->arbre_courant = 0;
	this->nb_mesures = 0;
	this->arbres_coord = posArbres;
}

/**************************************************************
* METHODE      : CCommande::getArbreCourant
* PRESENTATION : Obtention de la position l'arbre courant dans la liste
*
* ENTREES : void
*
* SORTIES : arbre_courant : position de l'arbre dans la liste
*
*  **************************************************************/
int CCommande::getArbreCourant() {
	return this->arbre_courant;
}

/**************************************************************
* METHODE      : CCommande::arbreSuivant
* PRESENTATION : selection de l'arbre suivant
*
* ENTREES : void
*
* SORTIES : arbre_suivant : coordonnees de l'arbre suivant
*
*  **************************************************************/
vector<int> CCommande::arbreSuivant() {
	vector<int> arbre_suivant = arbres_coord[arbre_courant];
	arbre_courant = (1 + arbre_courant) % arbres_coord.size();
	return arbre_suivant;
}

/**************************************************************
* METHODE      : CCommande::deplacement
* PRESENTATION : suivi des coordonnees de déplacement et actions sur le moteur pour déplacement du robot
*
* ENTREES : coords : vecteur de coordonnees des cases a parcourir
*
* SORTIES : void 
*  **************************************************************/
void CCommande::deplacement(vector<vector<int>> coords) {
	vector<int> pos_actuelle;
	for (int i = 0; i < coords.size(); i++) {
		pos_actuelle = compas.getPosition();
		if (pos_actuelle[0] < coords[i][0]) {
			compas.movePosition(moteur.droite());
			moteur.addTempsFonctionnement();
			moteur.addTempsFonctionnementIntermediaire();
		}
		if (pos_actuelle[0] > coords[i][0]) {
			compas.movePosition(moteur.gauche());
			moteur.addTempsFonctionnement();
			moteur.addTempsFonctionnementIntermediaire();
		}
		if (pos_actuelle[1] < coords[i][1]) {
			compas.movePosition(moteur.bas());
			moteur.addTempsFonctionnement();
			moteur.addTempsFonctionnementIntermediaire();
		}
		if (pos_actuelle[1] > coords[i][1]) {
			compas.movePosition(moteur.haut());
			moteur.addTempsFonctionnement();
			moteur.addTempsFonctionnementIntermediaire();
		}
	}
	batterie.addCapacity(moteur.getTempsFonctionnementIntermediaire());
	moteur.setTempsFonctionnementIntermediaire(0);
}

/**************************************************************
* METHODE      : CCommande::dijkstra
* PRESENTATION : precalcul le chemin à parcourir
*
* ENTREES : arrivée : coordonées de l'arbree à atteindre
*
* SORTIES : cheminFinal : vecteur de coordonnées des cases a suivre pour le déplacement
*
*  **************************************************************/
vector<vector<int>> CCommande::dijkstra(vector<int> arrivee) {
	//def des variables
	vector<int> depart = compas.getPosition(); //x et y
	//depart.push_back(0);
	int longueur = capteur.getLongueurMap();
	int largeur = capteur.getLargeurMap();
	int xDirection, yDirection, xDistance, yDistance;
	int i, j, minimum = 0;

	//vector<vector<int>> voisinage;
	vector<int> position = depart;
	//vector<vector<int>> chemins;
	//voisinage.push_back(depart);
	vector<vector<int>> cheminFinal;
	vector<int> positionTest;

	while (position != arrivee) {
		
		xDirection = arrivee[0] - position[0];
		yDirection = arrivee[1] - position[1];
		xDistance = abs(arrivee[0] - position[0]);
		yDistance = abs(arrivee[1] - position[1]);

		positionTest.clear();

		if (xDistance > yDistance) {
			if (xDirection > 0) {
				positionTest.push_back(position[0] + 1);
				positionTest.push_back(position[1]);
				position[0]++;
			}
			else {
				positionTest.push_back(position[0] - 1);
				positionTest.push_back(position[1]);
				position[0]--;
			}
		}
		else {
			if (yDirection > 0) {
				positionTest.push_back(position[0]);
				positionTest.push_back(position[1] + 1);
				position[1]++;
			}
			else {
				positionTest.push_back(position[0]);
				positionTest.push_back(position[1] - 1);
				position[1]--;
			}
		}

		cheminFinal.push_back(positionTest);

		/*
		voisin.clear();
		voisin.push_back(depart[0] + 1);
		voisin.push_back(depart[1]);

		if (!(voisin[0] > largeur || voisin[1] > longueur || voisin[0] < 0 || voisin[1] < 0)) {
			if (capteur.getChar(voisin[0], voisin[1]) != 'X' && !vecteurpresent(voisin, voisinage)) {
				voisin.push_back(1 + minimum);
			}
			else {
				voisin.push_back(10000 + minimum);
			}
		}
		else {
			voisin.push_back(10000 + minimum);
			if (minimum != 0 && voisin[2] < minimum) {
				minimum = voisin[2];
			}
		}
		voisinage.push_back(voisin);

		voisin.clear();
		voisin.push_back(depart[0] - 1);
		voisin.push_back(depart[1]);
		if (!(voisin[0] > largeur || voisin[1] > longueur || voisin[0] < 0 || voisin[1] < 0)) {
			if (capteur.getChar(voisin[0], voisin[1]) != 'X' && !vecteurpresent(voisin, voisinage)) {
				voisin.push_back(1 + minimum);
			}
			else {
				voisin.push_back(10000 + 3*minimum);
			}
		}
		else {
			voisin.push_back(10000 + minimum);
			if (minimum != 0 && voisin[2] < minimum) {
				minimum = voisin[2];
			}
		}
		voisinage.push_back(voisin);

		voisin.clear();
		voisin.push_back(depart[0]);
		voisin.push_back(depart[1] + 1);
		if (!(voisin[0] > largeur || voisin[1] > longueur || voisin[0] < 0 || voisin[1] < 0)) {
			if (capteur.getChar(voisin[0], voisin[1]) != 'X' && !vecteurpresent(voisin, voisinage)) {
				voisin.push_back(1 + minimum);
			}
			else {
				voisin.push_back(10000 + 2*minimum);
			}
		}
		else {
			voisin.push_back(10000 + minimum);
			if (minimum != 0 && voisin[2] < minimum) {
				minimum = voisin[2];
			}
		}
		voisinage.push_back(voisin);
		
		voisin.clear();
		voisin.push_back(depart[0]);
		voisin.push_back(depart[1] - 1);
		if (!(voisin[0] > largeur || voisin[1] > longueur || voisin[0] < 0 || voisin[1] < 0)) {
			if (capteur.getChar(voisin[0], voisin[1]) != 'X' && !vecteurpresent(voisin, voisinage)) {
				voisin.push_back(1 + minimum);
			}
			else {
				voisin.push_back(10000 + minimum);
			}
		}
		else {
			voisin.push_back(10000 + minimum);
			if (minimum != 0 && voisin[2] < minimum) {
				minimum = voisin[2];
			}
		}
		voisinage.push_back(voisin);

		minimum = min(voisinage[0][2], voisinage[1][2]);
		minimum = min(minimum, voisinage[2][2]);
		minimum = min(minimum, voisinage[3][2]);
		minimum++;

		for (i = 0; i < voisinage.size(); i++) {

			if (voisinage[i][2] == minimum) {
				position = voisinage[i];
				cheminFinal[minimum-1] = position;
				break;
			}
		}*/

	}
	return cheminFinal;
}

/*int CCommande::vecteurpresent(vector<int> aComparer, vector<vector<int>> reference) {

	int i = 0;
	while ( i < reference.size()) {
		if (reference[i][0] == aComparer[0] && reference[i][1] == aComparer[1]) {
			return 1;
		}
		i++;
	}
	return 0;
}*/

/**************************************************************
* METHODE      : CCommande::getTempsParcours
* PRESENTATION : Obtenir la valeur du temps d'un parcours
*
* ENTREES : void
*
* SORTIES : temps de fonctionnement : temps de fonctionement total
*
*  **************************************************************/
double CCommande::getTempsParcours(void) {
	return moteur.getTempsFonctionnement() + 300 * getNbMesures();
}

/**************************************************************
* METHODE      : CCommande::setNbMesures
* PRESENTATION : modifie la valeur de nb_mesures
*
* ENTREES : nb_mesures : la valeur du nombre de mesures
*
* SORTIES : void
*
*  **************************************************************/
void CCommande::setNbMesures(int nb_mesures) {
	this->nb_mesures = nb_mesures;
}

/**************************************************************
* METHODE      : CCommande::getNbMesures
* PRESENTATION : Obtention du nombre total de mesures effectuées
*
* ENTREES : void :
*
* SORTIES : nb_mesures : le nombre total de mesures
*
*  **************************************************************/
double CCommande::getNbMesures(void) {
	return this->nb_mesures;
}

/**************************************************************
* METHODE      : CCommande::getCapacity
* PRESENTATION : renvoie la valeur simulée de la capacité la batterie
*
* ENTREES : void
*
* SORTIES : batterie.getCapacity() : la capacité mesurée de la batterie
*
*  **************************************************************/
double CCommande::getCapacity(void) {
	return batterie.getCapacity();
}

/**************************************************************
* METHODE      : CCommande::affichage
* PRESENTATION : affiche toutes les valeurs de la simulation
*  **************************************************************/
void CCommande::affichage() {
	cout << "---------------------------------------------" << endl;
	cout << "SIMULATION TERMINEE :" << endl;
	cout << "Temps de parcours : " << getTempsParcours() << " secondes" << endl;
	cout << "Nombre de mesures : " << getNbMesures() << endl;
	cout << "Capacite de la batterie estimee : " << getCapacity() << " W/h" << endl;
	cout << "---------------------------------------------" << endl;
}

/**************************************************************
* METHODE      : CCommande::getCompas
* PRESENTATION : permet d'obtenir le compas de la classe CCommande
*
* ENTREES : void
*
* SORTIES : CCompas compas : le compas du ccommande
*
*  **************************************************************/
CCompas CCommande::getCompas() {
	return this->compas;
}

/**************************************************************
* METHODE      : CCommande::~CCommande
* PRESENTATION : destructeur de la classe CCommande
*  **************************************************************/
CCommande::~CCommande() {

}