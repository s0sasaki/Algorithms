class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i=0,j=0,a=0;
        int inci=0,incj=1;
        int top=-1,right=n,bottom=n,left=-1;
        vector<vector<int>> r(n,vector<int>(n,0));
        while(left<j&&j<right&&top<i&&i<bottom){
            r[i][j] = ++a;
            if(incj>0&&j==right-1){
                inci=1; incj=0; top++;
            }else if(inci>0&&i==bottom-1){
                inci=0; incj=-1; right--;
            }else if(incj<0&&j==left+1){
                inci=-1; incj=0; bottom--;
            }else if(inci<0&&i==top+1){
                inci=0; incj=1; left++;
            }
            i += inci;
            j += incj;
        }
        return r;
    }
};