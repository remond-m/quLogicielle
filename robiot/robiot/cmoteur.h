#pragma once
#include "ccompas.h"

class CMoteur
{
public:
	CMoteur();
	CMoteur(CCompas);
	~CMoteur();
	void setTempsFonctionnement(double);
	double getTempsFonctionnement(void);
	void addTempsFonctionnement();
	void haut(void);
	void bas(void);
	void gauche(void);
	void droite(void);
private:
	CCompas compas;
	double temps_fonctionnement;
};

