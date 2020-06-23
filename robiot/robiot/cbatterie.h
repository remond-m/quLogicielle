/************************************************************** * CLASSE : CBatterie
* PRESENTATION : Classe batterie pour decrire l'utilisation de la batterie du robiot *
 * METHODES PUBLIQUES :
* setCapacity(double) set la capacite minimale requise de la batterie
* getCapacity retourne la capacite minimale requise de la batterie
* addCapacity(double) incremente la capacite minimale requise de la batterie suite a un deplacement, une mesure...
**************************************************************/
#pragma once
class CBatterie
{
public:
	CBatterie();
	~CBatterie();
	void setCapacity(double);
	double getCapacity();
	void addCapacity(double);

private:
	double capacity;	//capacite en W/h
};