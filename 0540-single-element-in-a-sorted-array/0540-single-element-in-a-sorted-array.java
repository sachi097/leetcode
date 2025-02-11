class Solution {
    public int singleNonDuplicate(int[] nums) {
        int low = 0, high = nums.length - 1, mid;
        boolean isEven = false;
        while(low < high){
            mid = low + (high - low) / 2;
            if((high - mid) % 2 == 0){
                isEven = true;
            }
            else{
                isEven = false;
            }

            if(nums[mid] != nums[mid+1]){
                if(isEven){
                    high = mid;
                }
                else{
                    low = mid + 1;
                } 
            }
            else {
                if(isEven){
                    low = mid + 2;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return nums[high];
    }
}