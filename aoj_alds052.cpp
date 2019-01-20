#include<iostream>
#include<string>
using namespace std;

string a[1000], b[1000];
int r, c;

string oneString(string *v, int i, int j){
	string s;
	for(int p=i;p<i+r;p++){
		s += v[p].substr(j, c);
	}
	return s;
}

int main(){
	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++) cin>>a[i];
	cin>>r>>c;
	for(int i=0;i<r;i++) cin>>b[i];

	string target = oneString(b, 0, 0);

	for(int i=0;i+r-1<h;i++){
		for(int j=0;j+c-1<w;j++){
			if(target == oneString(a, i, j)) cout<<i<<" "<<j<<endl;
		}
	}

	return 0;
}
