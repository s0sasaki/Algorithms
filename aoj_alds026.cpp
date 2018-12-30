#include<iostream>
#include<algorithm>
using namespace std;

static const int MAX = 100000;

struct Node{
	int parent, left, right;
};

Node node[MAX];

int getDepth(int i){
	int j = i;
	int d = 0;
	while(node[j].parent!=-1){
		j = node[j].parent;
		d++;
	}
	return d;
}

int getHeight(int i){
	if(i==-1) return -1;
	else return 1+max(getHeight(node[i].left), getHeight(node[i].right));
}

int main(){
	int n,a,tmp,deg,sib;
	cin>>n;
	for(int i=0;i<n;i++){
		node[i].parent = -1;
		node[i].left = -1;
		node[i].right = -1;
	}
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>node[a].left;
		if(node[a].left!=-1) node[node[a].left].parent = a;
		cin>>node[a].right;
		if(node[a].right!=-1) node[node[a].right].parent = a;
	}

	for(int i=0;i<n;i++){
		cout<<"node "<<i<<": parent = "<<node[i].parent;
		tmp = node[i].parent;
		if(tmp == -1) sib = -1;
		else if(node[tmp].left==i)  sib = node[tmp].right;
		else sib = node[tmp].left;
		cout<<", sibling = "<<sib;
		deg = 0;
		if(node[i].left!=-1) deg += 1;
		if(node[i].right!=-1) deg += 1;
		cout<<", degree = "<<deg;
		cout<<", depth = "<<getDepth(i);
		cout<<", height = "<<getHeight(i);
		if(node[i].parent == -1) cout<<", root";
		else if(node[i].left==-1 && node[i].right==-1) cout<<", leaf";
		else cout<<", internal node";
		cout<<endl;
	}
	
	return 0;
}
