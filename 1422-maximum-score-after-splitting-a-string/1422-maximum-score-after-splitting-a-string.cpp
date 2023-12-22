class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, lEnd = 0, rStart = 1, result = 0;
        if(s[0] == '0'){
            zeros++;
        }
        while(rStart < s.size()){
            if(s[rStart] == '1'){
                ones++;
            }
            rStart++;
        }
        result = zeros + ones;
        lEnd++;
        while(lEnd < s.size() - 1){
            if(s[lEnd] == '0'){
                zeros++;
            }
            else{
                ones--;
            }
            result = max(result, zeros + ones);
            lEnd++;
        }
        return result;
    }
};