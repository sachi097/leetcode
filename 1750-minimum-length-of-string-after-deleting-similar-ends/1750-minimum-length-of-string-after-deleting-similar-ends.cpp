class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1, preStartIndex, postStartIndex;
        while(left < right){
            preStartIndex = left;
            postStartIndex = right;
            while(left < n - 1 && s[left] == s[left+1])
                left++;
            while(right > 0 && s[right] == s[right-1])
                right--;
            if(s[left] != s[right]){
                return postStartIndex - preStartIndex + 1;
            }
            else{
                left++;
                right--;
            }
        }
        return right - left == 0 ? 1 : 0;
    }
};