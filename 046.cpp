class Solution {
public:
    void rec(vector<int> nums, vector<int> s, vector<vector<int>> &r){
        if(nums.size()==0){
            r.push_back(s);
            return;
        }
        for(int i=0;i<nums.size();i++){
            vector<int> p=nums;
            p.erase(p.begin()+i);
            s.push_back(nums[i]);
            rec(p, s, r);
            s.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> r;
        vector<int> s;
        rec(nums, s, r);
        return r;
    }
};