class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int i = 1;
        while(i<=x/i) i++;
        return i-1;
    }
};