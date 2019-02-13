class Solution {
public:
    string getPermutation(int n, int k) {
        k -= 1;
        string s;
        int f[n+1],used[n];
        f[0]=1;
        for(int i=0;i<n;i++)f[i+1]=(i+1)*f[i];
        for(int i=0;i<n;i++)used[i]=0;
        for(int i=0;i<n;i++){
            int a = k/f[n-1-i];
            int j=0;
            int t=0;
            while(1){
                if(t==a&&!used[j]) break;
                if(!used[j]) t++;
                j++;
            }
            used[j] = 1;
            s += '1'+j;
            k = k%f[n-1-i];
        }
        return s;
    }
};