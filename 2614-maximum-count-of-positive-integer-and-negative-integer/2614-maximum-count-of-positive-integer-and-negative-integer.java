class Solution {
    public int maximumCount(int[] nums) {
        int n = nums.length;

        int firstP = apnaLowerB(nums, 1) ; //>= 1
        int firstN = apnaLowerB(nums, 0);  //>=0

        return Math.max(n - firstP, firstN);
    }

    public int apnaLowerB(int[] nums, int target) {
        int l = 0;
        int r = nums.length-1;
        int result = nums.length;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(nums[mid] < target) {
                l = mid+1;
            } else {
                result = mid;
                r = mid-1;
            }
        }
        //nums = {0, 0, 0, 0}
        return result;
    }
}