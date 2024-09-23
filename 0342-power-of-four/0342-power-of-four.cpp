class Solution {
public:
    bool isPowerOfFour(int n) {
        // for number to be power of 4 it must be power of 2 and its remainder should be 1 on division by 3
        return ( n > 0 && !(n & (n-1)) && (n % 3 == 1));
    }
};