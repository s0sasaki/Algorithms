#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;

enum Color{WHITE, GRAY, BLACK};
struct edge{
	int v,c;
	edge(int v, int c): v(v), c(c){}
};
bool operator< (const edge &e, const edge &f){return e.c<f.c;}

int n;
vector<vector<edge>> a;
int *r;

void dijkstra(){
	Color color[n];
	for(int i=0;i<n;i++) color[i]=WHITE;
	color[0] = GRAY;
	priority_queue<edge> pq;
	pq.push(edge(0,0));
	while(!pq.empty()){
		edge e = pq.top(); pq.pop();
		if(color[e.v]==BLACK) continue;
		color[e.v] = BLACK;
		r[e.v] = - e.c;
		
		for(int i=0;i<a[e.v].size();i++){
			edge f = a[e.v][i];
			if(color[f.v]==BLACK) continue;
			color[f.v] = GRAY;
			int cost = e.c - f.c;
			pq.push(edge(f.v, cost));
		}
	}
	
}

int main(){
	int u,k,v,c;
	cin>>n;
	a = vector<vector<edge>>(n);
	r = new int [n];
	for(int i=0;i<n;i++){
		cin>>u>>k;
		for(int j=0;j<k;j++){
			cin>>v>>c;
			a[u].emplace_back(edge(v,c));
		}
	}
	
	dijkstra();

	for(int i=0;i<n;i++)
		cout<<i<<" "<<r[i]<<endl;
	return 0;
}
