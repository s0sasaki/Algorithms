class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0||obstacleGrid[0].size()==0) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1) return 0;
        int a[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) a[i][j]=1;
                else if(i==0) a[i][j]=(!obstacleGrid[i][j-1])*a[i][j-1];
                else if(j==0) a[i][j]=(!obstacleGrid[i-1][j])*a[i-1][j];
                else a[i][j] = (!obstacleGrid[i][j-1])*a[i][j-1]+(!obstacleGrid[i-1][j])*a[i-1][j];
            }
        }
        return a[m-1][n-1];
    }
};