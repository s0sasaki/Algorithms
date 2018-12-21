class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int n = num1.size();
        int m = num2.size();
        int tmp[n+m+1];
        for(int i=0;i<n+m+1;i++) tmp[i] = 0;
        int a, c, p, q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                p = n-i-1;
                q = m-j-1;
                a = (num1[p]-'0')*(num2[q]-'0');
                tmp[i+j] += a%10;
                tmp[i+j+1] += a/10;
            }
        }
        a = 0;
        c = 0;
        for(int i=0;i<n+m+1;i++){
            a = tmp[i]+c;
            tmp[i] = a%10;
            c = a/10;
        }
        string s = "";
        int i=n+m;
        while(tmp[i]==0) i--;
        while(i>=0){
            s.insert(s.end(), '0'+tmp[i]);
            i--;
        }
        return s;
    }
};