#ifndef L1S_h
#define L1S_h
#include "StackonL1.h"

class L1S{
public:
	 L1S();//crt
	 ~L1S();//dsry
	 L1S(const L1S&);//cpy
	 L1S& operator = (const L1S&);//=
	 void addtoend(const Stack& S);
	 void addtobegin(const Stack& S);
	 void makeitempty();
	 void tobegin();
	 void tonext();
	 void toend();
	 bool isempty()const;
	 void erase();
	 Stack& getcur();

private:
	struct Lelem{
		Lelem* next;
		Stack stack;
	};
	Lelem* tail;
	Lelem* head;
	Lelem* temp;
	void copy(const L1S& List);
};
#endif 