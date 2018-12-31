#include<iostream>
#include<vector>
using namespace std;

vector<int> pre, in, post;
int n;

void rec(int p, int s, int t){
	if(t<=0) return;
	int v = pre[p];
	int i = s;
	while(in[i]!=v) i++;
	rec(p+1, s, i-s);
	rec(p+i-s+1, i+1, t-(i-s)-1);
	post.push_back(v);
}


int main(){
	cin>>n;
	pre.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++) cin>>pre[i];
	for(int i=0;i<n;i++) cin>>in[i];

	rec(0,0,n);
	
	for(int i=0;i<post.size();i++){
		cout<<post[i];
		if(i==post.size()-1) cout<<endl;
		else cout<<" ";
	}
	return 0;
}
