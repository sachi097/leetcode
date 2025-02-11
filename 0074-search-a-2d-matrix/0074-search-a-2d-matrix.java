class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int low = 0, high = m*n - 1, mid, i, j;
        while(low <= high){
            mid = low + (high - low) / 2;
            i = mid / n;
            j = mid % n;
            if(matrix[i][j] == target){
                return true;
            }

            if(matrix[i][j] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
}