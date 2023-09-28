class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        unordered_map<char, bool> hashMapWord1;
        unordered_map<char, bool> hashMapWord2;
        vector<int> countWord1(26, 0), countWord2(26, 0);
        for(auto i=0; i < word1.size(); i++){
            hashMapWord1.insert({word1[i], true});
            countWord1[word1[i] - 'a']++;
        }
        for(auto i=0; i < word2.size(); i++){
            if(!hashMapWord1.count(word2[i]))
                return false;
        }
        for(auto i=0; i < word2.size(); i++){
            hashMapWord2.insert({word2[i], true});
            countWord2[word2[i] - 'a']++;
        }
        for(auto i=0; i < word1.size(); i++){
            if(!hashMapWord2.count(word1[i]))
                return false;
        }
        sort(countWord1.begin(), countWord1.end());
        sort(countWord2.begin(), countWord2.end());
        return countWord1 == countWord2 ? true : false;
    }
};