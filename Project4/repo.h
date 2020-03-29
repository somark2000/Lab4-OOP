#pragma once
#include "domain.h"
#include <iostream>
using namespace std;

class repo
{
	friend class drug;
private:
	drug *farm;
	int cap, len;

public:
	//constructor
	repo();

	//destructor
	~repo();

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
};
