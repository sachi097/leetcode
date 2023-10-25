class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string,double>>>& edges,unordered_set<string>& visited,string from, string to, double product, double& ans){
        if(visited.find(from) != visited.end()){
            return;
        }
        visited.insert(from);
        if(from == to){
            ans = product;
            return;
        }
        for(auto edge: edges[from]){
            dfs(edges, visited, edge.first, to, product * edge.second, ans);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> edges;
        vector<double> result;
        string from, to;
        for(auto i=0; i < equations.size(); i++){
            edges[equations[i][0]].push_back({equations[i][1], values[i]});
            edges[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        for(auto query: queries){
            from = query[0];
            to = query[1];
            unordered_set<string> visited;
            if(edges.find(from) == edges.end() || edges.find(to) == edges.end()){
                result.push_back(-1.0);
            }
            else{
                double ans = -1.0, product = 1.0;
                dfs(edges,visited,from,to,product,ans);
                result.push_back(ans);
            }
        }
        return result;
    }
};