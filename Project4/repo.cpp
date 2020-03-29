#include <iostream>
#include "repo.h"
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