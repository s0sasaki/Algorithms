class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]) break;
        }
        if(i==0){
            sort(nums.begin(), nums.end());
            return;
        }
        i--;
        int v=nums[i];
        for(int j=nums.size()-1;j>0;j--){
            if(nums[j]>v){
                nums[i] = nums[j];
                nums[j] = v;
                break;
            }
        }
        sort(nums.begin()+i+1, nums.end());
        return;        
    }
};