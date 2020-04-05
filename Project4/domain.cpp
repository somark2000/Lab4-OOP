#include <iostream>
#include "domain.h"

drug::drug()
{

}

drug::drug(std::string name, float k, int m, float p)
{
	this->name = name;
	this->menge = m;
	this->preis = p;
	this->konzentration = k;
}

drug::~drug()
{

}

std::string drug::getname()
{
	return this->name;
}

int drug::getmenge()
{
	return this->menge;
}

float drug::getpreis()
{
	return this->preis;
}

float drug::getkonzentration()
{
	return this->konzentration;
}

void drug::setkonzentration(float k)
{
	this->konzentration = k;
}

void drug::setname(std::string n)
{
	this->name = n;
}

void drug::setmenge(int m)
{
	this->menge = m;
}

void drug::setpreis(float p)
{
	this->preis = p;
}

void drug::zeigen()
{
	cout << "Name: " << name << " Konzentration: " << konzentration << " Menge: " << menge << " Preis: " << preis << endl;
}