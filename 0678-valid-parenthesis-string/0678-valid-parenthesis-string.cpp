class Solution {
public:
    bool checkValidString(string s) {
        int openParen = 0, closeParen = 0, n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '*'){
                openParen++;
            }
            else{
                openParen--;
            }
            if(s[n-i-1] == ')' || s[n-i-1] == '*'){
                closeParen++;
            }
            else{
                closeParen--;
            }
            if(openParen < 0 || closeParen < 0){
                return false;
            }
        }
        return true;
    }
};