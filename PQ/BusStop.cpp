#include "BusStop.h"


BusStop::BusStop(size_t avgPasP, size_t avgBusP)
{
	this->pas = new PQ<Passenger>();
	this->bus = new PQ<Bus>();
	this->avgPas = avgPasP;
	size_t timer = 0;
	this->avgBus = avgBusP;
}

void BusStop::AddPass(int prioryty)
{
	Passenger* tObj= new Passenger("Person", prioryty);
	this->pas->Push(tObj, prioryty);
}

void BusStop::AddBuss()
{
	srand(time(NULL));
	Bus* tObj = nullptr;
	int j = 0;
	j = 1 + rand() % (12 - 1 + 1);
	tObj = new Bus(j, this->avgBus);
	this->bus->Push(tObj, j);
}

void BusStop::PrintPas()
{
	if (pas->getSize() == 0) {
		cout << "\nStop is empty!" << endl;
	}
	else {
		pas->Print();
	}
}


void BusStop::RunPas(uint32_t N, uint32_t t)
{
	float timeP = 0 ;
	float  amount = 0;
	uint32_t qtyPl = 0;
	uint32_t n = 0;
	srand(time(NULL));
	int i = 0;
	while (i< t) {
		this->timer++;
		uint32_t prior = 1 + rand() % (4 - 1 + 1);
		system("cls");
		cout << "\n-------Bus Stop-------" << endl;
		cout << "\nPrioryty" << "  " << "min" << endl;
		this->PrintPas();
		if (this->timer % this->avgPas == 0) {
			Passenger* p = new Passenger("Person", prior);
			pas->Push(p, prior);
		}
		if (this->timer % this->avgBus == 0) {
			uint32_t qty= 1 + rand() % (10- 1 + 1);
			Bus* b = new Bus(prior,qty);
			bus->Push(b,1);
			Sleep(500);
			cout << "\nBuss is come" << endl;
			cout << "\nQty of places: " << qty << endl;
			for(size_t i = 0; i < qty; i++) {
				qtyPl += qty;
				timeP += pas->SumTime();
				amount += pas->getSize();
				pas->Pop();
				n++;
			}
		}
		i++;
		Sleep(1000);
	}
	system("cls");
	cout << "\nAvg wait time= " << timeP / amount << endl;
	cout << "\nThe required bus interval= " << this->avgPas *( qtyPl/n) <<endl;
}

