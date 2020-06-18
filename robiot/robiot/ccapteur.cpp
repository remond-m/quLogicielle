#include "ccapteur.h"

#include <iostream>
#include <fstream>

CCapteur::CCapteur() {
	
}

CCapteur::CCapteur(string address)
{
	vector<char> tmp; //stock colonne
	ifstream mappy(address);

	if (mappy.is_open()) {
		cout << "Lecture cartographie: OK" << endl;
		char a;
		while (mappy.get(a)) {
			if (a == '\n') {
				map.push_back(vector<char>(tmp));
				tmp.clear();
			}
			else {
				tmp.push_back(a);
			}
		}
		map.push_back(vector<char>(tmp));
	}
	else {
		cout << "error reading file" << endl;

	}
}

char CCapteur::getChar(int i, int j) {
	return map[i][j];
}

CCapteur::~CCapteur() {

}