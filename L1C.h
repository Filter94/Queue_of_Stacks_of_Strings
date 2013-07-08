#ifndef L1C_h
#define L1C_h

class L1C{
public:
	 L1C();//crt
	 ~L1C();//dsry
	 L1C(const L1C&);//cpy
	 L1C& operator = (const L1C&);//=
	 void add(char* S);
	 void makeitempty();
	 void tobegin();
	 void tonext();
	 void toend();
	 bool isempty()const;
	 void erase();
	 char* getcur();

private:
	struct Lelem{
		Lelem* next;
		char* str;
	};
	Lelem* tail;
	Lelem* head;
	Lelem* temp;
	void copy(const L1C& List);
};
#endif 