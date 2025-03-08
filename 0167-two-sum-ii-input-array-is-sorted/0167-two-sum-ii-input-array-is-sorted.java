class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        int left = 0, right = n - 1;
        int sum = 0;
        while(left < right){
            sum = numbers[left] + numbers[right];
            if(sum == target){
                return new int[]{left+1, right+1};
            }

            if(sum > target){
                right--;
            }
            else{
                left++;
            }
        }
        return new int[]{-1, -1};
    }
}