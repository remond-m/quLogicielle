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
#include "tests.h"
using namespace std;
static const char* __cvs_id = "@(#) $Header$";

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
    Tests tests();
	//Test de lecture du fichier de cartographie
	/if(tests.test_lectureFichierCartographie("../cartographie_terrain.tx")) {
		cout << "Test de lecture de cartographie --> OK" << endl;
	} else {
		cout << "Test de lecture de cartographie --> KO" << endl;
	}

	//Test de lecture du fichier de cartographie
	if(tests.test_lectureFichierListeArbres("../liste_de_controle.txt")) {
		cout << "Test de lecture de liste d'arbres a mesurer --> OK" << endl;
	} else {
		cout << "Test de lecture de cartographie --> KO" << endl;
	}

	//Test de la fonction getChar du capteur
	CCommande test_commande(fichier_cartographie,fichier_liste_controle);
	if(tests.testCapteur_getChar(test_commande.getCapteur(), 'X', 6, 4)) {
		cout << "Test de la fonction getChar du capteur --> OK" << endl;
	}
	else {
		cout << "Test de la fonction getChar du capteur --> KO" << endl;
	}
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





