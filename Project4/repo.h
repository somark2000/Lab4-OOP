#pragma once
#include "domain.h"
//#include "controller.h"
#include <iostream>
#include <vector>
using namespace std;

class repo
{
	friend class contr;
	friend class drug;
private:
	drug* farm;
	int cap, len;

public:
	vector <drug> med;
	vector <vector <drug>> istoric_undo, istoric_redo;
	//constructor
	repo();

	//destructor
	~repo();

	//shows all the drugs 
	void show();

	void name_sort();

	void search(drug m);

	void menge_sort(int menge);

	void preis_sort();

	void undo();

	void redo();

};