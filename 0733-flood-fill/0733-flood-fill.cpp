class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j, int initialPixel, int color){
        grid[i][j] = color;
        static int rowNbr[] = {-1, 0, 1, 0};
        static int colNbr[] = {-0, -1, 0, 1};
        for(int k=0; k<4; k++){
            int nextI = i + rowNbr[k];
            int nextJ = j + colNbr[k];
            if(nextI>=0 && nextJ>=0 && nextI<grid.size() && nextJ<grid[0].size() && grid[nextI][nextJ] == initialPixel && grid[nextI][nextJ] != color){
                dfs(grid, nextI, nextJ, initialPixel, color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};