// robiot.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "ccommande.h"
#include "sensor.h"
#include <iostream>

#include <string>
using namespace std;

int main()
{
    //Test de la classe commande
    std::string fichier_liste_controle = "C:/Users/Guillaume/Desktop/QuLogiciel/quLogicielle/robiot/liste_de_controle.txt";
    std::string fichier_cartographie = "C:/Users/Guillaume/Desktop/QuLogiciel/quLogicielle/robiot/liste_de_controle.txt";
    CCommande commande(fichier_cartographie,fichier_liste_controle);

    system("PAUSE");

    do {
        commande.deplacement(commande.dijkstra(commande.arbreSuivant()));
    }
    while (commande.getArbreCourant() != 0);

    commande.affichage();
    
    system("PAUSE");

    //test class sensor
    //Sensor testSensor("D:/Qualite_logiciel/TP/quLogicielle/robiot/NOM.txt");
    //cout << " La lettre à la coordonnee(2; 5) est: " << testSensor.getChar(1, 1) << endl;
}
    

