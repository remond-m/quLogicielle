#include "cmoteur.h"


CMoteur::CMoteur(CCompas compas) {
	this->compas = compas;
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