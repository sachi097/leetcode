class Solution {
public:

    bool checkVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
       int left = 0, right = k, maxVowelLength = INT_MIN, vowelLength = 0;
       for(auto m = 0; m < k; m++){
           if(checkVowel(s[m])){
               vowelLength++;
           }
       }
       maxVowelLength = max(maxVowelLength, vowelLength);
       while(right < s.length()){
           if(checkVowel(s[left])){
               vowelLength--;
           }
           if(checkVowel(s[right])){
               vowelLength++;
           }
           maxVowelLength = max(maxVowelLength, vowelLength);
           left++;
           right++;
       }
       return maxVowelLength;
    }
};