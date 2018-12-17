class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        int i;
        i = num%10;
        if(i<4) for(int j=0;j<i;j++) s = "I"+s;
        else if(i==4) s = "IV"+s;
        else if(i<9) {for(int j=0;j<i-5;j++) s ="I"+s; s ="V"+s;}
        else if(i==9) s ="IX"+s;
        i = (num/10)%10;
        if(i<4) for(int j=0;j<i;j++) s ="X"+s;
        else if(i==4) s ="XL"+s;
        else if(i<9) {for(int j=0;j<i-5;j++) s ="X"+s; s ="L"+s;}
        else if(i==9) s ="XC"+s;
        i = (num/100)%10;
        if(i<4) for(int j=0;j<i;j++) s ="C"+s;
        else if(i==4) s ="CD"+s;
        else if(i<9) {for(int j=0;j<i-5;j++) s ="C"+s; s ="D"+s;}
        else if(i==9) s ="CM"+s;
        i = num/1000;
        if(i<4) for(int j=0;j<i;j++) s ="M"+s;
        return s;
    }
};