#include <iostream>
#include "repo.h"
using namespace std;

repo::repo()
{
	this->cap = 100;
	this->len = 0;
	this->farm = new drug[this->cap];
}

bool repo::isempty()
{
	if (len != 0) return false;
	return true;
}

bool repo::search(drug d)
{
	if (isempty() == true)
	{
		return false;//if empty there are no elements in it
	}
	for (int i = 0; i < this->len; ++i)
	{
		if ((d.getkonzentration() == farm[i].getkonzentration()) and (d.getname() == farm[i].getname()))
		{
			return true;
		}
	}
	return false;
}

void repo::add(drug d)
{
	if (search(d) == false)
	{
		farm[len] = d;
		len++;
		if (len = cap)//the container is full
		{
			cap *= 2;
			drug* v = new drug[cap];
			for (int i = 0; i < len; ++i)
			{
				v[i] = farm[i];
			}
			delete this->farm;
			this->farm = v;
		}
	}
	else
	{
		for (int i = 0; i < this->len; ++i)
		{
			if ((d.getkonzentration() == farm[i].getkonzentration()) and (d.getname() == farm[i].getname()))
			{
				farm[i].setmenge(farm[i].getmenge() + d.getmenge());
			}
		}
	}
}

void repo::remove(drug d)
{
	if (isempty() == true)
	{
		cout << "Container empty\n";
		return;
	}
	if (search(d) == false)
	{
		cout << "The searched drug is not listed\n";
		return;
	}
	for (int i = 0; i < this->len; ++i)
	{
		if ((d.getkonzentration() == farm[i].getkonzentration()) and (d.getname() == farm[i].getname()))
		{
			for (int k = i + 1; k < this->len; ++k)
			{
				farm[k - 1] = farm[k];
			}
			len--;
		}
	}
}

void repo::update(drug d)
{

}