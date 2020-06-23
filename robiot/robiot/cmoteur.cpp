/************************************************************** /
*
* Copyright(c) CDTI
* Reproduction et diffusion interdites.
* Developpe par CDTI NRT
* Projet Robiot
*
*SOUS - SYSTEME : Robiot
*
*SOURCE : cmoteur.cpp
* PRESENTATION : la classe moteur permet de garder en m?oire les temps de fonctionnements du moteur
*
*AUTEUR : NRT
* VERSION CVS : 1.0
* DATE : 15/06/2020
* ***************************************************************/

#include "cmoteur.h"
static const char* __cvs_id = "@(#) $Header$";

/**************************************************************  
* METHODE      : CMoteur::CMoteur
* PRESENTATION : onstructeur initialisant le moteur  
*  
* ENTREES : void
*  
* SORTIES : temps_fonctionnement : temps global
*           temps_intermediaire : temps entre chaque arbre
*  
**************************************************************/

CMoteur::CMoteur() {
	this->temps_fonctionnement = 0;
	this->temps_intermediaire = 0;
}

/**************************************************************
* METHODE      : CMoteur::setTempsFonctionnement
* PRESENTATION : change la valeur de temps
*
* ENTREES : double temps : temps global
*
* SORTIES : void
*
**************************************************************/
void CMoteur::setTempsFonctionnement(double temps) {
	this->temps_fonctionnement = temps;
}

/**************************************************************
* METHODE      : CMoteur::getTempsFonctionnement
* PRESENTATION : renvoie le temps de fonctionnement global
*
* ENTREES : void
*
* SORTIES : temps_fonctionnement : temps de fonctionnement global 
*
* EXCEPTIONS : <exception_1> : cas d'erreur 1
*              <exception_2> : cas d'erreur 2
*              <exception_3> : cas d'erreur 3
*
**************************************************************/

double CMoteur::getTempsFonctionnement() {
	return this->temps_fonctionnement;
}

/**************************************************************
* METHODE      : CMoteur::setTempsFonctionnementIntermediaire
* PRESENTATION : change le temps fonctionnement entre chaque arbre
*
* ENTREES : double temps : nouveau temps global
*
* SORTIES : void
*
**************************************************************/

void CMoteur::setTempsFonctionnementIntermediaire(double temps) {
	this->temps_intermediaire = temps;
}

/**************************************************************
* METHODE      : CMoteur::getTempsFonctionnementIntermediaire
* PRESENTATION : renvoie le temps de fonctionnement entre chaque arbre
*
* ENTREES : void
*
* SORTIES : temps_intermediaire : temps de fonctionnement entre chaque arbre
*
**************************************************************/

double CMoteur::getTempsFonctionnementIntermediaire() {
	return this->temps_intermediaire;
}

/**************************************************************
* METHODE      : CMoteur::addTempsFonctionnementIntermediaire
* PRESENTATION : ajoute un temps de fonctionnement interm?aire d'un d?lacement d'une cases
*
* ENTREES : void
*
* SORTIES : temps_intermediare : temps entre 2 arbres
*
**************************************************************/

void CMoteur::addTempsFonctionnementIntermediaire() {
	this->temps_intermediaire += (10 / 0.42);
}

/**************************************************************
* METHODE      : CMoteur::addTempsFonctionnement
* PRESENTATION : ajoute un temps de fonctionnement global lors d'un d?lacement d'une case
*
* ENTREES :void
*
* SORTIES : temps_fonctionnement : temps de fonctionnement global
*
**************************************************************/

void CMoteur::addTempsFonctionnement() {
	this->temps_fonctionnement += (10/0.42);
}

/**************************************************************
* METHODE      : CMoteur::haut
* PRESENTATION : donne la direction de deplacement vers le haut
*
* ENTREES : void
*
* SORTIES : position : renvoie la position en haut par rapport ?la position actuelle
*
*
**************************************************************/

vector<int> CMoteur::haut() {
	vector<int> position;
	position.push_back(0);
	position.push_back(-1);
	return position;
}

/**************************************************************
* METHODE      : CMoteur::bas
* PRESENTATION : donne la direction de deplacement vers le bas
*
* ENTREES : void
*
* SORTIES : position : renvoie la position en bas par rapport ?la position actuelle
*
**************************************************************/

vector<int> CMoteur::bas() {
	vector<int> position;
	position.push_back(0);
	position.push_back(1);
	return position;
}

/**************************************************************
* METHODE      : CMoteur::gauche
* PRESENTATION : donne la direction de deplacement vers la gauche
*
* ENTREES : void
*
* SORTIES : position : renvoie la position ?gauche par rapport ?la position actuelle
*
**************************************************************/

vector<int> CMoteur::gauche() {
	vector<int> position;
	position.push_back(-1);
	position.push_back(0);
	return position;
}

/**************************************************************
* METHODE      : CMoteur::droite
* PRESENTATION : donne la direction de deplacement vers la droite
*
* ENTREES : void
*
* SORTIES : position : renvoie la position ?droite par rapport ?la position actuelle
*
**************************************************************/

vector<int> CMoteur::droite() {
	vector<int> position;
	position.push_back(1);
	position.push_back(0);
	return position;
}

/**************************************************************
* METHODE      : CMoteur::~CMoteur
* PRESENTATION : d?ruit le moteur
*
* ENTREES : void
*
* SORTIES : void
*
**************************************************************/

CMoteur::~CMoteur() {

}