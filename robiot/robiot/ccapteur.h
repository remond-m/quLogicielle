/************************************************************** * CLASSE : CCapteur
* PRESENTATION : Classe CCompas pour decrire la position du robiot *
 * METHODES PUBLIQUES :
* getChar renvoie le caractere present sur la carte à une coordonnee donnee
* getLongueurMap renvoie la longueur du terrain etudie
* getLargeurMap renvoie la largeur du terrain etudie
* getMap renvoie la cartographie de la zone etudiee
**************************************************************/
#pragma once
#include <fstream>
#include <vector>
using namespace std;

class CCapteur
{
public:
	CCapteur();
	CCapteur(string address);
	~CCapteur();
	char getChar(int i, int j);
	int getLongueurMap(void);
	int getLargeurMap(void);
	vector<vector<char>> getMap(void);
private:
	vector<vector<char>> map;
};

