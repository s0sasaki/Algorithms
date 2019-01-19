#include<iostream>
#include<string>
using namespace std;
int main(){
	string t,p;
	cin>>t>>p;
	for(int i=0;i+p.size()-1<t.size();i++){
		bool same = true;
		for(int j=p.size()-1;j>=0;j--){
			if(t[i+j]!=p[j]) {
				same = false;
				break;
			}
		}
		if(same) cout<<i<<endl;
	}
	return 0;
}
