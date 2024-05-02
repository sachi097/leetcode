class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left < right && nums[left] < 0){
            if(abs(nums[left]) == nums[right]){
                return nums[right];
            }
            if(abs(nums[left]) < nums[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return -1;
    }
};