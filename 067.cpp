class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int tmp, tmp_a, tmp_b;
        string r = "";
        int i=a.size()-1;
        int j=b.size()-1;
        while(i>=0||j>=0||c>0){
            if(i>=0) tmp_a = a[i]-'0'; else tmp_a = 0;
            if(j>=0) tmp_b = b[j]-'0'; else tmp_b = 0;
            tmp = tmp_a+tmp_b+c;
            r.insert(r.begin(), tmp%2+'0');
            c = tmp/2;
            i--;j--;
        }
        return r;
    }
};