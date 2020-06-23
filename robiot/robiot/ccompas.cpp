#include "ccompas.h"

CCompas::CCompas() {
	this->x_coord = 0;
	this->y_coord = 0;
}

void CCompas::setPosition(vector<int> position) {
	this->x_coord = position[0];
	this->y_coord = position[1];
}

vector<int> CCompas::getPosition() {
	vector<int> position;
	position.push_back(x_coord);
	position.push_back(y_coord);
	return position;
}

void CCompas::movePosition(vector<int> position) {
	this->x_coord += position[0];
	this->y_coord += position[1];
}


CCompas::~CCompas() {

}