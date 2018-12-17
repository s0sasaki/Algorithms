class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return vector<string>{};
        vector<string> r = vector<string>{""};
        vector<string> data{" ","*","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i=0;i<digits.size();i++){
            vector<string> old_r = r;
            r = vector<string>{};
            for(int j=0;j<old_r.size();j++){
                for(int k=0; k<data[digits[i]-'0'].size();k++){
                    r.push_back(old_r[j] + data[digits[i]-'0'][k]);
                }
            }
        }
        return r;
    }
};