class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        if(n==0) return 0;
        vector<vector<int>> a(grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) a[i][j]=grid[i][j];
                else if(i==0) a[i][j]=grid[i][j]+a[i][j-1];
                else if(j==0) a[i][j]=grid[i][j]+a[i-1][j];
                else a[i][j] = grid[i][j]+(a[i-1][j]<a[i][j-1]? a[i-1][j]:a[i][j-1]);
            }
        }
        return a[m-1][n-1];
    }
};