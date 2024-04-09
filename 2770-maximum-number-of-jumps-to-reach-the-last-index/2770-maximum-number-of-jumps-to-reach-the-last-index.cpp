class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        vector<vector<int>> dp(n , vector(n, 0));
        for(int j=1; j<n; j++){
            dp[0][j] = abs(nums[j] - nums[0]) <= target ? 1 : 0;
            sum += dp[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=i; j<n; j++){
                if(j==i){
                    dp[i][i] = dp[i-1][j];
                }
                else{
                    if(dp[i][i] && abs(nums[j] - nums[i]) <= target){
                        dp[i][j] = max(1 + dp[i][i], dp[i-1][j]);
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[n-1][n-1] == 0 ? -1 : dp[n-1][n-1];
    }
};