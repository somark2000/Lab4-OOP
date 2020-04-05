#include <iostream>
#include "repo.h"
#include "domain.h"

using namespace std;

repo::repo()
{
	cap = 100;
	len = 0;
	farm = new drug[cap];
}

/*repo::~repo()
{
	delete farm;
}*/

void repo::show()
{
	for (int i = 0; i < len; ++i)
	{
		cout << farm[i].getname() << ' ' << farm[i].getkonzentration() << ' ' << farm[i].getmenge() << ' ' << farm[i].getpreis() << '\n';
	}
}
