#pragma once
using namespace std;
#include <iostream>

class drug
{
private:
	std::string name;
	float konzentration, preis;
	int menge;
public:
	//constuctor
	drug();
	drug(std::string name, float k, int m, float p);
	
	//destructor
	~drug();

	//name getter
	std::string getname();

	//name setter
	void setname(std::string name);

	//konzentration getter
	float getkonzentration();

	//konzentration setter
	void setkonzentration(float k);

	//menge getter
	int getmenge();

	//menge setter
	void setmenge(int m);

	//preis getter
	float getpreis();

	//preis setter
	void setpreis(float p);

	void zeigen();
};
