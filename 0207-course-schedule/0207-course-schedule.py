class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj_graph = [[] for i in range(numCourses)]
        in_degree = [0] * numCourses
        for i in range(len(prerequisites)):
            dest, source = prerequisites[i]
            adj_graph[source].append(dest)
            in_degree[dest] += 1
        
        courses = 0
        q = deque()
        for i in range(numCourses):
            if in_degree[i] == 0:
                q.append(i)
                courses += 1
        
        while q:
            current_source = q.pop()
            for edge in adj_graph[current_source]:
                in_degree[edge] -= 1
                if in_degree[edge] == 0:
                    q.append(edge)
                    courses += 1
        
        return courses == numCourses
        