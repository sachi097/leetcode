class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, operations = 0;
        sort(nums.begin(), nums.end());
        while(left < right){
            if((nums[left] + nums[right]) == k){
                operations++;
                left++;
                right--;
            }
            else if(nums[left] + nums[right] < k){
                left++;
            }
            else{
                right--;
            }
        }
        return operations;
    }
};