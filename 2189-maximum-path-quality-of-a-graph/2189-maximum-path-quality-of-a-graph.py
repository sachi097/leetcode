class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        n = len(values)
        visited = [0] * n
        adj_list = [[] for _ in range(n)]
        for u, v, t in edges:
            adj_list[u].append([v, t])
            adj_list[v].append([u, t])
        
        res = [values[0]]

        def dfs(time, u, score):
            if time > maxTime:
                return
            
            if visited[u] == 0:
                score += values[u]
            
            visited[u] += 1

            if u == 0:
                res[0] = max(res[0], score)
            
            for v, t in adj_list[u]:
                dfs(time+t, v, score)
            
            visited[u] -= 1
        
        dfs(0, 0, 0)
        return res[0]


        