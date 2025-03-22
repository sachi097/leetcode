class Solution {

    int find(int i, int[] parent){
        if(i != parent[i]){
            return parent[i] = find(parent[i], parent);
        }
        return i;
    }

    void union(int a, int b, int[] rank, int[] parent){
        int parent_a = find(a, parent);
        int parent_b = find(b, parent);

        if(parent_a == parent_b){
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

    public int countCompleteComponents(int n, int[][] edges) {
        int[] parent = new int[n];
        int[] rank = new int[n];

        int[] nodes = new int[n];
        long[] edgesOfNodes = new long[n];

        Arrays.fill(rank, 1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(int i=0; i<edges.length; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            union(a, b, rank, parent);
        }

        for (int i = 0; i < n; i++) {
            nodes[find(i, parent)]++;
        }

        for (int[] edge : edges) {
            edgesOfNodes[find(edge[0], parent)]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find(i, parent) == i) {
                if (edgesOfNodes[i] == (long) nodes[i] * (nodes[i] - 1) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
}