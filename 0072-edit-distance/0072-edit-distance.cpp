class Solution {
public:
    int diff(char a, char b){
        return a == b ? 0 : 1;
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto i=0; i<=m; i++){
            dp[i][0] = i;
        }
        for(auto j=0; j<=n; j++){
            dp[0][j] = j;
        }
        for(auto i=1; i<=m; i++){
            for(auto j=1; j<=n; j++){
                dp[i][j] = min(dp[i-1][j-1] + diff(word1[i-1], word2[j-1]),min(1+dp[i][j-1],1+dp[i-1][j]));
            }
        }
        return dp[m][n];
    }
};