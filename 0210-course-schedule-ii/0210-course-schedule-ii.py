class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj_graph = [[] for i in range(numCourses)]
        in_degree = [0] * numCourses
        for i in range(len(prerequisites)):
            dest, source = prerequisites[i]
            adj_graph[source].append(dest)
            in_degree[dest] += 1
        
        courses = []
        q = deque()
        for i in range(numCourses):
            if in_degree[i] == 0:
                q.append(i)
                courses.append(i)
        
        while q:
            current_source = q.pop()
            for edge in adj_graph[current_source]:
                in_degree[edge] -= 1
                if in_degree[edge] == 0:
                    q.append(edge)
                    courses.append(edge)
        
        return courses if len(courses) == numCourses else []