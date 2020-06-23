// robiot.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "ccommande.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Test de la classe commande
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
    

