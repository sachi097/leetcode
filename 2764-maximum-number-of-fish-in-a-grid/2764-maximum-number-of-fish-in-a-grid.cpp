class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(i<0 || i >= m || j<0 || j >= n || grid[i][j] == -1 || grid[i][j] == 0){
            return 0;
        }

        int curSum = grid[i][j], nextI, nextJ;
        grid[i][j] = -1;
        for(int k=0; k<4; k++){
            nextI = i + dir[k][0];
            nextJ = j + dir[k][1];

            curSum += dfs(nextI, nextJ, m, n, grid);
        }

        return curSum;

    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maximum = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0){
                    maximum = max(maximum, dfs(i, j, m, n, grid));
                }
            }
        }
        return maximum;
    }
};