class Solution {
public:

    int dp[1001][1001];

    int findLCS(int i, int j, string &text1, string &text2){
        if(i == 0 || j == 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(text1[i-1] == text2[j-1]){
            dp[i][j] = 1 + findLCS(i-1, j-1, text1, text2);
        }
        else{
            dp[i][j] = max(findLCS(i-1, j, text1, text2), findLCS(i, j-1, text1, text2));
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        // bottom - up 
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // for(auto i=1; i<=m; i++){
        //     for(auto j=1; j<=n; j++){
        //         if(text1[i-1] == text2[j-1]){
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[m][n];

        // top - down
        memset(dp, -1, sizeof(dp));
        return findLCS(m, n, text1, text2);
    }
};