class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return true;
        int i=0,j=0;
        while(i<=j){
            if(nums.size()-1<=j) return true;
            j = j>i+nums[i]? j:i+nums[i];
            i++;
        }
        return false;
    }
};