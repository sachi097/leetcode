class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int digit = 0, n = x;
        while(n > 0){
            digit += n % 10;
            n /= 10;
        }
        return x % digit == 0 ? digit :  -1;
    }
};