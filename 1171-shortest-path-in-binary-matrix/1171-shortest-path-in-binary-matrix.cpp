class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if(grid[0][0] == 1){
            return -1;
        }

        if(row == 1 && col == 1 && grid[0][0] == 0){
            return 1;
        }

        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        queue<pair<int, int>> q;

        q.push({0, 0});
        grid[0][0] = 1;
        int level = 1;


        int i = 0, j = 0;
        while(!q.empty()){
            int size = q.size();
            for(int k=0; k<size; k++){
                auto top = q.front();
                q.pop();

                i = top.first;
                j = top.second;

                for(int m=0; m<8; m++){
                    int nextI = i + dir[m][0];
                    int nextJ = j + dir[m][1];

                    if(nextI >= 0 && nextI < row && nextJ >= 0 && nextJ < col && grid[nextI][nextJ] == 0){
                        q.push({nextI, nextJ});
                        grid[nextI][nextJ] = 1;
                        if(nextI == row-1 && nextJ == col-1){
                            return level+1;
                        }
                    }
                }
            }

            level++; 

        }

        return -1;

    }
};