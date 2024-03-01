class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int count = 0;
        for(auto ch: s){
            ans += "0";
            if(ch == '1'){
                count++;
            }
        }
        int i = 0;
        while(count > 1){
            ans[i++] = '1';
            count--;
        }
        ans[s.size() - 1] = '1';
        return ans;
    }
};