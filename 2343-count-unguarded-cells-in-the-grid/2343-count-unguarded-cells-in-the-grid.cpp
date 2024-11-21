class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int i, int j, int m, int n, vector<vector<int>> &grid, int direction){
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j] != 2 && grid[i][j] != 1){
            dfs(i + dir[direction][0], j + dir[direction][1], m, n, grid, direction);
            grid[i][j] = -1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int i, j;

        for(auto k=0; k<guards.size(); k++){
            i=guards[k][0];
            j=guards[k][1];
            grid[i][j] = 1; //gurad;
        }

        for(auto k=0; k<walls.size(); k++){
            i=walls[k][0];
            j=walls[k][1];
            grid[i][j] = 2; //wall;
        }

        for(i=0; i<m; i++){
            for(j=0;j<n;j++){
                if(grid[i][j] == 1){
                    for(auto k=0; k<4; k++){
                        int nextI = i + dir[k][0];
                        int nextJ = j + dir[k][1];
                        dfs(nextI, nextJ, m, n, grid, k);
                    }
                }
            }
        }
        
        int count = 0;
        for(i=0; i<m; i++){
            for(j=0;j<n;j++){
                if(grid[i][j] == 0){
                    count++;
                }
            }
        }

        return count;
    }
};