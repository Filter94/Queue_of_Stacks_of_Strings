#ifndef Stack_h
#define Stack_h
#include "L1C.h"

class Stack{
public:
void push(char* S);
void pop();
char* top();
bool isempty()const;
void makeitempty();
private:
	L1C List;
};
#endif