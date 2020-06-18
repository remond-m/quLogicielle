#pragma once
#include "ccompas.h"

class CMoteur
{
public:
	CMoteur(CCompas);
	~CMoteur();
	void haut(void);
	void bas(void);
	void gauche(void);
	void droite(void);
private:
	CCompas compas;
};

