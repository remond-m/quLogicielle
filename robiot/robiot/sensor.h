#pragma once
#include <fstream>
#include <vector>
using namespace std;

class Sensor
{
private : 
	char map[100][100];
public :
	//constructor
	Sensor(string address);

	//read
	char* getMap();
};




