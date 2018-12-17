class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> r{};
        if(nums.size()<3) return r;
        sort(nums.begin(),nums.end());
        int a=nums[0]+1,b=nums[1]+1,k;
        for(int i=0;i<nums.size()-2;i++){
            k=nums.size()-1;
            if(nums[i]==a) continue;
            a=nums[i];
            b=nums[i+1]+1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==b) continue;
                b=nums[j];
                for(;k>j;k--){
                    if(nums[i]+nums[j]+nums[k]==0){ 
                        r.push_back(vector<int>{nums[i],nums[j],nums[k--]});
                        break;
                    }
                    else if(nums[i]+nums[j]+nums[k]<0)
                        break;
                }
            }
        }
        return  r;
    }
};
