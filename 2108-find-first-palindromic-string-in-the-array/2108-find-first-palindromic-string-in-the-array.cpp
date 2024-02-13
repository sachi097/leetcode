class Solution {
public:
    bool checkPalindrome(string input){
        bool ans = true;
        int left = 0, right = input.size() - 1;
        while(left < right){
            if(input[left] != input[right])
                return false;
            left++;
            right--;
        }
        return ans;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(auto word: words){
            if(checkPalindrome(word))
                return word;
        }
        return "";
    }
};