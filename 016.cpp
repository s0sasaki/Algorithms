class Solution {
public:
    int abs(int a){
        return a>0? a:-a;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        int r = nums[0]+nums[1]+nums[2];
        int min = abs(target-r);
        sort(nums.begin(), nums.end());
        int tmp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=nums.size()-1;k>j;k--){
                    tmp = nums[i]+nums[j]+nums[k];
                    if(tmp<target-min) break;
                    if(abs(target-tmp)<min){
                        r = tmp;
                        min = abs(target-tmp);
                    }
                }
            }
        }
        return r;
    }
};