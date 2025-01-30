class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unionSet(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if(parent_a == parent_b) {
            return;
        }

        if(rank[parent_a] > rank[parent_b]){
            parent[parent_b] = parent_a; 
        }
        else if(rank[parent_b] > rank[parent_a]){
            parent[parent_a] = parent_b;
        }
        else{
            parent[parent_b] = parent_a;
            rank[parent_a]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1, 0);
        rank.resize(n+1, 1);

        for(auto i=1; i<=n; i++){
            parent[i] = i;
        }

        vector<int> ans(2);
        for(auto i=0; i<n; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(find(a) != find(b)){
                unionSet(a, b);
            }
            else{
                ans[0] = a;
                ans[1] = b;
            }
        }
        return ans;
    }
};