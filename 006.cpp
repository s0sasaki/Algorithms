class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2) return s;
        string t;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.size();j++){
                if(j%(2*numRows-2)==i||j%(2*numRows-2)==2*numRows-2-i)
                    t.push_back(s[j]);
            }
        }
        return t;
    }
};