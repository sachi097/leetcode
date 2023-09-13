class Solution {
public:
    bool checkVowel(char x){
        if(x == 'a' || x == 'e' || x == 'i' | x == 'o' || x == 'u') return true;
        return false;
    }

    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(checkVowel(towlower(s[i])) && checkVowel(towlower(s[j]))){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else{
                if(!checkVowel(towlower(s[i]))){
                    i++;
                }
                if(!checkVowel(towlower(s[j]))){
                    j--;
                }
            }
        }
        return s;
    }
};