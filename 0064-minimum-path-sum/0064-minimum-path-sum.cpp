class Solution {
public:
    // int dp[201][201];
    // vector<vector<int>> dir = {{0, 1}, {1, 0}};

    // int solve(int i, int j, vector<vector<int>> &grid, int &m, int &n){
        
    //     if(i==m-1 && j==n-1){
    //         return dp[i][j] = grid[i][j];
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     dp[i][j] = INT_MAX;

    //     for(auto k = 0; k < 2; k++){
    //         int nextI = i + dir[k][0];
    //         int nextJ = j + dir[k][1];
    //         if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n){
    //             dp[i][j] = min(dp[i][j], grid[i][j] + solve(nextI, nextJ, grid, m, n));
    //         }
    //     }

    //     return dp[i][j];
    // }

    int minPathSum(vector<vector<int>>& grid) {
        // memset(dp, -1, sizeof(dp));
        // int m = grid.size();
        // int n = grid[0].size();
        // solve(0, 0, grid, m, n);
        // return dp[0][0];

        // bottom up
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for(auto i=1; i<m; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(auto j=1; j<n; j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }

        for(auto i=1; i<m; i++){
            for(auto j=1; j<n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }
};