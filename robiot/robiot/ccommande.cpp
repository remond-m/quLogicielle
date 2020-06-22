#include "ccommande.h"
#include <algorithm>
#include <stdlib.h>


CCommande::CCommande() {

}

CCommande::CCommande(string adresse_cartographie, string adresse_liste_controle) {

	
	vector<vector<int>> posArbres;
	
	vector<int> tmp; //stock colonne
	ifstream mappy(adresse_liste_controle);
	if (mappy.is_open()) {
		cout << "Lecture liste de controle: OK" << endl;
		double valeur;
		int i = 0;
		while (mappy>>valeur) {
			if (i == 2) {
				posArbres.push_back(vector<int>(tmp));
				tmp.clear();
				i = 0;
			}

			tmp.push_back(valeur);
			i++;
		}
		posArbres.push_back(vector<int>(tmp));
	} else {
		cout << "error reading file" << endl;
	}
	
	this->capteur = CCapteur(adresse_cartographie);
	this->compas = CCompas();
	this->moteur = CMoteur(*this);
	this->batterie = CBatterie();
	this->arbre_courant = 0;
	this->nb_mesures = 0;
	this->arbres_coord = posArbres;
}

int CCommande::getArbreCourant() {
	return this->arbre_courant;
}

vector<int> CCommande::arbreSuivant() {
	vector<int> arbre_suivant = arbres_coord[arbre_courant];
	arbre_courant = (1 + arbre_courant) % arbres_coord.size();
	return arbre_suivant;
}

void CCommande::deplacement(vector<vector<int>> coords) {
	vector<int> pos_actuelle;
	for (int i = 0; i < coords.size(); i++) {
		pos_actuelle = compas.getPosition();
		if (pos_actuelle[0] < coords[i][0]) {
			moteur.droite();
			moteur.addTempsFonctionnement();
		}
		if (pos_actuelle[0] > coords[i][0]) {
			moteur.gauche();
			moteur.addTempsFonctionnement();
		}
		if (pos_actuelle[1] < coords[i][1]) {
			moteur.bas();
			moteur.addTempsFonctionnement();
		}
		if (pos_actuelle[1] > coords[i][1]) {
			moteur.haut();
			moteur.addTempsFonctionnement();
		}
	}
	batterie.addCapacity(moteur.getTempsFonctionnement());
}

vector<vector<int>> CCommande::dijkstra(vector<int> arrivee) {
	//def des variables
	vector<int> depart = compas.getPosition(); //x et y
	//depart.push_back(0);
	int longueur = capteur.getLongueurMap();
	int largeur = capteur.getLargeurMap();
	int xDirection, yDirection, xDistance, yDistance;
	int i, j, minimum = 0;

	//vector<vector<int>> voisinage;
	vector<int> position = depart;
	//vector<vector<int>> chemins;
	//voisinage.push_back(depart);
	vector<vector<int>> cheminFinal;
	vector<int> positionTest;

	while (position != arrivee) {
		
		xDirection = arrivee[0] - position[0];
		yDirection = arrivee[1] - position[1];
		xDistance = abs(arrivee[0] - position[0]);
		yDistance = abs(arrivee[1] - position[1]);

		positionTest.clear();

		if (xDistance > yDistance) {
			if (xDirection > 0) {
				positionTest.push_back(position[0] + 1);
				positionTest.push_back(position[1]);
				position[0]++;
			}
			else {
				positionTest.push_back(position[0] - 1);
				positionTest.push_back(position[1]);
				position[0]--;
			}
		}
		else {
			if (yDirection > 0) {
				positionTest.push_back(position[0]);
				positionTest.push_back(position[1] + 1);
				position[1]++;
			}
			else {
				positionTest.push_back(position[0]);
				positionTest.push_back(position[1] - 1);
				position[1]--;
			}
		}

		cheminFinal.push_back(positionTest);

		/*
		voisin.clear();
		voisin.push_back(depart[0] + 1);
		voisin.push_back(depart[1]);

		if (!(voisin[0] > largeur || voisin[1] > longueur || voisin[0] < 0 || voisin[1] < 0)) {
			if (capteur.getChar(voisin[0], voisin[1]) != 'X' && !vecteurpresent(voisin, voisinage)) {
				voisin.push_back(1 + minimum);
			}
			else {
				voisin.push_back(10000 + minimum);
			}
		}
		else {
			voisin.push_back(10000 + minimum);
			if (minimum != 0 && voisin[2] < minimum) {
				minimum = voisin[2];
			}
		}
		voisinage.push_back(voisin);

		voisin.clear();
		voisin.push_back(depart[0] - 1);
		voisin.push_back(depart[1]);
		if (!(voisin[0] > largeur || voisin[1] > longueur || voisin[0] < 0 || voisin[1] < 0)) {
			if (capteur.getChar(voisin[0], voisin[1]) != 'X' && !vecteurpresent(voisin, voisinage)) {
				voisin.push_back(1 + minimum);
			}
			else {
				voisin.push_back(10000 + 3*minimum);
			}
		}
		else {
			voisin.push_back(10000 + minimum);
			if (minimum != 0 && voisin[2] < minimum) {
				minimum = voisin[2];
			}
		}
		voisinage.push_back(voisin);

		voisin.clear();
		voisin.push_back(depart[0]);
		voisin.push_back(depart[1] + 1);
		if (!(voisin[0] > largeur || voisin[1] > longueur || voisin[0] < 0 || voisin[1] < 0)) {
			if (capteur.getChar(voisin[0], voisin[1]) != 'X' && !vecteurpresent(voisin, voisinage)) {
				voisin.push_back(1 + minimum);
			}
			else {
				voisin.push_back(10000 + 2*minimum);
			}
		}
		else {
			voisin.push_back(10000 + minimum);
			if (minimum != 0 && voisin[2] < minimum) {
				minimum = voisin[2];
			}
		}
		voisinage.push_back(voisin);
		
		voisin.clear();
		voisin.push_back(depart[0]);
		voisin.push_back(depart[1] - 1);
		if (!(voisin[0] > largeur || voisin[1] > longueur || voisin[0] < 0 || voisin[1] < 0)) {
			if (capteur.getChar(voisin[0], voisin[1]) != 'X' && !vecteurpresent(voisin, voisinage)) {
				voisin.push_back(1 + minimum);
			}
			else {
				voisin.push_back(10000 + minimum);
			}
		}
		else {
			voisin.push_back(10000 + minimum);
			if (minimum != 0 && voisin[2] < minimum) {
				minimum = voisin[2];
			}
		}
		voisinage.push_back(voisin);

		minimum = min(voisinage[0][2], voisinage[1][2]);
		minimum = min(minimum, voisinage[2][2]);
		minimum = min(minimum, voisinage[3][2]);
		minimum++;

		for (i = 0; i < voisinage.size(); i++) {

			if (voisinage[i][2] == minimum) {
				position = voisinage[i];
				cheminFinal[minimum-1] = position;
				break;
			}
		}*/

	}
	return cheminFinal;
}

/*int CCommande::vecteurpresent(vector<int> aComparer, vector<vector<int>> reference) {

	int i = 0;
	while ( i < reference.size()) {
		if (reference[i][0] == aComparer[0] && reference[i][1] == aComparer[1]) {
			return 1;
		}
		i++;
	}
	return 0;
}*/


double CCommande::getTempsParcours(void) {
	return moteur.getTempsFonctionnement() + 300 * getNbMesures();
}

void CCommande::setNbMesures(int nb_mesures) {
	this->nb_mesures = nb_mesures;
}

int CCommande::getNbMesures(void) {
	return this->nb_mesures;
}

double CCommande::getCapacity(void) {
	return batterie.getCapacity();
}

void CCommande::affichage() {
	cout << "---------------------------------------------" << endl;
	cout << "SIMULATION TERMINEE :" << endl;
	cout << "Temps de parcours : " << getTempsParcours() << " secondes" << endl;
	cout << "Nombre de mesures : " << getNbMesures() << endl;
	cout << "Capacite de la batterie estimee : " << getCapacity() << " W/h" << endl;
	cout << "---------------------------------------------" << endl;
}

void CCommande::getListe() {
	for (int i = 0; i < arbres_coord.size(); i++) {
		cout << "Position arbre " << (i + 1) << " : " << arbres_coord[i][0] << " / " << arbres_coord[i][1] << endl;
	}
}


CCommande::~CCommande() {

}