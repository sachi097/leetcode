class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0, j = 0, k = 0, m = word1.length(), n = word2.size();
        while(i < m && j < n){
           result += word1[i++];
           result += word2[j++];
        }
        while(i < m){
            result += word1[i++];
        }
        while(j < n){
            result += word2[j++];
        }
        return result;
    }
};