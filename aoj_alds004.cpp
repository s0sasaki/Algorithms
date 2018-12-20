#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int r[n];
	for(int i=0;i<n;i++) cin>>r[i];
	int min = r[0];
	int ret = r[1]-r[0];
	for(int i=1;i<n;i++){
		ret = ret>r[i]-min? ret:r[i]-min;
		min = min<r[i]? min:r[i];
	}
	cout<<ret<<endl;
	return 0;
}
