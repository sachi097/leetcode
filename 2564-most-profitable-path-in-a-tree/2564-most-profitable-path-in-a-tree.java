import java.util.*;

class Solution {
    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = amount.length;
        
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) 
            graph[i] = new ArrayList<>();
        for (int[] e : edges) {
            graph[e[0]].add(e[1]);
            graph[e[1]].add(e[0]);
        }
        
        
        int[] parent = new int[n];
        Arrays.fill(parent, -1);
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.offer(bob);
        parent[bob] = -2;
        while (!dq.isEmpty()) {
            int cur = dq.poll();
            if (cur == 0) break;
            for (int nxt : graph[cur]) {
                if (parent[nxt] == -1) {
                    parent[nxt] = cur;
                    dq.offer(nxt);
                }
            }
        }
        
        
        List<Integer> bobPath = new ArrayList<>();
        for (int cur = 0; cur != -2; cur = parent[cur]) {
            bobPath.add(cur);
            if (cur == bob) break;
        }
        Collections.reverse(bobPath);
        
        
        int[] bobTime = new int[n];
        Arrays.fill(bobTime, Integer.MAX_VALUE);
        for (int i = 0; i < bobPath.size(); i++) {
            bobTime[bobPath.get(i)] = i;
        }
        
        
        int[] ans = new int[]{Integer.MIN_VALUE};
        dfs(0, -1, 0, 0, ans, bobTime, amount, graph);
        return ans[0];
    }
    
    private void dfs(int node, int parent, int time, int profit, int[] ans, int[] bobTime, int[] amount, List<Integer>[] graph) {
       
        int newProfit;
        if (time < bobTime[node])
            newProfit = profit + amount[node];
        else if (time == bobTime[node])
            newProfit = profit + amount[node] / 2;
        else
            newProfit = profit;
        
        boolean isLeaf = true;
        for (int nxt : graph[node]) {
            if (nxt == parent) continue;
            isLeaf = false;
            dfs(nxt, node, time + 1, newProfit, ans, bobTime, amount, graph);
        }
        if (isLeaf)
            ans[0] = Math.max(ans[0], newProfit);
    }
}