class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m = len(heights)
        n = len(heights[0])

        # Min-heap (priority_queue)
        pq = [(0, 0, 0)]  # (effort, i, j)

        # Distance (effort) matrix
        result = [[float('inf')] * n for _ in range(m)]
        result[0][0] = 0

        # Directions
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]

        while pq:
            diff, i, j = heapq.heappop(pq)

            # If we reach the target cell
            if i == m - 1 and j == n - 1:
                return diff

            for dx, dy in directions:
                ni = i + dx
                nj = j + dy

                if 0 <= ni < m and 0 <= nj < n:
                    nextDiff = max(diff, abs(heights[i][j] - heights[ni][nj]))

                    if nextDiff < result[ni][nj]:
                        result[ni][nj] = nextDiff
                        heapq.heappush(pq, (nextDiff, ni, nj))

        return result[m - 1][n - 1]