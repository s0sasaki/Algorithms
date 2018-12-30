#include<iostream>
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

int main(){
	int n,a,b,tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		node[i].parent = -1;
		node[i].left = -1;
		node[i].right = -1;
	}
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>b;
		for(int j=0;j<b;j++){
			if(j==0) {
				cin>>node[a].left;
				tmp = node[a].left;
			}else {
				cin>>node[tmp].right;
				tmp = node[tmp].right;
			}
			node[tmp].parent = a;
		}
	}

	for(int i=0;i<n;i++){
		cout<<"node "<<i<<": parent = "<<node[i].parent<<", depth = "<<getDepth(i);
		if(node[i].parent == -1) cout<<", root";
		else if(node[i].left == -1) cout<<", leaf";
		else cout<<", internal node";
		cout<<", [";
		tmp = node[i].left;
		bool flag = false;
		while(tmp!=-1){
			if(flag) cout<<", ";
			else flag = true;
			cout<<tmp;
			tmp = node[tmp].right;
		}
		cout<<"]"<<endl;
	}
	
	return 0;
}
