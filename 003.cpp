class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2) return s.size();
        int max = 0;
        int i = 0;
        for(int j=1;j<s.size();j++){
            for(int k=i;k<j;k++){
                if(s[k]==s[j]){
                    i=k+1;
                    break;
                }
            }
            max = max>(j-i+1)? max:(j-i+1);
        }
        return max;
    }
};