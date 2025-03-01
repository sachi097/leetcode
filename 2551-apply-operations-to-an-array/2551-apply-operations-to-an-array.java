class Solution {
    public int[] applyOperations(int[] nums) {
        int i = 0, j = 0, n = nums.length;
        int temp;
        while(j < n){
            if(j+1 < n && nums[j] == nums[j+1]){
                nums[j] *= 2;
                nums[j+1] = 0;
            }

            if(nums[j] != 0){
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
            }

            j++;
        }
        return nums;
    }
}