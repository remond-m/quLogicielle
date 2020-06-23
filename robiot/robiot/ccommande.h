#pragma once
#include "cmoteur.h"
#include "ccompas.h"
#include "cbatterie.h"
#include "ccapteur.h"

#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class CCommande
{
public:
	CCommande();
	CCommande(string,string);
	~CCommande();
	void getListe(void);
	void affichage(void);
	int getArbreCourant(void);
	void setNbMesures(int);
	double getTempsParcours(void);
	double getNbMesures(void);
	double getCapacity(void);
	vector<int> arbreSuivant();
	void deplacement(vector<vector<int>>);
	vector<vector<int>> dijkstra(vector<int>);
	int vecteurpresent(vector<int>, vector<vector<int>>);
	CCompas getCompas();
	
private :
	CMoteur moteur;
	CCompas compas;
	CBatterie batterie;
	CCapteur capteur;
	vector<vector<int>> arbres_coord;
	int arbre_courant;
	int nb_mesures;
};

