class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1, score = 0;
        while(left<=right){
            if(tokens[left] <= power){
                score++;
                power -= tokens[left];
                left++;
            }
            else if(score > 0){
                power += tokens[right];
                right--;
                score--;
            }
            else{
                break;
            }
        }
        return score;
    }
};
