class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int i=0;
        int r=0;
        for(;i<str.size();i++){
            if(str[i]==' ') continue;
            if(str[i]=='+') {i++; break;}
            if(str[i]=='-') {sign =-1; i++; break;}
            if(0<=str[i]-'0' && str[i]-'0'<=9) break;
            return 0;
        }
        if(i==str.size()) return 0;
        for(;i<str.size();i++){
            if(0<=str[i]-'0' && str[i]-'0'<=9){
                if(r>INT_MAX/10||10*r>INT_MAX-(str[i]-'0')) return INT_MAX;
                if(r<INT_MIN/10||10*r<INT_MIN+(str[i]-'0')) return INT_MIN;
                r = r*10 + sign*(str[i]-'0');
            }else{
                break;
            }
        }
        return r;
    }
};