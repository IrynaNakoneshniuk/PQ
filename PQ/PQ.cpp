#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BusStop.h"
#include"Node.h"
#include "Printer.h"

using namespace std;
int main()
{
    int j = 0;
   /* uint32_t intervalBus;
    uint32_t intervalPas;
    uint32_t N;
    uint32_t v;
    cout << "\n Enter interval bus: ";
    cin>>intervalBus;
    cout << "\n Enter interval of movement of passenger: ";
    cin >> intervalPas;
    cout << "\nEnter the time interval orthe analysis: ";
    cin >>v;
    cout << "\nEnter the amount of passenger at the stop: ";
    cin >> N;
    BusStop* bus = new BusStop(intervalPas, intervalBus);
    bus->RunPas(N,v);*/
    PQ<Printer>* p = new PQ<Printer>();
    PQ<Printer>* saveP = new PQ<Printer>();
    for (size_t i = 0; i < 10; i++) {
        j = 1 + rand() % (4 - 1 + 1);
        Printer* tmp = new Printer("U",j);
        p->Push(tmp,j);
    }
    saveP->Print2();
    return 0;
}


