class Solution {
public:

    struct TrieNode{
        bool isEnd;
        TrieNode* child[27];
    };

    void insertNode(TrieNode* crawler, string word){
        bool parent = false;
        int i = 0;
        for(auto &ch: word){
            int index = (ch == '/') ? 26 : ch - 'a';
            if(!crawler->child[index]){
                crawler->child[index] = new TrieNode();
            }
            else if(crawler->child[index]->isEnd){
                if(i<word.size() && word[i+1] == '/')
                    return;
            }
            i++;
            crawler = crawler->child[index];
        }
        crawler->isEnd = true;
    }

    void search(TrieNode* crawler, string currentWord, vector<string> &result){
        if(crawler->isEnd){
            result.push_back(currentWord);
        }
        for(int i=0; i<27; i++){
            if(crawler->child[i]){
                char ch;
                if(i == 26){
                    ch = '/';
                }
                else{
                    ch = 'a' + i;
                }
                search(crawler->child[i], currentWord + ch, result);
            }
        }
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode* trie = new TrieNode();
        sort(folder.begin(), folder.end());
        for(auto &str: folder){
            insertNode(trie, str);
        }

        vector<string> result;
        search(trie, "", result);

        return result;
      
    }

};