#include"L1C.h"
#include<string.h>
#include<stdexcept>

L1C::L1C(){
	head =nullptr;
	temp =nullptr;
	tail =nullptr;
}

L1C::~L1C(){
	makeitempty();
}

L1C::L1C(const L1C& List){
	copy(List);
}

L1C& L1C::operator = (const L1C& List){
	if (this!=&List){
		makeitempty();
		copy(List);
	}
	return *this;
}

void L1C::add(char* S){
	Lelem* a=new Lelem ;
	if(S){
		a->str=new char[strlen(S)+1];
		strcpy(a->str,S);
	}
	else{
		a->str=0;
	}
	a->next=nullptr;
	if(head){
		tail->next=a;
	}
	else{
		head=a;
	}
	tail=a;
	temp=tail;
}

void L1C::makeitempty(){
	temp=head;
	Lelem* a;
	while (temp){
		a=temp->next;
		delete temp;
		temp=a;
	}
	head=nullptr;
	tail=nullptr;
}

void L1C::tobegin(){
	temp=head;
}

void L1C::tonext(){
	if(temp)
		temp=temp->next;
	else
		throw std::out_of_range("End of list.");
}



void L1C::toend(){
	temp=tail;
}

bool L1C::isempty()const{
	return !head;
}

void L1C::erase(){//Удаляет элемент temp, перемещает temp за удаленный или temp==nullptr если temp в конце.
	if(temp){
		Lelem *a,*b;
		if(temp){
			a=temp->next;
		}
		else{
			a=nullptr;
		}
		b=head;
		if(head!=temp){
			while(b->next!=temp){
				b=b->next;
			}
			delete temp;
			b->next=a;
			temp=a;
			if (!a){
				tail=b;
				temp=tail;
			}
		}
		else{
			delete head;
			tail=nullptr;
			temp=nullptr;
			head=nullptr;
		}
	}
	else{throw std::logic_error("Current element is bad.");
	}
}

char* L1C::getcur(){
	if (!temp){throw std::logic_error("Current element is bad.");
	}
	return temp->str;
}

void L1C::copy(const L1C& List){
	Lelem* a=List.head;
	while(a){
		add(a->str);
		a=a->next;
	}
	temp=head;
}
