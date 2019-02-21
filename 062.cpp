class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0) return 0;
        //long long r = 1;
        //for(int i=m;i<=m+n-2;i++) r *= i;
        //for(int i=1;i<=n-1;i++) r /= i;
        //return (int)r;
        int a[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0) a[i][j] = 1;
                else a[i][j] = a[i-1][j]+a[i][j-1];
            }
        }
        return a[m-1][n-1];
    }
};