/** /
*
* Copyright(c) CDTI
* Reproduction et diffusion interdites. 
* Developpe par CDTI NRT 
* Projet Robiot 
* 
*SOUS - SYSTEME : Robiot 
* 
*SOURCE : ccapteur.cpp 
* PRESENTATION : definition du capteur du robiot
* 
*AUTEUR : NRT
* VERSION CVS : 1.0
* DATE : 15/06/2020
* ***/


#include <iostream>
#include <fstream>
#include "ccapteur.h"

static const char * __cvs_id="@(#) $Header$" ;

/**************************************************************
* METHODE : CCompas::CCapteur
* PRESENTATION : Constructeur par defaut, non-utilise
* ENTREES : void
* SORTIES : void
* **************************************************************/
CCapteur::CCapteur() {
	
}

/**************************************************************
* METHODE : CCompas::CCapteur
* PRESENTATION : Constructeur surcharge ouvrant un fichier et enregistrant son contenu dans un vector map de carte pour simuler le capteur
* ENTREES : address l'adresse du fichier a ouvrir
* SORTIES : void
* **************************************************************/
CCapteur::CCapteur(string address)
{
	vector<char> tmp; //stock colonne
	ifstream mappy(address);

	if (mappy.is_open()) {
		//cout << "Lecture cartographie: OK" << endl;
		char a;
		while (mappy.get(a)) {
			if (a == '\n') {
				map.push_back(vector<char>(tmp));
				tmp.clear();
			}
			else {
				tmp.push_back(a);
			}
		}
		map.push_back(vector<char>(tmp));
	}
	/*else {
		cout << "error reading file" << endl;
	}*/
}

/**************************************************************
* METHODE : CCapteur::CCapteur
* PRESENTATION : renvoie la largeur de la zone etudiee
* ENTREES : void
* SORTIES : map.size le nombre de "ligne" donc la largeur de la zone etudiee
* **************************************************************/
int CCapteur::getLargeurMap() {
	return map.size();
}

/**************************************************************
* METHODE : CCapteur::CCapteur
* PRESENTATION : renvoie la longueur de la zone etudiee
* ENTREES : void
* SORTIES : map[0].size la taille de la premiere ligne donc la longueur de la zone etudiee
* **************************************************************/
int CCapteur::getLongueurMap() {
	return map[0].size();
}

/**************************************************************
* METHODE : CCapteur::CCapteur
* PRESENTATION : renvoie le caractere present sur la carte a une coordonnee donnee
* ENTREES : i la coordonnee x
*			j la coordonnee y
* SORTIES : map[i][j] 
* **************************************************************/
char CCapteur::getChar(int i, int j) {
	return map[i][j];
}

/**************************************************************
* METHODE : CCapteur::CCapteur
* PRESENTATION : renvoie le caractere present sur la carte a une coordonnee donnee
* ENTREES : void
* SORTIES : void
* **************************************************************/
CCapteur::~CCapteur() {

}

/**************************************************************
* METHODE : CCapteur::getMap
* PRESENTATION : renvoie tableau de vecteur de la carte
* ENTREES : void
* SORTIES : map : carte de la zone a traiter
* **************************************************************/

vector<vector<char>> CCapteur::getMap(){
	return this->map;
}