#include "ccommande.h"

CCommande::CCommande( int arbre, double timer, string address) {
	
	vector<vector<int>> posArbres;
	
	vector<int> tmp; //stock colonne
	ifstream mappy(address);
	if (mappy) {
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
	
	this->arbre_courant = arbre;
	this->arbres_coord = posArbres;
	this->timer = timer;
}

void CCommande::getListe() {
	for (int i = 0; i < arbres_coord.size(); i++) {
		cout << "Position arbre " << (i + 1) << " : " << arbres_coord[i][0] << " / " << arbres_coord[i][1] << endl;
	}
}

vector<int> CCommande::arbreSuivant() {
	arbre_courant ++;
	return arbres_coord[arbre_courant];
}

vector<vector<int>> CCommande::dijkstra(int a_modifier) {

	vector<vector<int>> test;
	return test;
}


CCommande::~CCommande() {

}