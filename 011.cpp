class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int h,w;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                h = height[i]<height[j]? height[i]:height[j];
                w = j-i;
                max = max>h*w? max:h*w;
            }
        }
        return max;
    }
};