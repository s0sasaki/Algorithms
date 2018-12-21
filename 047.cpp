class Solution {
public:
    void rec(vector<int>nums, int i, vector<vector<int>> &r){
        if(i==nums.size()-1){
            r.push_back(nums);
            return;
        }
        vector<int> tmp;
        for(int k=i; k<nums.size(); k++){
            bool flag = true;
            for(int j=0;j<tmp.size();j++){
                if(nums[k]==tmp[j]){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            tmp.push_back(nums[k]);
            swap(nums[i], nums[k]);
            rec(nums, i+1, r);
            swap(nums[i], nums[k]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> r;
        if(nums.size()==0) return r;
        sort(nums.begin(), nums.end());
        rec(nums, 0, r);
        return r;
    }
};