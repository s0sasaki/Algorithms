class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        string t = "";
        for(int i=1; i<n; i++){
            char c = s[0];
            int count = 0;
            for(int j=0; j<s.size(); j++){
                if(c==s[j]) count++;
                else{
                    t += to_string(count);
                    t += c;
                    c = s[j];
                    count = 1;
                }
            }
            t += to_string(count);
            t += c;
            s = t;
            t = "";
        }
        return s;
    }
};