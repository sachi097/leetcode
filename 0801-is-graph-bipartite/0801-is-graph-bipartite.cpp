class Solution {
public:
    unordered_map<int, vector<int>> adj;

    bool dfs(vector<vector<int>>& graph, int u, int colorU, vector<int> &color){
        color[u] = colorU;

        for(auto &v: graph[u]){
            if(color[v] == colorU){
                return false;
            }

            if(color[v] == -1){
                int colorV = 1 - colorU;
                if(dfs(graph, v, colorV, color) == false){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int u=0; u<graph.size(); u++){
            if(color[u] == -1){
                if(dfs(graph, u, 1, color) == false){
                    return false;
                }
            }
        }

        return true;
    }
};