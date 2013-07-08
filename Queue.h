#ifndef Queue_h
#define Queue_h
#include "L1S.h"
class Queue{
public:
	unsigned int size;
	Queue();
	~Queue();
	Queue(const Queue&);
	Queue& operator = (const Queue&);
	void putin(const Stack& stack);
	void takeout();
	void makeitempty();
	bool isempty()const;
	Stack& viewlast();
private:
	L1S los;
	void copy(const Queue& queue);
};
#endif