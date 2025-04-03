class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(parent[i] != i){
            return parent[i] = find(parent[i]);
        }
        return i;
    }

    void unionDSU(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if(parent_a == parent_b){
            return;
        }

        if(rank[parent_a] > rank[parent_b]){
            parent[parent_b] = parent_a;
        }
        else if(rank[parent_b] > rank[parent_b]){
            parent[parent_a] = parent_b;
        }
        else{
            parent[parent_b] = parent_a;
            rank[parent_a]++;
        }
     }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rank.resize(n);

        vector<int> cost(n, -1);

        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u); 
            int parent_v = find(v);

            if(parent_u != parent_v){
                unionDSU(u, v);
                cost[parent_u] &= cost[parent_v];
            }

            cost[parent_u] &= w;
        }

        vector<int> result(query.size(), -1);
        int i = 0;
        for(auto &q: query){
            int src = q[0];
            int dst = q[1];

            if(src == dst){
                result[i] = 0;
                continue;
            }

            if(find(src) == find(dst)){
                result[i] = cost[find(src)];
            }

            i++;
        }

        return result;

    }
};