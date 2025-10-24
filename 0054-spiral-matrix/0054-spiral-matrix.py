class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        start_row = 0
        end_row = len(matrix) - 1
        start_col = 0
        end_col = len(matrix[0]) - 1

        result = []
        
        while start_row <= end_row and start_col <= end_col:
            # print first row
            for j in range(start_col, end_col+1):
                result.append(matrix[start_row][j])
            
            start_row += 1

            # print last col
            for i in range(start_row, end_row+1):
                result.append(matrix[i][end_col])
            
            end_col -= 1

            #print last row
            if start_row <= end_row:
                for j in range(end_col, start_col-1, -1):
                    result.append(matrix[end_row][j])
                
                end_row -= 1
            
            #print first col
            if start_col <= end_col:
                for i in range(end_row, start_row-1, -1):
                    result.append(matrix[i][start_col])
                
                start_col += 1
        
        return result
