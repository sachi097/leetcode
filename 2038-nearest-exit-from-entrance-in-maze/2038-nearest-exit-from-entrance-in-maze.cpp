class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size(), exit = 0;
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        int k[4] = {-1, 0, 0, 1};
        int l[4] = {0, -1, 1, 0};
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                pair<int,int> currentPosition = q.front();
                q.pop();
                int x = currentPosition.first;
                int y = currentPosition.second;
                if((x != entrance[0] || y != entrance[1]) && (x == 0 || y == 0 || x == m - 1 || y == n - 1)){
                    return exit;
                }
                for(auto j=0; j<4; j++){
                    int newX = x + k[j], newY = y + l[j];
                    if(newX >= 0 && newX < m && newY >= 0 && newY < n && maze[newX][newY] == '.'){
                        q.push({newX, newY});
                        maze[newX][newY] = '+';
                    }
                }
            }
            exit++;
        }
        return -1;
    }
};