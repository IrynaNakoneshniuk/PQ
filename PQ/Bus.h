#pragma once
#include <iostream>
using namespace std;
class Bus
{
	private:
	uint32_t number;
	uint32_t qtyPlaces;
    public:
	Bus(uint32_t number, uint32_t qtyPlacesP) {
		this->number = number;
		this->qtyPlaces = qtyPlacesP;

	}
	Bus() :Bus(0,0) {};
	void setNumber(uint32_t number) { number = this->number; }
	uint32_t getNumber() { return this->number; }
	Bus* operator=(const Bus* obj);
	friend ostream& operator<<(ostream& stream, const Bus* obj);
};

