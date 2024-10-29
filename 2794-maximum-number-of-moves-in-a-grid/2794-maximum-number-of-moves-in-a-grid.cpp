class Solution {
public:
    int dp[1001][1001];
    vector<vector<int>> dir = {{-1, 1}, {0, 1}, {1, 1}};

    int solve(int i, int j, vector<vector<int>> &grid, int &m, int &n){
        int start = grid[i][j];
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        dp[i][j] = 0;

        for(auto k = 0; k < 3; k++){
            int nextI = i + dir[k][0];
            int nextJ = j + dir[k][1];

            if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && start < grid[nextI][nextJ]){
                dp[i][j] = max(dp[i][j], 1 + solve(nextI, nextJ, grid, m, n));
            }
        }

        return dp[i][j];
    }

    int maxMoves(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size();
        int n = grid[0].size();
        int result = INT_MIN;
        for(auto i=0; i<grid.size(); i++){
            result = max(result, solve(i, 0, grid, m, n));
        }

        return result;
    }
};