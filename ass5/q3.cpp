#include <iostream>
using namespace std;

class node{
	int data;
	node *next;
};

void findmiddle(){
	if(!head){
		return;
	}
	
	node *slow=head;
	node *fast=head;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	
	cout<<"middle element: "<<slow->data<<endl;
}

int main(){
	findmiddle();
}
