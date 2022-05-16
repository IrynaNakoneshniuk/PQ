#include "Bus.h"

Bus* Bus::operator=(const Bus* obj)
{
	this->number = obj->number;
	this->qtyPlaces = obj->qtyPlaces;
	return this;
}

ostream& operator<<(ostream& stream, const Bus* obj)
{
	stream << "\n" << obj->number<<" " <<obj->qtyPlaces<< endl;
	return stream;
}
