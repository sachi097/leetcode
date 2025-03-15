class Trie{
    boolean isEnd;
    Trie[] child;

    Trie(){
        isEnd = false;
        child = new Trie[26];
    }
}

class Solution {

    public boolean search(Trie root, String searchWord, int idx, int[] dp){
        if(idx == searchWord.length()){
            return true;
        }

        if(dp[idx] != -1){
            return dp[idx] == 1;
        }

        Trie crawler = root;
        for(int i=idx; i<searchWord.length(); i++){
            int index = searchWord.charAt(i) - 'a';
            if(crawler.child[index] == null){
                dp[idx] = 0;
                return false;
            }

            crawler = crawler.child[index];

            if(crawler.isEnd && search(root, searchWord, i + 1, dp)){
                dp[idx] = 1;
                return true;
            }
        }

        dp[idx] = 0;
        return false;
    }

    public void insert(Trie root, String s){
        for(char ch: s.toCharArray()){
            int index = ch - 'a';
            if(root.child[index] == null){
                root.child[index] = new Trie();
            }
            root = root.child[index];
        }
        root.isEnd = true;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        Trie root = new Trie();

        for(String str: wordDict){
            insert(root, str);
        }

        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);

        return search(root, s, 0, dp);
    }
}