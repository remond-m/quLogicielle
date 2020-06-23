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
private:
	vector<vector<char>> map;
};

