class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1, i = 0 ;
        string res;
        char current_char = chars[0];
        for(i = 1;  i < chars.size(); i++){
            if(current_char != chars[i]){
                res += current_char;
                if(count > 1){
                    res += to_string(count);
                }
                count = 1;
                current_char = chars[i];
            }
            else{
                count++;
            }
        }
        res += chars[i-1];
        if(count > 1){
            res += to_string(count);
        }
        for(i = 0 ; i < res.size(); i++){
            chars[i] = res[i];
        }
        return res.size();
    }
};