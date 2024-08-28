class Solution {
public:
    
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool dfs(vector<vector<int>>& grid2, vector<vector<int>>& grid1, int m, int n, int i, int j){
        bool valid = true;
        if(i >= 0 && j >= 0 && i < m && j < n && grid2[i][j] == 1){
            valid = grid2[i][j] == grid1[i][j];
            grid2[i][j] = 2;
            for(auto l=0; l<4; l++){
                valid &= dfs(grid2, grid1, m, n, i + dir[l][0], j + dir[l][1]);
            }
        }
        return valid;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), ans = 0;
        for(auto i=0; i<m; i++){
            for(auto j=0; j<n; j++){
                if(grid2[i][j] == 1){
                    if(dfs(grid2, grid1, m, n, i, j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};