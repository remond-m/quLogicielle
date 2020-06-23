#pragma once
#include <vector>
using namespace std;

class CCompas
{
public:
	CCompas();
	~CCompas();
	void setPosition(vector<int>);
	vector<int> getPosition();
	void movePosition(vector<int>);

private:
	int x_coord;
	int y_coord;
};

