#include "cmoteur.h"


CMoteur::CMoteur() {
	this->temps_fonctionnement = 0;
}

CMoteur::CMoteur(CCommande commande) {
	this->commande = commande;
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
	this->commande.compas.movePosition(0, -1);
}

void CMoteur::bas() {
	this->commande.compas.movePosition(0, 1);
}

void CMoteur::gauche() {
	this->commande.compas.movePosition(-1, 0);
}

void CMoteur::droite() {
	this->commande.compas.movePosition(1, 0);
}

CMoteur::~CMoteur() {

}