class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> r;
        map<string, int> dict;
        int a=0;
        for(int i=0;i<strs.size();i++){
            string b=strs[i];
            sort(b.begin(), b.end());
            if(dict.find(b)==dict.end()){
                r.push_back(vector<string>{strs[i]});
                dict[b] = a++;
            }else{
                r[dict[b]].push_back(strs[i]);
            }
        }
        return r;
    }
};