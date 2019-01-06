#include<iostream>
#include<algorithm>
#include<cfloat>
using namespace std;
int main(){
	int n;
	cin>>n;
	double p[n], q[n+1];
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n+1;i++) cin>>q[i];

	double dp[n+1][n+1];
	double psum[n][n];
	double qsum[n+1][n+1];
	for(int i=0;i<n+1;i++) dp[i][i] = q[i];
	for(int i=0;i<n;i++) {
		psum[i][i] = p[i];
		for(int j=i+1;j<n;j++){
			psum[i][j] = psum[i][j-1]+p[j];
		}
	}
	for(int i=0;i<n+1;i++) {
		qsum[i][i] = q[i];
		for(int j=i+1;j<n+1;j++){
			qsum[i][j] = qsum[i][j-1]+q[j];
		}
	}

	for(int i=1;i<n+1;i++){
		for(int j=0;j+i<n+1;j++){
			dp[j][j+i] = DBL_MAX;
			for(int k=0;k<i;k++){
				double tmp; 
				tmp = dp[j][j+k]+dp[j+k+1][j+i]; //pick 2 subtrees
				tmp += psum[j][j+i-1]+qsum[j][j+i]; //increment the depth
				dp[j][j+i] = min(dp[j][j+i], tmp);
			}
		}
	}
	cout<<dp[0][n]<<endl;

	return 0;
}
