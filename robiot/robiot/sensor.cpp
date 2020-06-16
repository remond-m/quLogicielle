#include "sensor.h"
#include <iostream>

Sensor::Sensor(string address)
{
	ifstream mappy(address);
	if (mappy) {
		char a;
		int i=0, j=0;
		while (mappy.get(a)) {
			if (a == '/n') {
				j++;
				i = 0;
			}
			else {
				map[i][j] = a;
				i++;
			}
		}
	}
	else {
		cout << "error reading file" << endl;

	}
	
}
char* Sensor::getMap() {
	return *map;
}