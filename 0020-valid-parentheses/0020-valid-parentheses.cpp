class Solution {
public:
    bool isValid(string s) {
        int i=-1;
        for(auto& ch:s){
            if(ch=='(' || ch=='{' || ch=='[')
                s[++i]=ch;
            else{
                if(i>=0 && ((s[i]=='(' && ch==')') || (s[i]=='{' && ch=='}') || (s[i]=='[' && ch==']'))){
                    i--;
                }
                else{
                    return false;
                }
            }
        }
        return i==-1;
    }
};