class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        unordered_set<char> hashSetWord1;
        unordered_set<char> hashSetWord2;
        vector<int> countWord1(26, 0), countWord2(26, 0);
        for(auto i=0; i < word1.size(); i++){
            hashSetWord1.insert(word1[i]);
            countWord1[word1[i] - 'a']++;
        }
        for(auto i=0; i < word2.size(); i++){
            hashSetWord2.insert(word2[i]);
            countWord2[word2[i] - 'a']++;
        }
        sort(countWord1.begin(), countWord1.end());
        sort(countWord2.begin(), countWord2.end());
        return (hashSetWord1 == hashSetWord2 && countWord1 == countWord2);
    }
};