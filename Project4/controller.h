#pragma once
#include "repo.h"
#include <iostream>
using namespace std;

class contr
{
	friend class repo;
	friend class drug;
private:
	repo rep;
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
	void lowsupply(int x);
};
