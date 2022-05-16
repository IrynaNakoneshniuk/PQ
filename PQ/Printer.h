#pragma once
#include "Printer.h"
#include "Node.h"
#include <iostream>

using namespace std;

class Printer {
private:
	string user;
	uint32_t prioritet;
	char timeP[100];
public:
	uint32_t getPrior() { return this->prioritet; }
	Printer(string user, uint32_t prioritet);
	Printer() :Printer("", 0) {};
	~Printer() = default;
	friend ostream& operator <<(ostream& out, const Printer* p);
};
