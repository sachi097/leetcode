class Solution {
public:
    int minOperations(string s) {
        int result0 = 0, result1 = 0;
        string t = s;
        if(s[0] == '1'){
            result0++;
        }
        s[0] = '0';
        for(auto i=1; i<s.size(); i++){
            if(s[i] == s[i-1]){
                result0++;
                if(s[i] == '0'){
                    s[i] = '1';
                }
                else{
                    s[i] = '0'; 
                }
            }
        }
        s = t;
        if(s[0] == '0'){
            result1++;
        }
        s[0] = '1';
        for(auto i=1; i<s.size(); i++){
            if(s[i] == s[i-1]){
                result1++;
                if(s[i] == '0'){
                    s[i] = '1';
                }
                else{
                    s[i] = '0'; 
                }
            }
        }
        return min(result0, result1);
    }
};