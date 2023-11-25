class Trie {
public:
    struct trieNode{
        bool isEndofWord;
        trieNode* child[26];
    };

    trieNode* trie;

    Trie() {
        trie = new trieNode();
    }
    
    void insert(string word) {
        trieNode* crawler = trie;
        for(auto ch: word){
            int idx = ch - 'a';
            if(crawler->child[idx] == NULL){
                crawler->child[idx] = new trieNode();
            }
            crawler = crawler->child[idx];
        }
        crawler->isEndofWord = true;
    }
    
    bool search(string word) {
        trieNode* crawler = trie;
        for(auto ch: word){
            int idx = ch - 'a';
            if(crawler->child[idx] == NULL){
                return false;
            }
            crawler = crawler->child[idx];
        }
        return crawler->isEndofWord;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = trie;
        for(auto ch: prefix){
            int idx = ch - 'a';
            if(crawler->child[idx] == NULL){
                return false;
            }
            crawler = crawler->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */