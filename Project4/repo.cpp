#include <iostream>
#include "repo.h"
#include "domain.h"
#include <algorithm>
#include <vector>
using namespace std;

repo::repo()
{
	this->cap = 100;
	this->len = 0;
	this->farm = new drug[this->cap];
}

void repo::show()
{
	for (int i = 0; i < this->len; ++i)
	{
		cout << farm[i].getname() << ' ' << farm[i].getkonzentration() << ' ' << farm[i].getmenge() << ' ' << farm[i].getpreis() << '\n';
	}
}

repo::~repo()
{
	delete farm;
}

//sortiert die Liste von Medikamente nach Name
void repo::name_sort()
{
	auto relation = [](drug a, drug b) { return a.getname() < b.getname(); };
	sort(med.begin(), med.end(), relation);
}

//sucht eine Zeichenkette in der Name und zeigt die Medikamente, die sie enthalten
void repo::search(drug m)
{
	string s;
	cin >> s;
	vector <drug> t; //vector temporar

	name_sort();
	for (int i = 0; i < med.size(); i++)
	{
		if (med.at(i).getname().find(s) != string::npos && med.at(i).getmenge() > 0)
			t.push_back(med.at(i));
	}

	for (int i = 0; i < t.size(); i++)
		t[i].zeigen();

}

//zeigt die Medikamente mit einer kleineren Menge als eine gegebene
void repo::menge_sort(int menge)
{
	for (int i = 0; i < med.size(); i++)
	{
		if (med.at(i).getmenge() < menge)
			med.at(i).zeigen();
	}
}

//sortiert nach Preis
void repo::preis_sort()
{
	auto relation = [](drug a, drug b) { return a.getpreis() < b.getpreis(); };
	sort(med.begin(), med.end(), relation);

	for (int i = 0; i < med.size(); i++)
		med.at(i).zeigen();

}
//undo die letzte Operation
void repo::undo()
{
	if (istoric_undo.size() != 0)
	{
		istoric_redo.push_back(med);
		med = istoric_undo.at(istoric_undo.size() - 1);
		istoric_undo.erase(istoric_undo.begin() + istoric_undo.size() - 1);
		//cout << "undo"<<" "<<endl;
	}
	else
		cout << " Nu este posibil! " << endl;
}

//redo die letzte Operation
void repo::redo()
{
	if (istoric_redo.size() != 0)
	{
		istoric_undo.push_back(med);
		med = istoric_redo.at(istoric_redo.size() - 1);
		istoric_redo.erase(istoric_redo.begin() + istoric_redo.size() - 1);
		//cout << "redo" <<" "<<endl;
	}
	else
		cout << " Nu este posibil! " << endl;
}
