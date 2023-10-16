class Solution {
public:
    int dfs(vector<vector<int>> &adj, vector<bool> &visited, int from){
        int change = 0;
        visited[from] = true;
        for(auto to: adj[from]){
            if(!visited[abs(to)]){
                change += dfs(adj, visited, abs(to)) + (to > 0);
            }
        }
        return change;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto el: connections){
            adj[el[0]].push_back(el[1]);
            adj[el[1]].push_back(-el[0]);
        }
        return dfs(adj, vector<bool>(n) = {}, 0);
    }

};

