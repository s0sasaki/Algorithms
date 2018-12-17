class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> r;
        if(nums.size()<4) return r;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int low=j+1,high=nums.size()-1;
                while(low<high){
                    if(nums[i]+nums[j]+nums[low]+nums[high]==target){
                        r.push_back(vector<int>{nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                    }
                    else if(nums[i]+nums[j]+nums[low]+nums[high]<target){
                        low++;
                    }
                    else if(nums[i]+nums[j]+nums[low]+nums[high]>target){
                        high--;
                    }
                    
                }
            }
        }
        
        vector<vector<int>> s;
        for(int i=0;i<r.size();i++){
            bool flag = true;
            for(int j=0;j<i;j++){
                if(r[i][0]==r[j][0]&&
                   r[i][1]==r[j][1]&&
                   r[i][2]==r[j][2]&&
                   r[i][3]==r[j][3]) {
                    flag=false;
                    break;
                }
            }
            if(flag) s.push_back(r[i]);
        }
        
        return s;
    }
};