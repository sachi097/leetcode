class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charMap;
        for(auto ch: chars){
            charMap[ch]++;
        }
        string ans;
        for(auto word: words){
            bool add = true;
            unordered_map<char, int> wordCharMap = charMap;
            for(auto ch: word){
                if(charMap.find(ch) == charMap.end() || wordCharMap[ch] == 0){
                    add = false;
                    break;
                }
                wordCharMap[ch]--;
            }
            if(add){
                ans += word;
            }
        }
        return ans.size();
    }
};