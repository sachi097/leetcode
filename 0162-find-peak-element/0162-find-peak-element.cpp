class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(low == high - 1){
                if(nums[low] > nums[high]){
                    return low;
                }
                else{
                    return high;
                }
            }
            if(mid != 0 && mid != n - 1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid + 1]){
                return mid;
            }
            else if(mid != 0 && mid != n - 1 && nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high == -1 ? 0 : n - 1;
    }
};