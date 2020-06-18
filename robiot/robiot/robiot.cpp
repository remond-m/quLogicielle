// robiot.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "ccommande.h"
#include <iostream>
#include <string>


int main()
{
    //Test de la classe commande
    std::string fichier = "C:/Users/Guillaume/Desktop/QuLogiciel/quLogicielle/robiot/liste_de_controle.txt";
    CCommande c1(0,0,0,0,fichier);
    c1.getListe();
    std::cout << "Hello CDTI!\n";
}
