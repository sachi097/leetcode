class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0, countOpenParentheses = 0, countCloseParentheses = 0;
        for(auto i=0; i<s.size(); i++){
            if(s[i] == '('){
                countOpenParentheses++;
            }
            else if(s[i] == ')'){
                maxi = max(maxi, countOpenParentheses);
                countOpenParentheses--;
            }
        }
        return maxi;
    }
};