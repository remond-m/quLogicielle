/** /
*
* Copyright(c) CDTI
* Reproduction et diffusion interdites. 
* Developpe par CDTI NRT 
* Projet Robiot 
* 
*SOUS - SYSTEME : Robiot 
* 
*SOURCE : cbatterie.cpp 
* PRESENTATION : définition de la batterie du robiot
* 
*AUTEUR : NRT
* VERSION CVS : 1.0
* DATE : 15/06/2020
* ***/

#include "cbatterie.h"

static const char * __cvs_id="@(#) $Header$" ;

/**************************************************************
* METHODE : CBatterie::CBatterie
* PRESENTATION : Constructeur par défaut, initialise la capacité a 0
* ENTREES : void
* SORTIES : void
* **************************************************************/
CBatterie::CBatterie() {
	this->capacity = 0;
}

/**************************************************************
* METHODE : CBatterie::setCapacity
* PRESENTATION : change la capacité de la batterie
* ENTREES : capacity la nouvelle capacité
* SORTIES : void
* **************************************************************/
void CBatterie::setCapacity(double capacity) {
	this->capacity = capacity;
}

/**************************************************************
* METHODE : CBatterie::getCapacity
* PRESENTATION : renvoie la capacité minimale nécessaire de la batterie
* ENTREES : void
* SORTIES : capacity la capacité minimale de la batterie en W
* **************************************************************/
double CBatterie::getCapacity() {
	return this->capacity;
}

/**************************************************************
* METHODE : CBatterie::addCapacity
* PRESENTATION : incrémente la capacité minimale de la batterie
* ENTREES : temps le temps de déplacement que le robiot vient d'effectuer
* SORTIES : void
* **************************************************************/
void CBatterie::addCapacity(double temps) {
	double temps_moteur_heure = temps / 3600;
	double temps_mesure_heure = 300.0 / 3600;
	double temps_controleur_heure = temps_moteur_heure + temps_mesure_heure;
	this->capacity += temps_moteur_heure*28 + temps_controleur_heure*12.5 + temps_mesure_heure*30;
}

CBatterie::~CBatterie() {

}