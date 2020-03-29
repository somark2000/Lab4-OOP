#include <iostream>
#include "controller.h"

contr::contr(repo r)
{
	this->rep = r;
}

contr::~contr()
{
	delete rep.farm;
}

bool contr::isempty()
{
	if (rep.len != 0) return false;
	return true;
}


bool contr::search(drug d)
{
	if (isempty() == true)
	{
		return false;//if empty there are no elements in it
	}
	for (int i = 0; i < rep.len; ++i)
	{
		if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
		{
			return true;
		}
	}
	return false;
}

void contr::add(drug d)
{
	if (search(d) == false)
	{
		rep.farm[rep.len] = d;
		rep.len++;
		if (rep.len = rep.cap)//the container is full
		{
			rep.cap *= 2;
			drug* v = new drug[rep.cap];
			for (int i = 0; i < rep.len; ++i)
			{
				v[i] = rep.farm[i];
			}
			delete rep.farm;
			rep.farm = v;
		}
	}
	else
	{
		for (int i = 0; i < rep.len; ++i)
		{
			if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
			{
				rep.farm[i].setmenge(rep.farm[i].getmenge() + d.getmenge());
			}
		}
	}
}

void contr::remove(drug d)
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
	for (int i = 0; i < rep.len; ++i)
	{
		if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
		{
			for (int k = i + 1; k < rep.len; ++k)
			{
				rep.farm[k - 1] = rep.farm[k];
			}
			rep.len--;
		}
	}
}

void contr::update(drug d)
{
	if (search(d) == false)
	{
		add(d);
	}
	else
	{
		for (int i = 0; i < rep.len; ++i)
		{
			if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
			{
				std::string w;
				//update the name
				cout << "Current name of the drug is " << d.getname() << "\n Do you want to update it? (y/n)";
				cin >> w;
				if (w == "y")
				{
					cout << "The new name is ";
					cin >> w;
					rep.farm[i].setname(w);
				}

				//update the price
				cout << "Current price of the drug is " << d.getpreis() << "\n Do you want to update it? (y/n)";
				cin >> w;
				if (w == "y")
				{
					float x;
					cout << "The new price is ";
					cin >> x;
					rep.farm[i].setpreis(x);
				}

				//update the amount
				cout << "Current amount of the drug is " << d.getmenge() << "\n Do you want to update it? (y/n)";
				cin >> w;
				if (w == "y")
				{
					int x;
					cout << "The new amount is ";
					cin >> x;
					rep.farm[i].setmenge(x);
				}

				//update the concentration
				cout << "Current name of the drug is " << d.getname() << "\n Do you want to update it? (y/n)";
				cin >> w;
				if (w == "y")
				{
					cout << "The new name is ";
					cin >> w;
					rep.farm[i].setname(w);
				}
			}
		}
	}
}

void contr::show(std::string s)
{
	if (s.length() == 0)
	{
		rep.show();
	}
	else
	{
		repo r;
		for (int i = 0; i < rep.len; ++i)
		{
			if (rep.farm[i].getname().find(s))
			{
				r.farm[r.len] = rep.farm[i];
				r.len++;
				if (r.len = r.cap)//the container is full
				{
					r.cap *= 2;
					drug* v = new drug[r.cap];
					for (int i = 0; i < r.len; ++i)
					{
						v[i] = r.farm[i];
					}
					delete r.farm;
					r.farm = v;
				}
			}
		}
		r.show();
	}
}

void contr::lowsupply(int x)
{
	if (isempty() == true)
	{
		cout << "There are no products\n";
	}
	else
	{
		repo r;
		for (int i = 0; i < rep.len; ++i)
		{
			if (rep.farm[i].getmenge()<x)
			{
				r.farm[r.len] = rep.farm[i];
				r.len++;
				if (r.len = r.cap)//the container is full
				{
					r.cap *= 2;
					drug* v = new drug[r.cap];
					for (int i = 0; i < r.len; ++i)
					{
						v[i] = r.farm[i];
					}
					delete r.farm;
					r.farm = v;
				}
			}
		}
		r.show();
	}
}