#pragma once
#include "ccommande.h"

class CMoteur
{
public:
	CMoteur();
	CMoteur(CCommande);
	~CMoteur();
	void setTempsFonctionnement(double);
	double getTempsFonctionnement(void);
	void addTempsFonctionnement();
	void haut(void);
	void bas(void);
	void gauche(void);
	void droite(void);
private:
	CCommande commande;
	double temps_fonctionnement;
};

