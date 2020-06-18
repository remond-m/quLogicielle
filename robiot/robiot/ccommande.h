#pragma once
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class CCommande
{
public:
	CCommande(int ,int,int , double, string);
	~CCommande();
	void getListe();
	vector<int> arbreSuivant();
	vector<vector<int>> dijkstra(int);
private :
	int x_coord;
	int y_coord;
	int arbre_courant;
	vector<vector<int>> arbres_coord;
	double timer;
};

