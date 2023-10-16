class Solution {
public:
    int dfs(int currentCity, int n, vector<vector<int>>& isConnected, vector<int>& visited){
        if(!visited[currentCity]){
            visited[currentCity] = 1;
            for(auto k=0; k<n; k++){
                if(k!=currentCity && isConnected[currentCity][k]){
                    dfs(k, n, isConnected, visited);
                }
            }
            return 1;
        }
        return 0;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = 0;
        vector<int> visited(n, 0);
        for(auto i=0; i<n; i++){
            for(auto j=0; j<n; j++){
                if(isConnected[i][j]){
                    provinces = provinces + dfs(i, n, isConnected, visited);
                }
            }
        }
        return provinces;
    }
};