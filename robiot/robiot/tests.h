/************************************************************** /
*
* Copyright(c) CDTI
* Reproduction et diffusion interdites.
* Developpe par CDTI NRT
* Projet Robiot
*
*SOUS - SYSTEME : Robiot
*
*SOURCE : tests.h
* PRESENTATION : classe de tests
*
*AUTEUR : NRT
* VERSION CVS : 1.0
* DATE : 15/06/2020
* *************************************************************** /
/**************************************************************
* CLASSE       : tests
* PRESENTATION :classe de tests
* METHODES PUBLIQUES :
* test_lectureFichierListeArbres : test verifiant si le fichier de liste de controle est lu correctement
* test_lectureFichierCartographie : test verifiant si le fichier de cartographie de la zone a etudier est lu correctement
* testCapteur_getChar : test verifiant si la fonction getChar du CCapteur renvoie la bonne donnee
* OBSERVATIONS :
**************************************************************/
#pragma once
#include <vector>
#include "ccommande.h"
using namespace std;

class Tests
{
public:
	Tests();
	~Tests();
	int test_lectureFichierListeArbres(string);
	int test_lectureFichierCartographie(string);
	int testCapteur_getChar(CCapteur, char, int, int);
};