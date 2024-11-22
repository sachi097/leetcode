class Solution {
public:
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int m, n;

    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0){
            return 0;
        }

        int result = 0;
        int tmp = grid[i][j];
        grid[i][j] = 0; // do

        for(int k=0; k<4; k++){ // explore
            int nextI = i + dir[k][0];
            int nextJ = j + dir[k][1];
            result = max(result, dfs(nextI, nextJ, grid));
        }

        grid[i][j] = tmp; // undo
        return grid[i][j] + result;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, dfs(i, j, grid));
                }
            }
        }

        return maxGold;
    }
};