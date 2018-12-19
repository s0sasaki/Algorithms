class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;;i++){
            if(i==nums.size()) return i;
            if(nums[i]>=target) return i;
        }
    }
};