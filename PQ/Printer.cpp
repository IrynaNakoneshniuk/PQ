#define _CRT_SECURE_NO_WARNINGS
#include "Printer.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;

Printer::Printer(string user, uint32_t prioritet)
{
	time_t tt = (time(nullptr));
	struct tm t;
	char buf[100];
	t = *localtime(&tt);
	strftime(buf, sizeof(buf), "%A %d/%m/%Y %X", &t);
	this->user = user;
	this->prioritet = prioritet;
	strcpy(timeP, buf);
}

ostream& operator<<(ostream& out, const Printer* p)
{
	cout << "Prioritet: " << p->prioritet << endl;
	cout << "User: " << p->user << endl;
	cout << "Time: " << p->timeP << endl;
	return out;
}
