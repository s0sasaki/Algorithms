#include<iostream>
#include<string>
using namespace std;
int main(){
	long long nb=0, c=0;
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]=='B')	nb += 1;
		else c += nb;
	}
	cout<<c<<endl;
	return 0;
}
