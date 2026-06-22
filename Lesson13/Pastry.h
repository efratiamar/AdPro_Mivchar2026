#pragma once
#include <iostream>
using namespace std;

class Pastry
{

	float bakingTime;
public:
	Pastry(float bt) :bakingTime(bt) {};
	virtual float calcCalories() const = 0;
	void printInfo() const
	{
		cout << "BT: " << bakingTime << "Calo: " << calcCalories();
	}
};

class Cake :public Pastry
{
	int layers;
	float caloriesPerLayer;
public :
	Cake(float bt, int l, float c)
		: Pastry(bt), layers(l), caloriesPerLayer(c)
	{};

	float calcCalories()  const override
	{
		return layers * caloriesPerLayer;
	}

};

class Cookie :public Pastry
{
	float radius;
	float caloriesPerCm;
public:
	Cookie(float bt, int l, float c)
		: Pastry(bt), radius(l), caloriesPerCm(c)
	{
	};

	float calcCalories()  const override
	{
		return (radius * radius * 3.14 * caloriesPerCm);
	}

};


