class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCount = INT_MIN, maxRow = 0;
        int m = mat.size(), n = mat[0].size();
        for(auto i=0; i<m; i++){
            int count = 0;
            for(auto j=0; j<n; j++){
                if(mat[i][j] == 1)
                    count++;
            }
            if(count > maxCount){
                maxCount = count;
                maxRow = i;
            }
        }
        return {maxRow, maxCount};
    }
};