class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return -1;
        int sign = (dividend<0)^(divisor<0)? -1:1;
        long long d = labs(divisor);
        long long n = labs(dividend);
        long long r = 0;
        long long acc = 0;
        long long tmp_r, tmp_acc;
        while(acc+d<=n){
            tmp_r = 1;
            tmp_acc = d;
            while(acc+(tmp_acc<<1)<=n){
                tmp_r <<=1;
                tmp_acc <<=1;
            }
            r += tmp_r;
            acc += tmp_acc;
        }
        if(sign<0&&r-1>INT_MAX) return INT_MIN;
        if(sign>0&&r>INT_MAX) return INT_MAX;
        return sign==1?(int)r:(int)-r;
    }
};