class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxLen = 0;
        vector<int> map(256, -1);
        while(right < s.size()){
            int currChar = s[right];
            if(map[currChar] != -1){
                left = max(left, map[currChar] + 1);
            }

            map[currChar] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};