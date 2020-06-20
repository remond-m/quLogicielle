#include "ccommande.h"
#include <math.h>


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
	this->moteur = CMoteur(compas);
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
	for (int i = 0; coords.size(); i++) {
		pos_actuelle = compas.getPosition();
		if (pos_actuelle[0] < coords[i][0]) {
			moteur.gauche();
			moteur.addTempsFonctionnement();
		}
		if (pos_actuelle[0] > coords[i][0]) {
			moteur.droite();
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

vector<vector<int>> CCommande::dijkstra(vector<int> depart, vector<int> arrivee, int longueur, int largeur, CCapteur sens) {
	//def des variables
	vector<int> depart; //x et y
	vector<int> arrivee;

	int i, j, min = 0;

	vector<vector<int>> voisins;
	vector<int> position = depart;
	vector<vector<int>> chemins;
	chemins.push_back(depart);
	vector<vector<int>> cheminFinal;

	while (position != arrivee) {
		vector<int> voisin;
		voisin.push_back(depart[0] + 1);
		voisin.push_back(depart[1]);
		if (sens.getChar(voisin[0], voisin[1]) == ' ' && !vecteurpresent(voisin, chemins)) {
			voisin.push_back(1 + min);
		}
		else {
			voisin.push_back(10000 + min);
		}
		if (min != 0 && voisin[2] < min) {
			min = voisin[2];
		}
		voisins.push_back(voisin);

		voisin.push_back(depart[0] - 1);
		voisin.push_back(depart[1]);
		if (sens.getChar(voisin[0], voisin[1]) == (' ' || 'O') && !vecteurpresent(voisin, chemins)) {
			voisin.push_back(1 + min);
		}
		else {
			voisin.push_back(10000 + min + min + min);
		}
		if (min != 0 && voisin[2] < min) {
			min = voisin[2];
		}
		voisins.push_back(voisin);

		voisin.push_back(depart[0]);
		voisin.push_back(depart[1] + 1);
		if (sens.getChar(voisin[0], voisin[1]) == (' ' || 'O') && !vecteurpresent(voisin, chemins)) {
			voisin.push_back(1 + min);
		}
		else {
			voisin.push_back(10000 + min + min);
		}
		if (min != 0 && voisin[2] < min) {
			min = voisin[2];
		}
		voisins.push_back(voisin);

		voisin.push_back(depart[0]);
		voisin.push_back(depart[1] - 1);
		if (sens.getChar(voisin[0], voisin[1]) == (' ' || 'O') && !vecteurpresent(voisin, chemins)) {
			voisin.push_back(1 + min);
		}
		else {
			voisin.push_back(10000 + min);
		}
		if (min != 0 && voisin[2] < min) {
			min = voisin[2];
		}
		voisins.push_back(voisin);

		for (i = 0; i < voisin.size(); i++) {
			if (voisins[i][2] == min) {
				position = voisins[i];
				cheminFinal[min] = position;
				break;
			}
		}

	}
	return cheminFinal;
}

int CCommande::vecteurpresent(vector<int> aComparer, vector<vector<int>> comparer) {
	vector<vector<int>> tmp = comparer;
	int test = 0;
	while (tmp.size() != 0) {
		if (comparer.back()[0] == aComparer[0] or comparer.back()[1] == aComparer[1]) {
			test = 1;
		}
		comparer.pop_back();
	}
	return test;
}


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