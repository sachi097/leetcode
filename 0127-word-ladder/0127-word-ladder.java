class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Queue<Pair> q = new ArrayDeque<>();
        Set<String> set = new HashSet<String>();
        q.add(new Pair(beginWord, 1));
        for(int i = 0; i < wordList.size(); i++) {
            set.add(wordList.get(i));
        }
        set.remove(beginWord);
        while(!q.isEmpty()) {
            String word = q.peek().alphabet;
            int step = q.peek().steps;
            q.poll();
            if(word.equals(endWord)) return step;
            for(int i = 0; i < word.length(); i++) {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    char[] charArray = word.toCharArray();
                    charArray[i] = ch;
                    String alphaReplacedWord = new String(charArray); 
                    if(set.contains(alphaReplacedWord) == true) {
                        set.remove(alphaReplacedWord);
                        q.add(new Pair(alphaReplacedWord, step+1));
                    }
                }
            }
        }
        return 0;
    }
}

class Pair {
    String alphabet;
    int steps;
    Pair(String a, int s) {
        this.alphabet = a;
        this.steps = s;
    }
}