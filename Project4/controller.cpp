#include <iostream>
#include "controller.h"
#include <algorithm>
#include <vector>

using namespace std;

contr::contr()
{
	rep = repo();
}

contr::~contr()
{
	//delete rep.farm;
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
		//cout << rep.len;
		if (rep.len == rep.cap)//the container is full
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
	cout << rep.len << endl;
	action a;
	a.act = 1;
	a.d = d;
	history_undo.push_back(a);
}

void contr::uadd(drug d)
{
	rep.farm[rep.len] = d;
	rep.len++;
	action a;
	a.act = 1;
	a.d = d;
	history_redo.push_back(a);
}

void contr::remove(drug d)
{
	if (isempty() == true)
	{
		std::cout << "Container empty\n";
		return;
	}
	if (search(d) == false)
	{
		std::cout << "The searched drug is not listed\n";
		return;
	}
	drug m;
	for (int i = 0; i < rep.len; ++i)
	{
		if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
		{
			m = rep.farm[i];
			for (int k = i + 1; k < rep.len; ++k)
			{
				rep.farm[k - 1] = rep.farm[k];
			}
			rep.len--;
		}
	}
	action a;
	a.act = 3;
	a.d = m;
	history_undo.push_back(a);
}

void contr::uremove(drug d)
{
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
	action a;
	a.act = 3;
	a.d = d;
	history_redo.push_back(a);
}


void contr::update(drug d)
{
	drug mm;
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
				mm = rep.farm[i];
				std::string w;

				//update the price
				std::cout << "Current price of the drug is " << d.getpreis() << "\n Do you want to update it? (y/n)";
				std::cin >> w;
				if (w == "y")
				{
					float x;
					std::cout << "The new price is ";
					std::cin >> x;
					rep.farm[i].setpreis(x);
				}

				//update the amount
				std::cout << "Current amount of the drug is " << d.getmenge() << "\n Do you want to update it? (y/n)";
				std::cin >> w;
				if (w == "y")
				{
					int x;
					std::cout << "The new amount is ";
					std::cin >> x;
					rep.farm[i].setmenge(x);
				}
			}
		}
	}
	action a;
	a.act = 2;
	a.d = mm;
	history_undo.push_back(a);
}

void contr::uupdate(drug d)
{
	for (int i = 0; i < rep.len; ++i)
	{
		if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
		{
			rep.farm[i].setpreis(d.getpreis());
			rep.farm[i].setmenge(d.getmenge());
		}
	}
	action a;
	a.act = 3;
	a.d = d;
	history_redo.push_back(a);
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
			if (rep.farm[i].getname().find(s) == 0)
			{
				//r.farm[r.len++] = rep.farm[i];
				rep.farm[i].zeigen();

				/*if (r.len = r.cap)//the container is full
				{
					r.cap *= 2;
					drug* v = new drug[r.cap];
					for (int i = 0; i < r.len; ++i)
					{
						v[i] = r.farm[i];
					}
					delete r.farm;
					r.farm = v;
				}*/
			}
		}
		r.show();
	}
}

void contr::name_sort()
{
	auto relation = [](drug a, drug b) { return a.getname() < b.getname(); };
	sort(rep.farm, rep.farm + rep.len, relation);

	for (int i = 0; i < rep.len; i++)
		rep.farm[i].zeigen();

}

//zeigt die Medikamente mit einer kleineren Menge als eine gegebene
void contr::menge_sort(int menge)
{
	if (isempty() == true)
	{
		std::cout << "There are no products\n";
	}
	else
	{
		for (int i = 0; i < rep.len; i++)
		{
			if (rep.farm[i].getmenge() < menge)
				rep.farm[i].zeigen();
		}
	}
}

//sortiert nach Preis
void contr::preis_sort()
{
	auto relation = [](drug a, drug b) { return a.getpreis() < b.getpreis(); };
	sort(rep.farm, rep.farm + rep.len, relation);

	for (int i = 0; i < rep.len; i++)
		rep.farm[i].zeigen();

}

//undo die letzte Operation
void contr::undo()
{
	if (history_undo.size() != 0)
	{
		action med = history_undo.at(history_undo.size() - 1);
		if (med.act == 1)
		{
			uremove(med.d);
		}
		else if (med.act == 2)
		{
			uupdate(med.d);
		}
		else
		{
			uadd(med.d);
		}
		history_undo.pop_back();
		return;
	}
	//cout << "undo"<<" "<<endl;
	std::cout << " Nu este posibil! " << endl;
}

//redo die letzte Operation
void contr::redo()
{
	if (history_redo.size() != 0)
	{
		action med = history_redo.at(history_redo.size() - 1);
		if (med.act == 1)
		{
			remove(med.d);
		}
		else if (med.act == 2)
		{
			update(med.d);
		}
		else
		{
			add(med.d);
		}
		history_undo.pop_back();
		return;
	}
	//cout << "undo"<<" "<<endl;
	std::cout << " Nu este posibil! " << endl;
}