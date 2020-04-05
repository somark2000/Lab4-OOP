#pragma once
#include <iostream>
#include "controller.h"

class ui
{
	friend class repo;
	friend class drug;
	friend class contr;
private:
	contr con;
public:
	void Menu();
	void run();
	//constructor
	ui(contr cont);

	//destructor
	~ui();
};