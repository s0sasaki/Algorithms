#include<iostream>
using namespace std;

const int MAX =1000000;
int cnt;

void insertionSort(int *a, int n, int g){
	for(int i=g;i<n;i++){
		int v = a[i];
		int j = i-g;
		while(j>=0&&a[j]>v){
			a[j+g] = a[j];
			j = j-g;
			cnt++;
		}
		a[j+g] = v;
	}
}
void shellSort(int *a, int n){
	int m=1;
	int g[MAX];
	int i=1;
	g[0]=1;
	while(1+3*g[i-1]<=n){
		g[i] = 1+3*g[i-1];
		i++;
		m++;
	}
	cnt=0;
	for(int j=m-1;j>=0;j--)
		insertionSort(a,n,g[j]);
	
	cout<<m<<endl;
	for(int j=m-1;j>=0;j--){
		cout<<g[j];
		if(j>0) cout<<" ";
		else cout<<endl;	
	}
	cout<<cnt<<endl;
}

int main(){
	int n;
	int a[MAX];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	shellSort(a, n);
	for(int i=0;i<n;i++) cout<<a[i]<<endl;
	
	return 0;
}
