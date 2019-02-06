class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=0;
        bool flag = false;
        for(int j=0;j<s.size();j++){
            if(s[j]!=' ') {
                if(flag){
                    i=0;
                    flag=false;
                }
                i++;
            }
            else flag=true;
        }
        return i;
    }
};