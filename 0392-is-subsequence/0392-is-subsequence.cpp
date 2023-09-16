class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> m(size(s) + 1, vector<int> (size(t) + 1, 0));
        if(size(s) == 0) return true;
        if(size(t) == 0) return false;
        for(auto j=0; j <= size(t); j++){
            m[0][j] = 0;
        }
        for(auto i=0; i <= size(s); i++){
            m[i][0] = 0;
        }
        for(int i=1; i <= size(s); i++){
            for(int j=1; j <= size(t); j++){
                if(s[i-1] == t[j-1]){
                    m[i][j] = 1 + m[i-1][j-1];
                }
                else{
                    m[i][j] = max(m[i][j-1],  m[i-1][j]);
                }
            }
        }
        if(m[size(s)][size(t)] == size(s)) return true;
        return false;
    }
};