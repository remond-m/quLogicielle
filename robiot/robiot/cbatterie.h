#pragma once
class CBatterie
{
public:
	CBatterie();
	~CBatterie();
	void setCapacity(double);
	double getCapacity();
	void addCapacity(double);

private:
	//capacit� en W/h
	double capacity; 
};

