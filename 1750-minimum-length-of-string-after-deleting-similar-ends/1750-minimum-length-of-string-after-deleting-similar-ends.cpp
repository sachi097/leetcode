class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right){
            while(left < n - 1 && s[left] == s[left+1])
                left++;
            while(right > 0 && s[right] == s[right-1])
                right--;
            if(s[left] != s[right]){
                while(left > 0 && s[left] == s[left-1])
                    left--;   
                while(right < n - 1 && s[right] == s[right+1])
                    right++;
                return right - left + 1;
            }
            else{
                left++;
                right--;
            }
        }
        dfjkhfjkhgfghfj
        return right - left == 0 ? 1 : 0;
    }
};
