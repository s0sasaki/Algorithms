class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        int m = matrix.size();
        if(m==0) return r;
        int n = matrix[0].size();
        if(n==0) return r;
        int top=-1,right=n,bottom=m,left=-1;
        int i=0,j=0,incj=1,inci=0;
        while(top<i&&i<bottom&&left<j&&j<right){
            r.push_back(matrix[i][j]);
            if(j==right-1&&incj==1){
                inci = 1;
                incj = 0;
                top += 1;
            }else if(i==bottom-1&&inci==1){
                inci = 0;
                incj = -1;
                right += -1;
            }else if(j==left+1&&incj==-1){
                inci = -1;
                incj = 0;
                bottom += -1;
            }else if(i==top+1&&inci==-1){
                inci = 0;
                incj = 1;
                left += 1;
            }
            i += inci;
            j += incj;
        }
        return r;
    }
};