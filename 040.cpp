class Solution {
public:
    void rec(vector<int> c, int t, vector<int>&s, vector<vector<int>> &r){
        if(t==0) r.push_back(s);
        if(t<1) return;
        for(int i=0;i<c.size();i++){
            s.push_back(c[i]);
            if(i!=c.size()-1)
                rec(vector<int>(c.begin()+i+1, c.end()), t-c[i], s, r);
            else if(t-c[i]==0)
                r.push_back(s);
            s.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> r, t;
        vector<int> s;
        if(candidates.size()<1) return r;
        sort(candidates.begin(), candidates.end());
        rec(candidates, target, s, r);
        for(int i=0;i<r.size();i++){
            bool flag=true;
            for(int j=0;j<i;j++){
                if(r[i].size()!=r[j].size()) continue;
                int k;
                for(k=0;k<r[i].size();k++)
                    if(r[i][k]!=r[j][k]) break;
                if(k==r[i].size()){
                    flag=false;
                    break;
                }
            }
            if(flag)
                t.push_back(r[i]);
        }
        return t;
    }
};