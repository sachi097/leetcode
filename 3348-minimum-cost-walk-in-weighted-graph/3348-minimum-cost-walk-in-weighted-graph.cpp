class Solution {
public:
    vector<int> minimumCost(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    vector<vector<int>> adj(N); // Adjacency list
    vector<int> c(N, (1 << 30) - 1); // Cost array, initialized with maximum possible value
    
    // Construct adjacency list and update cost array
    for (vector<int> edge : edges) {
        int u = edge[0], v = edge[1], k = edge[2];
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u] = c[u] & k; // Update cost with bitwise AND
        c[v] = c[v] & k;
    }
    
    // BFS to find connected components and update cost array for each component
    queue<int> q;
    vector<int> group(N, -1); // Group array to store component group of each vertex
    for (int i = 0; i < N; i++) {
        if (group[i] == -1) {
            group[i] = i; // Assign component group ID
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                c[i] = c[i] & c[u]; // Update cost with bitwise AND of all vertices in the component
                for (int v : adj[u]) {
                    if (group[v] == -1) {
                        group[v] = i;
                        q.push(v);
                    }
                }
            }
        }
    }
    
    // Process queries
    vector<int> res;
    for (vector<int> query : queries) {
        int s = query[0], t = query[1];
        if (s == t) {
            res.push_back(0); // Same starting and ending vertex
        } else {
            if (group[s] == group[t]) {
                res.push_back(c[group[s]]); // Same connected component
            } else {
                res.push_back(-1); // Different connected components
            }
        }
    }
    return res;
}
};