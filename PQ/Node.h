#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

template <class T>
class Node
{
    public:
	T * value;
	Node<T>* next;
	Node<T>* prev;
	uint32_t priority;
	uint32_t time;
	Node(T* value, uint32_t priorityP, uint32_t time) {
		this->value = value;
		this->prev = nullptr;
		this->next = nullptr;
		this->priority = priorityP;
		this->time =time;
	}
	Node() :Node(nullptr,1,0) {};
	~Node() = default;
	T* getValue() { return this->value; }
	uint32_t getTime() { return this->time++; }
	uint32_t getPriority() { return this->priority; }
};

template <class T>
class PQ {
   private:
	  Node<T>* head;
	  Node<T>* tail;
	  uint32_t amount; 
   public:
	   PQ() {
		   head = nullptr;
		   tail = nullptr;
		   amount = 0;
	   }
	   T* Peek();
	   void Print();
	   void Print2();
	   void ClearAll();
	   void Push(T* elem, uint32_t priority);
	   void Pop();
	   uint32_t getSize() { return this->amount; }
	   void RunTime();
	   void DeLInTime(uint32_t time, uint32_t gty);
	   uint32_t SumTime();
};

template<class T>
inline T* PQ<T>::Peek(){
	return this->head->getValue();
}


template<class T>
inline void PQ<T>::Print()
{
	Node <T>* node_elem = this->head;;
	while (node_elem != nullptr) {
		cout << node_elem->getValue() << node_elem->getTime()<< endl;
		node_elem = node_elem->next;
	}
}

template<class T>
inline void PQ<T>::Print2()
{
	Node <T>* node_elem = this->head;;
	while (node_elem != nullptr) {
		cout << node_elem->getValue() << endl;
		node_elem = node_elem->next;
	}
}
template<class T>
inline void PQ<T>::ClearAll()
{
	if (this->amount > 0) {
		Node <T>* node_elem = new Node <T>();
		node_elem = this->tail;
		while (node_elem != nullptr) {
			node_elem = this->tail;
			this->tail = node_elem->prev;
			tail->next = nullptr;
			amount--;
			delete node_elem;
		}
	}
}

template<class T>
inline void PQ<T>::Push(T* elem, uint32_t priority)
{
	Node<T>* node_elem = new Node<T>(elem, priority,0);
	Node<T>* buf;
	if (head == NULL || priority < head->priority) {
		node_elem->next = head;
		head = node_elem;
	}
	else {
		buf = head;
		while (buf->next != NULL && buf->next->priority <= priority)
	    buf = buf->next;
		node_elem->next = buf->next;
		buf->next = node_elem;
	}
	this->amount++;
}

template<class T>
inline void PQ<T>::Pop()
{
	Node<T>* node_elem = this->head;
	if (node_elem== nullptr)
	{
		tail = head = nullptr;
	}
	else {
		this->head = this->head->next;
	}
	delete node_elem;
	amount--;
}

template<class T>
inline void PQ<T>::RunTime()
{
	Node <T>* node_elem = this->head;;
	while (node_elem != nullptr) {
		node_elem->time++;
		node_elem = node_elem->next;
	}
}

template<class T>
inline void PQ<T>::DeLInTime(uint32_t time, uint32_t gty)
{
	int i = gty;
	Node <T>* node_elem = this->head;
	while (i > 1 && node_elem != nullptr) {
		if (node_elem->time >= time && node_elem != nullptr) {
			this->Pop();
			node_elem = node_elem->next;
			i--;
		}
	}
}

template<class T>
inline uint32_t PQ<T>::SumTime()
{
	uint32_t sumTime = 0;
	Node <T>* node_elem = this->head;;
	while (node_elem != nullptr) {
		sumTime += node_elem->getTime();
		node_elem = node_elem->next;
	}
	return sumTime;
}



