/************************************************************** /
*
* Copyright(c) CDTI
* Reproduction et diffusion interdites.
* Developpe par CDTI NRT
* Projet Robiot
*
*SOUS - SYSTEME : Robiot
*
*SOURCE : cmoteur.h
* PRESENTATION : la classe moteur permet de garder en mémoire les temps de fonctionnements du moteur
*
*AUTEUR : NRT
* VERSION CVS : 1.0
* DATE : 15/06/2020
* *************************************************************** /
/**************************************************************
* CLASSE       : cmoteur
* PRESENTATION :la classe moteur permet de garder en mémoire les temps de fonctionnements du moteur
*
* METHODES PUBLIQUES :
* Cmoteur   : constructeur initialisant le moteur
* setTempsFonctionnement   : change la valeur de temps
* getTempsFonctionnement  : renvoie le temps de fonctionnement global
* setTempsFonctionnementIntermediaire  : change le temps fonctionnement entre chaque arbre
* getTempsFonctionnementIntermediaire  : renvoie le temps de fonctionnement entre chaque arbre
* addTempsFonctionnementIntermediaire  : ajoute un temps de fonctionnement intermédaire lors d'un déplacement d'une case
* addTempsFonctionnement : ajoute un temps de fonctionnement global lors d'un déplacement d'une case
* haut : donne la direction de déplacement vers le haut
* bas : donne la direction de déplacement vers le bas
* gauche : donne la direction de déplacement vers la gauche
* droite : donne la direction de déplacement vers la gauche
* ~CMoteur()  : détruit le moteur
* OBSERVATIONS :
**************************************************************/
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

