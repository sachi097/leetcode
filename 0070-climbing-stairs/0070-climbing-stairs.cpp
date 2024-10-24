class Solution {
public:
    int stairs(int n, vector<int>&dp){
        if(n==1 || n==2){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = stairs(n-1, dp) + stairs(n-2, dp);

        return dp[n];
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return stairs(n, dp);
    }
};