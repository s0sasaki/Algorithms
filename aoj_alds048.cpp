#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
struct Status{
	int a[3][3];
	int c,i,j;
	bool isTarget(){
		for(int i=0;i<8;i++){
			if(a[i/3][i%3]!=i+1) return false;
		}
		return true;
	}
};

bool operator< (const Status &s, const Status &t){
	for(int i=0;i<9;i++){
		if(s.a[i/3][i%3]==t.a[i/3][i%3]) continue;
		return s.a[i/3][i%3] < t.a[i/3][i%3];
	}
	return false;
}

queue<Status> que;
set<Status> visited;

int solve(){
	while(1){
		Status s = que.front();que.pop();
		if(visited.find(s)!=visited.end()) continue;
		if(s.isTarget()) return s.c;
		visited.insert(s);
		s.c++;
		if(s.i!=0) {
			swap(s.a[s.i][s.j], s.a[s.i-1][s.j]);
			s.i = s.i-1;
			que.push(s);
			s.i = s.i+1;
			swap(s.a[s.i][s.j], s.a[s.i-1][s.j]);
		}
		if(s.j!=0) { 
			swap(s.a[s.i][s.j], s.a[s.i][s.j-1]);
			s.j = s.j-1;
			que.push(s);
			s.j = s.j+1;
			swap(s.a[s.i][s.j], s.a[s.i][s.j-1]);
		}
		if(s.i!=2) { 
			swap(s.a[s.i][s.j], s.a[s.i+1][s.j]);
			s.i = s.i+1;
			que.push(s);
			s.i = s.i-1;
			swap(s.a[s.i][s.j], s.a[s.i+1][s.j]);
		}
		if(s.j!=2) { 
			swap(s.a[s.i][s.j], s.a[s.i][s.j+1]);
			s.j = s.j+1;
			que.push(s);
			s.j = s.j-1;
			swap(s.a[s.i][s.j], s.a[s.i][s.j+1]);
		}
	}
}
int main(){
	Status s;
	s.c=0;
	for(int i=0;i<9;i++) {
		cin>>s.a[i/3][i%3];
		if(s.a[i/3][i%3]==0){
			s.i=i/3;
			s.j=i%3;
		}
	}
	que.push(s);

	cout<<solve()<<endl;
}
