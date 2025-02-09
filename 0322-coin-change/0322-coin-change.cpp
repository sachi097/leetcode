class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(auto i=0; i<coins.size(); i++){
            for(auto j=coins[i]; j<=amount; j++){
                dp[j] = min(dp[j], 1+dp[j-coins[i]]);
            }
        }
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};