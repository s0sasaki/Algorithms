class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int i=0;
        int j=nums.size()/2;
        int mid;
        while(i<j){
            if(nums[i]<=target&&target<=nums[j]){
                mid = (i+j)/2;
                if(nums[mid]<target) i=mid+1;
                else j=mid;
            }else if(nums[i]<nums[j]&&target<=nums[i]){
                if(nums[0]<=target){
                    j=i;
                    i=0;
                }else{
                    i=j;
                    j=nums.size()-1;
                }
            }else if(nums[i]<nums[j]&&target>=nums[j]){
                i=j;
                j=nums.size()-1;
            }else if(nums[j]<=target&&target<=nums[i]){
                if(nums[0]<=target){
                    j=i;
                    i=0;
                }else{
                    i=j;
                    j=nums.size()-1;
                }
            }else if(nums[i]>nums[j]&&nums[i]<=target){
                mid = (i+j)/2;
                if(nums[mid]<=nums[j]) j=mid-1;
                else if(nums[mid]<target) i=mid+1;
                else j=mid;
            }else if(nums[i]>nums[j]&&target<=nums[j]){
                mid = (i+j)/2;
                if(nums[i]<=nums[mid]) i=mid+1;
                else if(nums[mid]<target) i=mid+1;
                else j=mid;
            }
        }
        if(nums[i]!=target) return -1;
        return i;
    }
};