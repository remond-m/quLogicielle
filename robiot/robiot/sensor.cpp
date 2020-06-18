#include "sensor.h"
#include <iostream>
#include <fstream>
using namespace std;

Sensor::Sensor(string address)
{
	vector<char> tmp; //stock colonne
	ifstream mappy(address);

	if (mappy.is_open()) {
		cout << "lecture ok"<< endl;
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
char Sensor::getChar(int i, int j) {
	return map[i][j];
}