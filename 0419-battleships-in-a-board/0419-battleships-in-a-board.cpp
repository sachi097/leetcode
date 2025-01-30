class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid){
        if(i<0 || i >= m || j<0 || j >= n || grid[i][j] == '.'){
            return;
        }

        int nextI, nextJ;
        grid[i][j] = '.';
        for(int k=0; k<4; k++){
            nextI = i + dir[k][0];
            nextJ = j + dir[k][1];

            dfs(nextI, nextJ, m, n, grid);
        }

    }

    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'X'){
                    ans++;
                    dfs(i, j, m, n, board);
                }
            }
        }
        return ans;
    }
};