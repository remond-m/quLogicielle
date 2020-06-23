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
// robiot.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <string>
#include "ccommande.h"
using namespace std;
static const char* __cvs_id = "@(#) $Header$";

int main()
{
    //Réalisation de la classe commande
    std::string fichier_liste_controle = "../liste_de_controle.txt";
    std::string fichier_cartographie = "../cartographie_terrain.txt";
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
    

