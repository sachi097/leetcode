class Solution {
public:
    int takeCharacters(string s, int k) {
        int left=0, right=0, n = s.size();
        unordered_map<char, int> mp;
        for(auto &ch: s){
            mp[ch]++;
        }

        if(mp['a'] < k || mp['b'] < k || mp['c'] < k)
        {
            return -1;
        }

        if(k == 0){
            return 0;
        }

        int windowLen = 0;
        while(right < n){
            mp[s[right]]--;

            while(left <= right && (mp['a'] < k || mp['b'] < k || mp['c'] < k)){
                mp[s[left]]++;
                left++;
            }

            windowLen = max(windowLen, right - left + 1);

            right++;
        }

        return n - windowLen;
    }
};