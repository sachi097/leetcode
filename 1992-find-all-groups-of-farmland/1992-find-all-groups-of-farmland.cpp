class Solution {
public:
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // dfs
    // vector<int> dfs(vector<vector<int>>& land, int m, int n, int i, int j){
    //     int endI = 0, endJ = 0;
    //     if(i >= 0 && j >= 0 && i < m && j < n && land[i][j] == 1){
    //         land[i][j] = 2;
    //         endI = i, endJ = j;
    //         for(auto l=0; l<4; l++){
    //             auto endPoints = dfs(land, m, n, i + dir[l][0], j + dir[l][1]);
    //             endI = max(endI, endPoints[0]);
    //             endJ = max(endJ, endPoints[1]);
    //         }
    //     }
    //     return {endI, endJ};
    // }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size(), size = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> ans;
        for(auto i=0; i<m; i++){
            for(auto j=0; j<n; j++){
                if(land[i][j] == 1){
                    //dfs
                    //auto endPoints = dfs(land, m, n, i, j);
                    // ans.push_back({i, j, endPoints[0], endPoints[1]});
                    
                    //bfs
                    q.push({i, j});
                    land[i][j] = 2;
                    int endI = i, endJ = j;
                    while(q.size() > 0){
                        size = q.size();
                        for(auto k=0; k<size; k++){
                            auto currentPosition = q.front();
                            q.pop();
                            for(auto l=0; l<4; l++){
                                auto nextX = currentPosition.first + dir[l][0], nextY = currentPosition.second + dir[l][1];
                                if(nextX >= 0 && nextY >= 0 && nextX < m && nextY < n && land[nextX][nextY] == 1){
                                    land[nextX][nextY] = 2;
                                    q.push({nextX, nextY});
                                    endI = max(endI, nextX);
                                    endJ = max(endJ, nextY);
                                }
                            }
                        }
                    }
                    ans.push_back({i, j, endI, endJ});
                }
            }
        }
        return ans;
    }
};