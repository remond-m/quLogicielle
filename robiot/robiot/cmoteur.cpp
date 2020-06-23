#include "cmoteur.h"


CMoteur::CMoteur() {
	this->temps_fonctionnement = 0;
	this->temps_intermediaire = 0;
}

void CMoteur::setTempsFonctionnement(double temps) {
	this->temps_fonctionnement = temps;
}

double CMoteur::getTempsFonctionnement() {
	return this->temps_fonctionnement;
}

void CMoteur::setTempsFonctionnementIntermediaire(double temps) {
	this->temps_intermediaire = temps;
}

double CMoteur::getTempsFonctionnementIntermediaire() {
	return this->temps_intermediaire;
}

void CMoteur::addTempsFonctionnementIntermediaire() {
	this->temps_intermediaire += (10 / 0.42);
}

void CMoteur::addTempsFonctionnement() {
	this->temps_fonctionnement += (10/0.42);
}

vector<int> CMoteur::haut() {
	vector<int> position;
	position.push_back(0);
	position.push_back(-1);
	return position;
}

vector<int> CMoteur::bas() {
	vector<int> position;
	position.push_back(0);
	position.push_back(1);
	return position;
}

vector<int> CMoteur::gauche() {
	vector<int> position;
	position.push_back(-1);
	position.push_back(0);
	return position;
}

vector<int> CMoteur::droite() {
	vector<int> position;
	position.push_back(1);
	position.push_back(0);
	return position;
}

CMoteur::~CMoteur() {

}