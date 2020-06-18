#pragma once
#include <fstream>
#include <vector>
using namespace std;

class Sensor
{
private : 
	vector<vector<char>> map;
public :
	//constructor
	Sensor(string address);

	//read
	char getChar(int i, int j);
};




