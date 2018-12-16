class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        string t="";
        int max=0;
        for(int i=0;i<s.size();i++){
            for(int j=i+max;j<s.size();j++){
                for(int k=0;k<=(j-i)/2;k++){
                    if(s[i+k]!=s[j-k]) break;
                    if((i+k==j-k||i+k==j-k-1) && (j-i+1>max)){
                        max = j-i+1;
                        t = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return t;
    }
};