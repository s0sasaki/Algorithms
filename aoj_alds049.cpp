#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
struct Puzzle{
	int a[4][4];
	int calcDist(){
		int u,v, sum=0;
		for(int i=1;i<16;i++){
			for(int j=0;j<16;j++){
				if(i==a[j/4][j%4]){
					u = j/4;
					v = j%4;
					break;
				}
			}
			sum += abs((i-1)/4-u) + abs((i-1)%4-v);

		}
		return sum;
	}
};

bool operator< (const Puzzle &s, const Puzzle &t){
	for(int i=0;i<16;i++){
		if(s.a[i/4][i%4]==t.a[i/4][i%4]) continue;
		return s.a[i/4][i%4] < t.a[i/4][i%4];
	}
	return false;
}

struct Status{
	Puzzle p;
	int c,i,j;
	int distFromTarget;
	Status(Puzzle p1, int cnt){
		p = p1;
		for(int k=0;k<16;k++) {
			if(p.a[k/4][k%4]==0){
				i=k/4;
				j=k%4;
			}
		}
		distFromTarget = p.calcDist();
		c = cnt;
	}
};

bool operator< (const Status &s, const Status &t){
	return -(s.c + s.distFromTarget) < -(t.c + t.distFromTarget);
}

int solve(Puzzle p0){	
	set<Puzzle> visited;
	priority_queue<Status> que;
	Status s0(p0,0);
	que.push(s0);
	while(!que.empty()){
		Status s = que.top();que.pop();
		Puzzle p = s.p;
		if(visited.find(p)!=visited.end()) continue;
		if(s.distFromTarget==0) return s.c;
		visited.insert(p);

		Puzzle tmp;
		if(s.i!=0) {
			tmp = p;
			swap(tmp.a[s.i][s.j], tmp.a[s.i-1][s.j]);
			if(visited.find(tmp)==visited.end()) que.push(Status(tmp, s.c+1));
		}
		if(s.j!=0) { 
			tmp = p;
			swap(tmp.a[s.i][s.j], tmp.a[s.i][s.j-1]);
			if(visited.find(tmp)==visited.end()) que.push(Status(tmp, s.c+1));
		}
		if(s.i!=3) { 
			tmp = p;
			swap(tmp.a[s.i][s.j], tmp.a[s.i+1][s.j]);
			if(visited.find(tmp)==visited.end()) que.push(Status(tmp, s.c+1));
		}
		if(s.j!=3) { 
			tmp = p;
			swap(tmp.a[s.i][s.j], tmp.a[s.i][s.j+1]);
			if(visited.find(tmp)==visited.end()) que.push(Status(tmp, s.c+1));
		}
	}
	return -1;
}

int main(){
	Puzzle p;
	for(int i=0;i<16;i++) {
		cin>>p.a[i/4][i%4];
	}

	cout<<solve(p)<<endl;
}
