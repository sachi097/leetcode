class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> allRotten;
        map<pair<int,int>, int> hashMap;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(auto i=0; i<m; i++){
            for(auto j=0; j<n; j++){
                if(grid[i][j] == 2){
                    allRotten.push_back({i,j});
                }
                if(grid[i][j] == 1){
                    hashMap[{i,j}] = INT_MAX;
                }
            }
        }
        int maxMinutes = 0;
        queue<pair<int,int>> q;
        for(auto rott: allRotten){
            q.push(rott);
            int minute = 1;
            set<pair<int,int>> visited;
            while(!q.empty()){
                int size = q.size();
                for(auto i=0; i<size; i++){
                    auto currentOrange = q.front();
                    q.pop();
                    int x = currentOrange.first;
                    int y = currentOrange.second;
                    for(auto dir: directions){
                        int newX = x + dir[0];
                        int newY = y + dir[1];
                        if(visited.find({newX,newY}) == visited.end() && newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == 1){
                            q.push({newX, newY});
                            visited.insert({newX,newY});
                            hashMap[{newX,newY}] = min(hashMap[{newX,newY}],minute);
                        }
                    }
                }
                minute++;
            }
        }
        for(auto el: hashMap){
            maxMinutes = max(maxMinutes,el.second);
        }
        return maxMinutes == INT_MAX ? -1: maxMinutes;
    }
};