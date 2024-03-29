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
    
    void searchCommondPrefix(trieNode* crawler, string &res){
        if(crawler->isEndofWord)
            return;
        int count = 0, id;
        for(auto i=0; i<26; i++){
            if(crawler->child[i]){
                count++;
                id = i;
            }
        }
        if(count != 1){
            return;
        }
        res += (char) ('a' + id);
        searchCommondPrefix(crawler->child[id], res);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        trieNode *trie = new trieNode(), *crawler = trie;
        string res;
        for(auto str: strs){
            insertWord(crawler, str);
        }
        searchCommondPrefix(crawler, res);
        return res;
    }
};