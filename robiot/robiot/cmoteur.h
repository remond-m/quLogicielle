#pragma once
#include <vector>
using namespace std;

class CMoteur
{
public:
	CMoteur();
	~CMoteur();
	void setTempsFonctionnement(double);
	double getTempsFonctionnement(void);
	void addTempsFonctionnement();
	void addTempsFonctionnementIntermediaire(void);
	void setTempsFonctionnementIntermediaire(double);
	double getTempsFonctionnementIntermediaire(void);
	vector<int> haut(void);
	vector<int> bas(void);
	vector<int> gauche(void);
	vector<int> droite(void);
private:
	double temps_fonctionnement;
	double temps_intermediaire;
};

