class Solution {
public:
    void rec(string s, int open, int close, vector<string> &r){
        if(open==0&&close==0){
            r.push_back(s);
        }else if(open==0){
            rec(s+")", open, close-1, r);
        }else if(open==close){
            rec(s+"(", open-1, close, r);
        }else if(close>open){
            rec(s+"(", open-1, close,r);
            rec(s+")", open, close-1,r);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        rec("", n, n, r);
        return r;
    }
};