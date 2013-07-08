#include"L1S.h"
#include<string.h>
#include<stdexcept>

L1S::L1S(){
	head =nullptr;
	temp =nullptr;
	tail =nullptr;
}

L1S::~L1S(){
	makeitempty();
}

L1S::L1S(const L1S& List){
	copy(List);
}

L1S& L1S::operator = (const L1S& List){
	if (this!=&List){
		makeitempty();
		copy(List);
	}
	return *this;
}

void L1S::addtoend(const Stack & S){
	Lelem* a=new Lelem ;
	a->stack=S;
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

void L1S::addtobegin(const Stack& S){
	Lelem* a=new Lelem ;
	a->stack=S;
	a->next=head;
	head=a;
	temp=head;
	if(!head->next){
		tail=head;
	}
}

void L1S::makeitempty(){
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

void L1S::tobegin(){
	temp=head;
}

void L1S::tonext(){
	if(temp)
		temp=temp->next;
	else
		throw std::out_of_range("End of list.");
}



void L1S::toend(){
	temp=tail;
}

bool L1S::isempty()const{
	return !head;
}

void L1S::erase(){//Удаляет элемент temp, перемещает temp за удаленный или temp==nullptr если temp в конце.
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

Stack& L1S::getcur(){
	if (!temp){throw std::logic_error("Current element is bad.");
	}
	return temp->stack;
}

void L1S::copy(const L1S& List){
	Lelem* a=List.head;
	while(a){
		addtoend(a->stack);
		a=a->next;
	}
	temp=head;
}
