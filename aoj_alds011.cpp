#include<iostream>
using namespace std;
static const int MAX = 1000000;

class Node{
  public:
	int value;
	Node *prev, *next;
};

class DoublyLinkedList{
	Node *nil;
  public:
	DoublyLinkedList(){
		nil = new Node;
		nil->prev = nil;
		nil->next = nil;
	};
	void print(){
		Node *i = nil->next;
		while(i!=nil){
			cout<< i->value;
			if(i->next!=nil) cout<<" ";
			i = i->next;
		}
		cout<<endl;
	};
	void insert(int v){
		Node *a = new Node;
		a->value = v;
		a->prev = nil;
		a->next = nil->next;
		a->next->prev = a;
		nil->next = a;
	};
	void deletekey(int v){
		if(nil->next==nil) return;
		Node *j = nil->next;
		while(j!=nil && j->value!=v){
			j = j->next;
		}
		if(j!=nil){
			j->prev->next = j->next;
			j->next->prev = j->prev;
			delete j;
		}
	};
	void deleteFirst(){
		if(nil->next==nil) return;
		Node *i = nil->next;
		nil->next = i->next;
		i->next->prev = nil;
		delete i;
	};
	void deleteLast(){
		if(nil->next==nil) return;
		Node *i = nil->prev;
		nil->prev = i->prev;
		i->prev->next = nil;
		delete i;
	};
};
int main(){
	DoublyLinkedList a;
	int n;
	cin>>n;
	string s;
	int v;
	for(int i=0;i<n;i++){
		cin >>s;
		if(s=="insert") {cin>>v; a.insert(v);}
		else if(s=="delete") {cin>>v; a.deletekey(v);}
		else if(s=="deleteFirst") a.deleteFirst();
		else if(s=="deleteLast") a.deleteLast();
	}
	a.print();
	return 0;
}
