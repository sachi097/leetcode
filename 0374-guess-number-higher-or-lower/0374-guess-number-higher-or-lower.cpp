/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int guessed, low=0, high = n;
        while(low <= high){
            guessed = low + (high - low) / 2;
            int result = guess(guessed);
            if(result == 0){
                return guessed;
            }
            else if(result == 1){
                low = guessed + 1;
            }
            else{
                high = guessed - 1;
            }
        }
        return -1;
    }
};