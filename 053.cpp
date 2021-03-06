class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int max = nums[0];
        int tmp = 0;
        for(int i=0; i<nums.size(); i++){
            tmp += nums[i];
            if(tmp>max) max = tmp;
            if(tmp<0) tmp = 0;
        }
        return max;
    }
};