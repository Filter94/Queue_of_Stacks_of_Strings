#include "StackonL1.h"
void Stack:: push(char* S){
	List.add(S);
}
void Stack:: pop(){
	List.toend();
	List.erase();
}

char* Stack:: top(){
	L1C L;
	L=List;
	L.toend();
	return L.getcur();
}

void Stack::makeitempty(){
	List.makeitempty();
}

bool Stack::isempty()const{
	return List.isempty();
}