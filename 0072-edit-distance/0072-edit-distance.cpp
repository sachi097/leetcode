class Solution {
public:
    
    int dp[501][501];
    
    int diff(char a, char b){
        return a == b ? 0 : 1;
    }
    
    int findDis(int i, int j, string word1, string word2){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = min(findDis(i-1, j-1, word1, word2) + diff(word1[i-1], word2[j-1]), min(1+findDis(i, j-1, word1, word2),1+findDis(i-1, j, word1, word2)));
        return dp[i][j];
    }
    
    
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();   
        // bottom-up
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // for(auto i=0; i<=m; i++){
        //     dp[i][0] = i;
        // }
        // for(auto j=0; j<=n; j++){
        //     dp[0][j] = j;
        // }
        // for(auto i=1; i<=m; i++){
        //     for(auto j=1; j<=n; j++){
        //         dp[i][j] = min(dp[i-1][j-1] + diff(word1[i-1], word2[j-1]),min(1+dp[i][j-1],1+dp[i-1][j]));
        //     }
        // }
        // return dp[m][n];
        
        // top-down
        memset(dp, -1, sizeof(dp));
        return findDis(m, n, word1, word2);
        
    }
};