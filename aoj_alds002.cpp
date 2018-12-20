
#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}

int main(){
	int a,b,r;
	cin>>a>>b;
	if(a>b){
		r = gcd(a,b);
	}else{
		r = gcd(b,a);
	}
	cout<<r<<endl;
	return 0;
}
