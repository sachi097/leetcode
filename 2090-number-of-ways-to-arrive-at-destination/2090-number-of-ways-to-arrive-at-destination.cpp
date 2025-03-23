class Solution {
public:
    typedef pair<long long, int> P;
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto &road: roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        
        vector<long long> result(n , LLONG_MAX);
        vector<int> dp(n, 0);
        dp[0] = 1;
        int src = 0;
        result[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int u = top.second;
            long long d = top.first;
            
            for(auto &e: adj[u]){
                int v = e.first;
                int w = e.second;
                
                if(d + w < result[v]){
                    dp[v] = dp[u];
                    result[v] = d + w;
                    pq.push({d+w, v});
                }
                else if(d + w == result[v]){
                    dp[v] = (dp[v] + dp[u]) % M;
                }
            }
        }

        return dp[n-1];
        
    }
};