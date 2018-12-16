class Solution {
public:
    bool isPalindrome(int x) {
        int r = x;
        int y = 0;
        if(x<0) return false;
        while(r!=0){
            y = 10*y + r%10;
            r /= 10;
        }
        if (y==x) return true;
        else return false;
    }
};