#pragma once
#include "repo.h"
#include <iostream>
#include <vector>

using namespace std;

struct action
{
	drug d;
	int act;
	/*
		1) Add
		2) Update
		3) Remove
	*/
};

class contr
{
	friend class repo;
	friend class drug;
private:
	repo rep;
	vector<action> history_undo; //istoric de modificari
	vector<action> history_redo; //istoric de undo-uri

public:
	//constructor
	contr(repo r);

	//destructor
	~contr();

	//add new drug
	void add(drug d);

	//remove existing drug
	void remove(drug d);

	//search for a specified drug
	bool search(drug d);

	//verifies if the repo is empty
	bool isempty();

	//updates a drug
	void update(drug d);

	//shows the listed drugs
	void show(std::string s);

	//shows the drugs on low supply
	void menge_sort(int menge);

	void preis_sort();

	void undo();

	void redo();

	//undo add <=> remove
	void uremove(drug d);

	// undo remove <=> add
	void uadd(drug d);

	//undo update
	void uupdate(drug d);
};
