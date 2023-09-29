class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> hash;
        int count = 0;
        for(auto i = 0; i < grid.size(); i++){
            string str = "(";
            for( auto j = 0; j < grid[0].size(); j++){
                str += to_string(grid[i][j]) + "_";
            }
            if(hash.count(str)){
                hash[str]++;
            }
            else{
                hash[str] = 1;
            }
        }
        for(auto j = 0; j < grid[0].size(); j++){
            string str = "(";
            for( auto i = 0; i < grid.size(); i++){
                str += to_string(grid[i][j]) + "_";
            }
            if(hash.count(str)){
                count+=hash[str];
            }
        }
        return count;
    }
};