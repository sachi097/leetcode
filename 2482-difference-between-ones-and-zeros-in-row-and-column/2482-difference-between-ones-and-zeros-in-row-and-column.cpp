class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
        for(auto i=0; i<m; i++){
            int countOne = 0, countZero = 0;
            for(auto j=0; j<n; j++){
                if(grid[i][j] == 1){
                    countOne++;
                }
                else{
                    countZero++;
                }
            }
            for(auto j=0; j<n; j++){
                diff[i][j] = countOne - countZero;
            }
        }
        for(auto j=0; j<n; j++){
            int countOne = 0, countZero = 0;
            for(auto i=0; i<m; i++){
                if(grid[i][j] == 1){
                    countOne++;
                }
                else{
                    countZero++;
                }
            }
            for(auto i=0; i<m; i++){
                diff[i][j] += countOne - countZero;
            }
        }
        return diff;
    }
};