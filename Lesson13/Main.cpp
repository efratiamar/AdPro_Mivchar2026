#include <string>
using namespace std;


#include "Pastry.h" //"Cake.h"
//#include "Cookie.h"
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	list<Pastry*> pastries; // הצהרה על רשימת המאפים
	float bakeTime;
	int choice;
	cout << "Enter pastry type (1 for Cake, 2 for Cookie) or 0 to end: ";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:	// הוספת עוגה לרשימה

			int layers;
			float calPerLayer;
			cout << "Enter baking time(minutes), layers, calories per layer: ";
			cin >> bakeTime >> layers >> calPerLayer;

			Pastry* p = new Cake(bakeTime, layers, calPerLayer);
			pastries.push_back(p);
			break;
		case 2: // הוספת עוגיה לרשימה

			float radius, calPerCmUnit;
			cout << "Enter baking time(minutes), radius(cm), calories per unit cm area: ";
			cin >> bakeTime >> radius >> calPerCmUnit;

			Pastry* p = new Cookie(bakeTime, radius, calPerCmUnit);
			pastries.push_back(p);

				break;
		default:cout << "Invalid choice, please enter 0,1 or 2.\n";
		}
		cout << "Enter pastry type (1 for Cake, 2 for Cookie) or 0 to end: ";
		cin >> choice;
	}

	//הדפסת נתוני כל המאפים

	//option A
	//list<Pastry*>::iterator it = pastries.begin();
	//for (auto it = pastries.begin(); it != pastries.end(); it++)
	//{
	//	(*it)->printInfo();
	//}

	//option B
	for_each(pastries.begin(), pastries.end(), [](Pastry* p){ p->printInfo(); });



		// שחרור זיכרון שהוקצה דינאמית
		for (auto it = pastries.begin(); it != pastries.end(); it++)
		{
			if (*it)
				delete *it;
		}
		return 0;
}











template <class T>
T isCondition(T arr[], int size, bool (*func) (T))
{

	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]))
			return arr[i];
	}

	return arr[size - 1];
}


template <class T>
void update(T arr[], int size, T elem)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == elem)
		{
			arr[i] = elem;
			break;
		}
	}
}

class Student
{
	int ID;
	string name;
	int mark;
public:
	Student(int id, string name, int mark)
	{
		this->ID = id; this->name = name; this->mark = mark;
	}

	bool operator==(const Student& other) const
	{
		return name == other.name;
	}
};

void main1()
{
	Student S[] = { Student(1,"Uri",70),Student(2,"Mira",95),Student(3,"Rami",99) };
	Student X(8, "Mira", 95);
	update(S, 3, X);
}
