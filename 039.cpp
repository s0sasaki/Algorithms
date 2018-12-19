class Solution {
public:
    void rec(vector<int> c, int t, vector<int> s, vector<vector<int>> &r){
        if(t==0) r.push_back(s);
        if(t<1) return;
        for(int i=0;i<c.size();i++){
            vector<int> tmp_s(s);
            tmp_s.push_back(c[i]);
            vector<int> tmp_c(c.begin()+i,c.end());
            rec(tmp_c, t-c[i], tmp_s, r);
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> r;
        vector<int> s;
        if(candidates.size()<1) return r;
        sort(candidates.begin(), candidates.end());
        rec(candidates, target, s, r);
        return r;
    }
};