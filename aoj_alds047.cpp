#include<iostream>
using namespace std;

int n;
int a[8][8];
bool emptyrow[8], emptycol[8], emptyrightup[15], emptyleftup[15];

bool solve(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(emptyrow[i]) continue;
			if(emptycol[j]) continue;
			if(emptyrightup[i+j]) continue;
			if(emptyleftup[i-j+7]) continue;
			a[i][j] = 1;
			emptyrow[i] = true;
			emptycol[j] = true;
			emptyrightup[i+j] = true;
			emptyleftup[i-j+7] = true;
			if(solve()) return true;
			a[i][j] = 0;
			emptyrow[i] = false;
			emptycol[j] = false;
			emptyrightup[i+j] = false;
			emptyleftup[i-j+7] = false;
		}
	}
	int sum=0;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			sum+=a[i][j];
	return sum==8;

}

int main(){
	int r,c;
	cin>>n;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++) 
			a[i][j] = 0;
	}
	for(int i=0;i<8;i++) emptyrow[i] = false;
	for(int i=0;i<8;i++) emptycol[i] = false;
	for(int i=0;i<15;i++) emptyrightup[i] = false;
	for(int i=0;i<15;i++) emptyleftup[i] = false;
	for(int i=0;i<n;i++){
		cin>>r>>c;
		a[r][c] = 1;
		emptyrow[r] = true;
		emptycol[c] = true;
		emptyrightup[r+c] = true;
		emptyleftup[r-c+7] = true;
	}

	solve();

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(a[i][j]) cout<<"Q";
			else cout<<".";
		}
		cout<<endl;
	}
	return 0;
}
