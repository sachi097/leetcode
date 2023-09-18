class Solution {
public:

    bool checkVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
       int i = 0, j = k, maxVowelLength = INT_MIN, vowelLength = 0;
       for(auto m = 0; m < k; m++){
           if(checkVowel(s[m])){
               vowelLength++;
           }
       }
       maxVowelLength = max(maxVowelLength, vowelLength);
       while(j < s.length()){
           if(checkVowel(s[i])){
               vowelLength--;
           }
           if(checkVowel(s[j])){
               vowelLength++;
           }
           maxVowelLength = max(maxVowelLength, vowelLength);
           i++;
           j++;
       }
       return maxVowelLength;
    }
};