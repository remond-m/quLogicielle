#pragma once
#include <vector>
using namespace std;

class CCompas
{
public:
	CCompas();
	~CCompas();
	void setPosition(int, int);
	vector<int> getPosition();
	void movePosition(int, int);

private:
	int x_coord;
	int y_coord;
};

