#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, ans=0, amin=10000;
	cin>>n;
	int a[n], b[n], T[10000];
	bool V[n];
	for(int i=0;i<n;i++) V[i] = true;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		b[i]=a[i];
		amin=min(a[i], amin);
	}
	sort(b, b+n);
	for(int i=0;i<n;i++) T[b[i]] = i;

	for(int i=0;i<n;i++) {
		if(!V[i]) continue;
		int j = i, tmpmin = a[i], c=0;
		int S = 0;
		while(V[j]){
			c++;
			tmpmin = min(tmpmin, a[j]);
			S += a[j];
			V[j] = false;
			j = T[a[j]];
		}
		ans += min(S+(c-2)*tmpmin, S+tmpmin+(c+1)*amin);
	}

	cout<<ans<<endl;
	return 0;
}
