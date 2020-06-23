/************************************************************** * CLASSE : CCompas
* PRESENTATION : Classe CCompas pour décrire la position du robiot *
 * METHODES PUBLIQUES :
* setPosition change la position du robiot
* getPosition renvoie la position du robiot
* movePosition déplace la position du robiot
**************************************************************/
#pragma once
#include <vector>
using namespace std;

class CCompas
{
public:
	CCompas();
	~CCompas();
	void setPosition(vector<int>);
	vector<int> getPosition();
	void movePosition(vector<int>);

private:
	int x_coord;
	int y_coord;
};

