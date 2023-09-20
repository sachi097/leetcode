class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int i, int j, int rows, int cols){
        if(i<0 || j<0 || i>=rows || j>=cols || !grid[i][j] || grid[i][j] == 2) return false;
        return true;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols, int count){
        if(isSafe(grid, i, j, rows, cols)){
            grid[i][j] = 2;
            static int rowNbr[] = {-1, 0, 1, 0};
            static int colNbr[] = {-0, -1, 0, 1};
            count = 1;
            for(auto k=0; k<4; k++){
                count = count + dfs(grid, i + rowNbr[k], j + colNbr[k], rows, cols, 0);
            }
        } 
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        for(auto i=0; i<rows; i++){
            for(auto j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(grid, i, j, rows, cols, 0));
                }
            }
        }
        return maxArea;
    }
};