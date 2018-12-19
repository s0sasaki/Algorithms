class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return vector<int>{-1,-1};
        int left=0;
        int right=nums.size()-1;
        int start, end, mid;
        while(left<right){
            mid = (right+left)/2;
            if(nums[mid]<target) left = mid+1;
            else right = mid;
        }
        start = left;
        right=nums.size()-1;
        if(nums[right]==target) end=right;
        else{
            while(left<right){
                mid = (right+left)/2;
                if(nums[mid]<target+1) left = mid+1;
                else right = mid;
            }
            end = right-1;
        }
        if(nums[start]==target&&nums[end]==target) return vector<int>{start, end};
        else return vector<int>{-1,-1};
    }
};