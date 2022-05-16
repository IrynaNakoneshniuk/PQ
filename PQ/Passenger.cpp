#include "Passenger.h"
#include <iostream>
#include <Windows.h>

Passenger::Passenger(string category, uint32_t prior)
{
	this->category = category;
	this->prior = prior;
}

Passenger* Passenger::operator=(const Passenger* obj)
{
	this->category = obj->category;
	this->prior = obj->prior;
	return this;
}


ostream& operator<<(ostream& stream, const Passenger* obj)
{
	stream << "\n" << obj->prior << "  " << obj->category << "  ";
	return stream;
}
