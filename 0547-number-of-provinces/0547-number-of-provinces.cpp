class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj, vector<int> &visited){
        visited[u] = 1;
        for(auto &v: adj[u]){
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = 0;
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        for(auto i=0; i<n; i++){
            for(auto j=0; j<n; j++){
                if(i != j){
                    if(isConnected[i][j]){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        for(auto i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                provinces++;
            }
        }
        return provinces;
    }
};