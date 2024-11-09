class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    int dp[101][101];

    int solve(int i, int j, vector<vector<int>> &grid, int &m, int &n){

        if(i==m-1 && j==n-1 && grid[i][j] == 1){
            return 0;
        }
        
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        dp[i][j] = 0;

        for(auto k = 0; k < 2; k++){
            int nextI = i + dir[k][0];
            int nextJ = j + dir[k][1];
            if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && grid[nextI][nextJ] != 1){
                grid[i][j] = 1; // do
                dp[i][j] += solve(nextI, nextJ, grid, m, n); // explore
                grid[i][j] = 0; // undo
            }
        }

        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int result = 0;
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solve(0, 0, obstacleGrid, m, n);
    }
};