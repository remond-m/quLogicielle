/** /
*
* Copyright(c) CDTI
* Reproduction et diffusion interdites. 
* Developpe par CDTI NRT 
* Projet Robiot 
* 
*SOUS - SYSTEME : Robiot 
* 
*SOURCE : ccompas.cpp 
* PRESENTATION : definition de l'outil de geolocalisation du robiot
* 
*AUTEUR : NRT
* VERSION CVS : 1.0
* DATE : 15/06/2020
* ***/

#include "ccompas.h"

static const char * __cvs_id="@(#) $Header$" ;

/**************************************************************
* METHODE : CCompas::CCompas
* PRESENTATION : Constructeur par defaut, initialise la position a (0;0)
* ENTREES : void
* SORTIES : void
* **************************************************************/
CCompas::CCompas() {
	this->x_coord = 0;
	this->y_coord = 0;
}

/**************************************************************
* METHODE : CCompas::setPosition
* PRESENTATION : change la position du robiot a une coordonnee donnee
* ENTREES : position la coordonnee a mettre
* SORTIES : void
* **************************************************************/
void CCompas::setPosition(vector<int> position) {
	this->x_coord = position[0];
	this->y_coord = position[1];
}

/**************************************************************
* METHODE : CCompas::getPosition
* PRESENTATION : renvoie la position actuelle du Robiot
* ENTREES : void
* SORTIES : position la coordonnee du robiot
* **************************************************************/
vector<int> CCompas::getPosition() {
	vector<int> position;
	position.push_back(x_coord);
	position.push_back(y_coord);
	return position;
}

/**************************************************************
* METHODE : CCompas::movePosition
* PRESENTATION : deplace la position du robiot
* ENTREES : deplacement le jeu de translation a effectuer en x et en y
* SORTIES : void
* **************************************************************/
void CCompas::movePosition(vector<int> deplacement) {
	this->x_coord += deplacement[0];
	this->y_coord += deplacement[1];
}

/**************************************************************
* METHODE : CCompas::~CCompas
* PRESENTATION : destructeur de la classe
* ENTREES : void
* SORTIES : void
* **************************************************************/
CCompas::~CCompas() {

}