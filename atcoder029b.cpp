#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto& t:a) cin>>t;
	sort(a.begin(), a.end());
	vector<int> used(n,0);
	int r = 0;
	for(int target=(1<<30);target>=2;target/=2){
		int low=0, high=n-1;
		while(1){
			while(low<n&&used[low]) ++low;
			while(high>=0&&used[high]) --high;
			if(low>=high) break;
			long long sum = a[low]+a[high];
			if(sum==target){
				r++;
				used[low] = used[high] = 1;
			}else if(sum<target){
				low++;
			}else{
				high--;
			}
		}
	}
	cout<<r<<endl;
	return 0;
}

