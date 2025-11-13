class Solution:
    directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]

    def dfs(self, i: int, j: int, grid: List[List[str]]) -> None:
        if 0 <= i < len(grid) and 0 <= j < len(grid[i]) and grid[i][j] == "1":
            grid[i][j] = "0"
            for direction in self.directions:
                self.dfs(i + direction[0], j + direction[1], grid)

    def numIslands(self, grid: List[List[str]]) -> int:
        result = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    self.dfs(i, j, grid)
                    result += 1
        
        return result