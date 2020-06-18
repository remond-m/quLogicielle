#include "ccompas.h"

CCompas::CCompas() {
	this->x_coord = 0;
	this->y_coord = 0;
}

void CCompas::setPosition(int x, int y) {
	this->x_coord = x;
	this->y_coord = y;
}

vector<int> CCompas::getPosition() {
	vector<int> position;
	position.push_back(x_coord);
	position.push_back(y_coord);
	return position;
}

void CCompas::movePosition(int x, int y) {
	this->x_coord += x;
	this->y_coord += y;
}


CCompas::~CCompas() {

}