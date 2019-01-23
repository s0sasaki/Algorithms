class Solution {
public:
    double myPow(double x, int n) {
        if(x==0.0) return 0.0;
        if(x==1.0) return 1.0;
        if(n==0) return 1.0;
        double rr = n>0? x:1/x;
        double xx = n>0? x:1/x;
        int ii =  n>0? 1:-1;
        int inc = n>0? 1:-1;
        double xx0 = 1.0;
        int bignum = 10000000;
        if(n>bignum||n<-bignum){
            for(int i=0; i<bignum; i++){
                xx0 *= xx;
            }
        }
        while(ii!=n){
            if(inc*ii<inc*(n/2)){
                rr *= rr;
                ii = 2*ii;
            }else if(inc*ii < inc*(n - inc*bignum)){
                rr *= xx0;
                ii += inc*bignum;
            }else{
                rr *= xx;
                ii += inc;
            }
            if(rr==INFINITY||rr==-INFINITY) {
                if(x<0&&n%2==1) return -INFINITY;
                else INFINITY;
            }else if(rr==0.0) return 0.0;
        }
        return rr;
    }
};