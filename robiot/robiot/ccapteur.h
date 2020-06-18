#pragma once
#include <fstream>
#include <vector>
using namespace std;

class CCapteur
{
public:
	//constructor
	CCapteur();
	CCapteur(string address);
	~CCapteur();
	//read
	char getChar(int i, int j);
private:
	vector<vector<char>> map;
};

