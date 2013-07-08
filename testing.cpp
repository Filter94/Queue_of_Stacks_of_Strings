#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

int main() {
	Queue Q;
	Stack S;
	cout<<"Input:"<<endl;
	for(char j=0;j<=3;j++){	
		for(char i='A'+j*5;i<'F'+j*5;i++){
			char* t=new char[3];
			t[0]=i;
			t[1]=i+32;
			t[2]='\0';
			S.push(t);
			cout<<S.top()<<' ';
			delete t;
		}
		cout<<endl;
		Q.putin(S);
		S.makeitempty();
	}
	cout<<"Output:"<<endl;
	while(!Q.isempty()){
		while(!Q.viewlast().isempty()){
		cout<< Q.viewlast().top()<<' ';
		Q.viewlast().pop();
		}
		cout<<endl;
		Q.takeout();
	}
	system("pause");
}