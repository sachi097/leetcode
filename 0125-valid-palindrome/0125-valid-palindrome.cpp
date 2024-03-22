class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            char leftChar = tolower(s[left]), rightChar = tolower(s[right]);
            while(left < right && (leftChar < 'a' || leftChar > 'z') && (leftChar < '0' || leftChar > '9' )){
                left++;
                leftChar = tolower(s[left]);
            }
            while(right > left && (rightChar < 'a' || rightChar > 'z') && (rightChar < '0' || rightChar > '9' )){
                right--;
                rightChar = tolower(s[right]);
            }
            if(leftChar != rightChar){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};