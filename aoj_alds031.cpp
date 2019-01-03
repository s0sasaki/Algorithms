#include<iostream>
#include<string>
using namespace std;

struct Node{
	int key;
	Node *parent, *left, *right;
};

static Node *root;

void insert(int v, Node *t){
	if(!root) {
		Node *a = new Node();
		a->key = v;
		a->parent = NULL;
		a->left = NULL;
		a->right = NULL;
		root = a;
	}else if(v<=t->key){
		if(!t->left) {
			Node *a = new Node();
			a->key = v;
			a->parent = t;
			a->left = NULL;
			a->right = NULL;
			t->left = a;
		}else{
			insert(v, t->left);
		}
	}else{
		if(!t->right) {
			Node *a = new Node();
			a->key = v;
			a->parent = t;
			a->left = NULL;
			a->right = NULL;
			t->right = a;
		}else{
			insert(v, t->right);
		}
	}
}

bool find(int v){
	Node *i = root;
	while(i!=NULL){
		if(v==i->key) return true;
		else if(v<i->key) i = i->left;
		else i = i->right;
	}
	return false;
}

void deletekey(int v){
	Node *i = root;
	Node *parent = NULL;
	while(1){
		if(!i) return;
		else if(v==i->key) break;
		parent = i;
		if(v<i->key) i=i->left;
		else i=i->right;
	}
	if(i->left==NULL&&i->right==NULL){
		if(parent==NULL)  ;
		else if(v<parent->key) parent->left =NULL;
		else parent->right = NULL;
		delete i;
	}else if(i->right==NULL){
		if(parent==NULL)  ;
		else if(v<parent->key) parent->left = i->left;
		else parent->right = i->left;
		i->left->parent = parent;
		delete i;
	}else if(i->left==NULL){
		if(parent==NULL)  ;
		else if(v<parent->key) parent->left = i->right;
		else parent->right = i->right;
		i->right->parent = parent;
		delete i;
	}else{
		Node *j=i->right;
		Node *parent_j=i;
		while(j->left!=NULL){
			parent_j=j;
			j=j->left;
		}
		if(parent_j==i) parent_j->right = NULL;
		else parent_j->left = j->right;
		if(parent_j->left) parent_j->left->parent = parent_j;
		i->key = j->key;
		delete j;
	}
}

void print_preorder(Node *i){
	if(!i) return;
	cout<<" "<<i->key;
	print_preorder(i->left);
	print_preorder(i->right);
}

void print_inorder(Node *i){
	if(!i) return;
	print_inorder(i->left);
	cout<<" "<<i->key;
	print_inorder(i->right);
}

int main(){
	int n,v;
	string s;
	cin>>n;
	root = NULL;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s=="insert") {
			cin>>v;
			insert(v,root);
		}else if(s=="find"){
			cin>>v;
			if(find(v)) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}else if(s=="delete"){
			cin>>v;
			deletekey(v);
		}else if(s=="print"){
			print_inorder(root);
			cout<<endl;
			print_preorder(root);
			cout<<endl;
		}
	}
	return 0;
}
