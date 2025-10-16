  #include <iostream>
  #include <vector>
using namespace std;


class node{
	public:
		int data;
		node *next;
		
		node(int value){
			data=value;
			next=NULL;
		}
};

int main(){
	node *curr=head;
	node *prev=NULL;
	node *fut=NULL;
	while(curr){
		fut=curr->next;
		curr->next=prev;
		prev=curr;
		curr=fut;
	}
	prev=head;
	return head;
	
}
