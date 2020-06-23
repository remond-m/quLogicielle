/************************************************************** /
*
* Copyright(c) CDTI
* Reproduction et diffusion interdites. 
* Developpe par CDTI
* Projet Robiot 
* 
*SOUS - SYSTEME : Robiot 
* 
*SOURCE : tests.cpp 
* PRESENTATION : fichier regroupant les tests unitaires
* 
*AUTEUR : NRT
* VERSION CVS : 1.0
* DATE : 15/06/2020
* ***************************************************************/

#include "stdlib.h"
#include "tests.h"

/**************************************************************  
* METHODE      : Tests::Tests
* PRESENTATION : constructeur initialisant l'outil de test  
*  
* ENTREES : void
*  
* SORTIES :
*  
**************************************************************/
Tests::Tests() {

};
/**************************************************************  
* METHODE      : tests::test_lectureFichierListeArbres
* PRESENTATION : test verifiant si le fichier de liste de controle est lu correctement 
*  
* ENTREES : liste_controle_adresse l'adresse du fichier a lire
*  
* SORTIES : 1 si OK
*			0 si KO
*  
**************************************************************/
int Tests::test_lectureFichierListeArbres(string liste_controle_adresse)
{
	CCommande test_commande("", liste_controle_adresse);
	vector<vector<int>> test = test_commande.getArbreCoord();
	if(test.empty()) {
		return 0;
	} else {
		return 1;
	}
}

/**************************************************************  
* METHODE      : tests::test_lectureFichierCartographie
* PRESENTATION : test verifiant si le fichier de cartographie de la zone a etudier est lu correctement
*  
* ENTREES : cartographie_adresse l'adresse du fichier a lire
*  
* SORTIES : 1 si OK
*			0 si KO
*  
**************************************************************/
int Tests::test_lectureFichierCartographie(string cartographie_adresse)
{
	CCommande test_commande(cartographie_adresse, "");
	vector<vector<char>> test = test_commande.getCapteur().getMap();
	if(test.empty()) {
		return 0;
	} else {
		return 1;
	}
}

/**************************************************************  
* METHODE      : test::testCapteur_getChar
* PRESENTATION : test verifiant si la fonction getChar du CCapteur renvoie la bonne donnee
*  
* ENTREES : capteur le capteur a tester
			reference la valeur de char attendue
			x_test la coordonnee x a tester
			y_test la coordonnee y a tester
*  
* SORTIES : 1 si OK
*			0 si KO
*  
**************************************************************/
int Tests::testCapteur_getChar(CCapteur capteur, char reference, int y_test, int x_test) {
	return (capteur.getChar(x_test, y_test) == reference) ? 1 : 0;
}

/**************************************************************
* METHODE      : Tests::~Tests
* PRESENTATION : destructeur de test
*
* ENTREES : void
*
* SORTIES :
*
**************************************************************/
Tests::~Tests() {

}


