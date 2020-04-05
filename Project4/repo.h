#pragma once
#include "domain.h"
//#include "controller.h"
#include <iostream>

using namespace std;

class repo
{
	friend class contr;
	friend class drug;
private:
	drug *farm;
	int cap, len;

public:
	//constructor
	repo();

	//destructor
	~repo();

	//shows all the drugs 
	void show();
};
