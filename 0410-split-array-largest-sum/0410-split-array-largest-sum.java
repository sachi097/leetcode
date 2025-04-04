class Solution {

    public boolean checkSplitPossible(int[] nums, int splitSum, int k){
        int splits = 0, prefixSum = 0;
        for(int i=0; i<nums.length; i++){
            if(prefixSum + nums[i] <= splitSum){
                prefixSum += nums[i];
            }
            else{
                prefixSum = nums[i];
                splits++;
            }
        }
        // if splits is less than k then it's possible to futher split the splits into k splits
        // because sum of splits < splitSum on further split into k splits will remain less than splitsum
        return splits + 1 <= k;
    }

    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        int low = Arrays.stream(nums).max().getAsInt();
        int high = Arrays.stream(nums).sum();

        int ans = -1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(checkSplitPossible(nums, mid, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;

    }
}