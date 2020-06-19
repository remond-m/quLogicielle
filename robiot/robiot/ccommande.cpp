#include "ccommande.h"


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

vector<vector<int>> CCommande::dijkstra(vector<int> a_modifier) {

	vector<vector<int>> test;
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