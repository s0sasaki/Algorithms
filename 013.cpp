class Solution {
public:
    int romanToInt(string s) {
        int r = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='I') {
                if(i<s.size()-1 && (s[i+1]=='V'||s[i+1]=='X')) {
                    r -= 1;
                }else{
                    r += 1;
                }
            }
            if(s[i]=='X') {
                if(i<s.size()-1 && (s[i+1]=='L'||s[i+1]=='C')) {
                    r -= 10;
                }else{
                    r += 10;
                }
            }
            if(s[i]=='C')  {
                if(i<s.size()-1 && (s[i+1]=='D'||s[i+1]=='M')) {
                    r -= 100;
                }else{
                    r += 100;
                }
            }
            if(s[i]=='V') r += 5;
            if(s[i]=='L') r += 50;
            if(s[i]=='D') r += 500;
            if(s[i]=='M') r += 1000;
        }
        return r;
    }
};