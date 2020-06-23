#include "cbatterie.h"

CBatterie::CBatterie() {
	this->capacity = 0;
}

void CBatterie::setCapacity(double capacity) {
	this->capacity = capacity;
}

double CBatterie::getCapacity() {
	return this->capacity;
}

void CBatterie::addCapacity(double temps) {
	double temps_moteur_heure = temps / 3600;
	double temps_mesure_heure = 300.0 / 3600;
	double temps_controleur_heure = temps_moteur_heure + temps_mesure_heure;
	this->capacity += temps_moteur_heure*28 + temps_controleur_heure*12.5 + temps_mesure_heure*30;
}


CBatterie::~CBatterie() {

}