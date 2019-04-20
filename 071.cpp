class Solution {
public:
    string simplifyPath(string path) {
        if(path.size()==0) return "/";
        vector<string> r;
        string s="/",t;
        int i=0,j=0;
        while(path[i]=='/') i++;

        while(1){
            
            while(path[j]=='/'&&j<path.size()) j++;
            if(j==path.size()) break;
            i=j;
            while(path[j]!='/'&&j<path.size()) j++;
            
            t=path.substr(i, j-i);
            if(t==".") ;
            else if(t==".."&&r.size()>0) r.pop_back();
            else if(t==".."&&r.size()==0) ;
            else if(j<=i) ;
            else r.push_back(t);

        }

        for(int i=0;i<r.size();i++){
            s += r[i];
            if(i!=r.size()-1) s+= "/";
        }
        return s;
    }
};