class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> countMap;
        for(auto ch: s){
            countMap[ch]++;
        }
        for(auto ch: t){
            countMap[ch]--;
        }
        for(auto item: countMap){
            if(item.second > 0 || item.second < 0){
                return false;
            }
        }
        return true;
    }
};