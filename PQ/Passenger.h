#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class Passenger
{
	public:
	string category;
	uint32_t prior;
	  Passenger(string category, uint32_t prior);
	  ~Passenger() { this->category.clear(); }
	  uint32_t getPriority() { return this->prior; }
	  Passenger* operator=(const Passenger* obj);
	  friend ostream& operator<<(ostream& strem, const Passenger* obj);
	  
};

