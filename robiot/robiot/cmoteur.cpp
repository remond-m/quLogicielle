#include "cmoteur.h"


CMoteur::CMoteur() {
	this->compas = CCompas();
	this->temps_fonctionnement = 0;
}

CMoteur::CMoteur(CCompas compas) {
	this->compas = compas;
	this->temps_fonctionnement = 0;
}

void CMoteur::setTempsFonctionnement(double temps) {
	this->temps_fonctionnement = temps;
}

double CMoteur::getTempsFonctionnement() {
	return this->temps_fonctionnement;
}

void CMoteur::addTempsFonctionnement() {
	this->temps_fonctionnement += (10/0.42);
}

void CMoteur::haut() {
	compas.movePosition(1, 0);
}

void CMoteur::bas() {
	compas.movePosition(-1, 0);
}

void CMoteur::gauche() {
	compas.movePosition(0, -1);
}

void CMoteur::droite() {
	compas.movePosition(0, 1);
}

CMoteur::~CMoteur() {

}