class Solution {
public:
    
    struct trieNode{
        bool isEndofWord;
        trieNode* child[26];
    };

    void insertWord(trieNode* crawler, string word){
        for(auto ch: word){
            int idx = ch - 'a';
            if(!crawler->child[idx])
                crawler->child[idx] = new trieNode();
            crawler = crawler->child[idx];
        }
        crawler->isEndofWord = true;
    }

    vector<string> search(trieNode *trie, string prefix) {
        vector<string> result;
        for (char &c : prefix) {
            int idx = c - 'a';
            if (!trie->child[idx])
                return {};
            trie = trie->child[idx];
        }
        findSuggestions(prefix, trie, result);
        return result;
    }
    
    void findSuggestions(string currentWord, trieNode* crawler, vector<string>& result){
        if(result.size() == 3)
            return;
        if(crawler->isEndofWord)
            result.push_back(currentWord);
        for(auto idx=0; idx<26; idx++){
            if(crawler->child[idx]){
                findSuggestions(currentWord + (char) ('a' + idx), crawler->child[idx], result);   
            }
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        trieNode* trie = new trieNode();
        trieNode* crawler = trie;
        for(auto i=0; i<products.size(); i++){
            insertWord(trie, products[i]);
        }
        string prefix;
        for(auto ch: searchWord){
            prefix += ch;
            ans.push_back(search(trie, prefix));
        }
        return ans;
    }
};