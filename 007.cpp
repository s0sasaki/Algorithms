class Solution {
public:
    int reverse(int x) {
        int residual = x;
        int y = 0;
        if (x>=0){
            while (residual != 0){
                if (y > INT_MAX/10 ) return 0;
                y *= 10;
                if (y > INT_MAX - residual%10) return 0;
                y += residual % 10;
                residual /= 10;
            }
        }else{
            while (residual != 0){
                if (y < INT_MIN/10) return 0;
                y *= 10;
                if (y < INT_MIN - residual%10) return 0;
                y += residual % 10;
                residual /= 10;
            }
        }
        return y;
    }
};