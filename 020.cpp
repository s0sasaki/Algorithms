class Solution {
public:
    bool isValid(string s) {
        vector<char> stack{};
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {stack.emplace_back(s[i]); }
            else if(s[i]=='[') {stack.emplace_back(s[i]); }
            else if(s[i]=='{') {stack.emplace_back(s[i]); }
            else if(s[i]==')'){
                if(stack.size()==0||stack.back()!='(') return false;
                else stack.pop_back();
            }
            else if(s[i]=='}'){
                if(stack.size()==0||stack.back()!='{') return false;
                else stack.pop_back();
            }
            else if(s[i]==']'){
                if(stack.size()==0||stack.back()!='[') return false;
                else stack.pop_back();
            }
        }
        if(stack.size()==0) return true;
        else return false;
    }
};