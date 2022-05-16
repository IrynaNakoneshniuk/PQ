#pragma once
#include<iostream>
#include "Node.h"
#include "Passenger.h"
#include "BusStop.h"
#include "Bus.h"
using namespace std;

class BusStop
{
	public:
	PQ <Passenger>* pas;
	PQ <Bus>* bus;
	size_t timer;
	size_t avgPas;
	size_t avgBus;
		BusStop(size_t avgPasP, size_t avgBusP);
		void AddPass(int prioryty);
		void AddBuss();
		void PrintPas();
		void RunPas(uint32_t N, uint32_t t);
};

