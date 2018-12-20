#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	int r=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		int j=2;
		for(;j*j<=a[i];j++){
			if(a[i]%j==0) break;
		}
		if(j*j>a[i]) r++;
	}
	cout<<r<<endl;
	return 0;
}
