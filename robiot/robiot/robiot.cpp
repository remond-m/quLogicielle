/************************************************************** /
*
* Copyright(c) CDTI
* Reproduction et diffusion interdites. 
* Developpe par CDTI
* Projet Robiot 
* 
*SOUS - SYSTEME : Robiot 
* 
*SOURCE : robiot.cpp 
* PRESENTATION : édition du main realisant toutes les fonctions du robiot pour dimensionner la batterie
* 
*AUTEUR : NRT
* VERSION CVS : 1.0
* DATE : 15/06/2020
* ***************************************************************/

#include <iostream>
#include <string>
#include "ccommande.h"
//#include "tests.cpp"
using namespace std;
static const char* __cvs_id = "@(#) $Header$";
//int test_lectureFichierListeArbres(string);
//int test_lectureFichierCartographie(string);
//int testCapteur_getChar(CCapteur , char , int , int );



/**************************************************************  
* METHODE      : main::main
* PRESENTATION : fonction principale de la simulation qui lance le programme
*  
* ENTREES : void
*  
* SORTIES : void
*  
**************************************************************/
int main()
{
	std::string fichier_liste_controle = "../liste_de_controle.txt";
    std::string fichier_cartographie = "../cartographie_terrain.txt";
	/*Lancement de tests unitaires*/

	//Test de lecture du fichier de cartographie
	/*if(test_lectureFichierCartographie("../cartographie_terrain.tx")) {
		cout << "Test de lecture de cartographie --> OK" << endl;
	} else {
		cout << "Test de lecture de cartographie --> KO" << endl;
	}*/

	//Test de lecture du fichier de cartographie
	/*if(test_lectureFichierListeArbres("../liste_de_controle.txt")) {
		cout << "Test de lecture de liste d'arbres a mesurer --> OK" << endl;
	} else {
		cout << "Test de lecture de cartographie --> KO" << endl;
	}*/

	//Test de la fonction getChar du capteur
	CCommande test_commande(fichier_cartographie,fichier_liste_controle);
	/*if(testCapteur_getChar(test_commande.getCapteur(), 'X', 6, 4)) {
		cout << "Test de la fonction getChar du capteur --> OK" << endl;
	}
	else {
		cout << "Test de la fonction getChar du capteur --> KO" << endl;
	}*/
	/*Fin des tests unitaires*/

	system("PAUSE");

    //Réalisation de la classe commande
    CCommande commande(fichier_cartographie,fichier_liste_controle);

    system("PAUSE");

    commande.setNbMesures(0);

    do {
        commande.deplacement(commande.dijkstra(commande.arbreSuivant()));
        commande.setNbMesures(commande.getNbMesures() + 1);
    }
    while (commande.getArbreCourant() != 0);

    commande.affichage();
    
    system("PAUSE");
}
    

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
/*int test_lectureFichierListeArbres(string liste_controle_adresse)
{
	CCommande test_commande("", liste_controle_adresse);
	if (test_commande.getArbreCoord().empty()) {
		return 0;
	}
	else {
		return 1;
	}
}*/

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
/*int test_lectureFichierCartographie(string cartographie_adresse)
{
	CCommande test_commande(cartographie_adresse, "");
	if (test_commande.getCapteur().getMap().empty()) {
		return 0;
	}
	else {
		return 1;
	}
}*/

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
/*int testCapteur_getChar(CCapteur capteur, char reference, int x_test, int y_test) {
	return (capteur.getChar(x_test, y_test) == reference) ? 1 : 0;
}*/




