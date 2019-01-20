#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
long long B = 1717171;
int main(){
	string t,p;
	cin>>t>>p;
	long long hash[t.size()+1];
	long long pow[t.size()+1];
	hash[0]=0;
	pow[0]=1;
	for(int i=0;i<t.size();i++){
		hash[i+1] = hash[i]*B + t[i];
		pow[i+1] = pow[i]*B;
	}
	long long base=0;
	for(int i=0;i<p.size();i++) base = base*B+p[i];

	for(int i=0;i+p.size()<=t.size();i++){
		int left=i, right=i+p.size()-1;
		if(hash[right+1]-hash[left]*pow[right-left+1]==base) printf("%d\n", i);
	}
	return 0;
}
