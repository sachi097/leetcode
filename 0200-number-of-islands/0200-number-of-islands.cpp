class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<int>> dir{{0, -1},{0, 1},{1, 0},{-1, 0}};
        int numberIslands = 0, m = grid.size(), n = grid[0].size(), size = 0;
        for(auto i=0; i<m; i++){
            for(auto j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    numberIslands++;
                    q.push({i, j});
                    grid[i][j] = '2';
                    while(q.size() > 0){
                        size = q.size();
                        for(auto k = 0; k<size; k++){
                            auto currentNode = q.front();
                            q.pop();
                            auto x = currentNode.first, y = currentNode.second;
                            for(auto l=0; l<4; l++){
                                auto nextI = x + dir[l][0], nextJ = y + dir[l][1];
                                if(nextI >= 0 && nextJ >=0 && nextI < m && nextJ < n && grid[nextI][nextJ] == '1'){
                                    grid[nextI][nextJ] = '2';
                                    q.push({nextI, nextJ});
                                }
                            }
                        }
                    }
                }
            }
        }
        return numberIslands;
    }
};