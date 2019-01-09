#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
enum Color{WHITE, GRAY, BLACK};

int n;
int **a;
Color *color;

//This is not Prim's algorithm with O(n^2).
//It should update minp for the newly-blacked node.
int prim(){
	color[0] = BLACK;
	int sum=0;
	while(1){
		int p, minp=INT_MAX;
		for(int i=0;i<n;i++){
			if(color[i]!=BLACK) continue;
			for(int j=0;j<n;j++){
				if(color[j]==BLACK||a[i][j]==-1) continue;
				else if(color[j]==WHITE) color[j] = GRAY;
				if(minp>a[i][j]){
					minp = a[i][j];
					p = j;
				}
			}
		}
		if(minp==INT_MAX) break;
		sum += minp;
		color[p] = BLACK;
	}
	return sum;
}

int main(){
	cin>>n;
	a = new int*[n];
	for(int i=0;i<n;i++) a[i] = new int[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	color = new Color[n];
	for(int i=0;i<n;i++) color[i] = WHITE;

	cout<<prim()<<endl;

	delete a;
	return 0;
}
