class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(auto i=0; i<m; i++){
            dp[i][0] = 1;
        }
        for(auto j=0; j<n; j++){
            dp[0][j] = 1;
        }
        for(auto i=1; i<m; i++){
            for(auto j=1; j<n; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};