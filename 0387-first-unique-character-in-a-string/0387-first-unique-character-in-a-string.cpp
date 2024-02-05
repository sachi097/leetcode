class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashMap;
        for(auto ch: s){
            hashMap[ch]++;
        }
        for(auto i=0; i<s.size(); i++){
            if(hashMap[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};