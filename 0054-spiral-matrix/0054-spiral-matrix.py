class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        start_row, end_row, start_col, end_col = 0, len(matrix) - 1, 0, len(matrix[0]) - 1
        result = []

        while start_row <= end_row and start_col <= end_col:

            # first row
            for j in range(start_col, end_col + 1):
                result.append(matrix[start_row][j])
            
            start_row += 1

            # last col
            for i in range(start_row, end_row + 1):
                result.append(matrix[i][end_col])
            
            end_col -= 1

            if start_row <= end_row:
                for j in range(end_col, start_col - 1, -1):
                    result.append(matrix[end_row][j])
            
                end_row -= 1

            if start_col <= end_col:
                for i in range(end_row, start_row - 1, -1):
                    result.append(matrix[i][start_col])
            
                start_col += 1
        
        return result