class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        nums[1] = max(nums[0], nums[1]);
        for(auto i=2; i<n; i++){
            nums[i] = max(nums[i-1], nums[i] + nums[i-2]);
        }
        return nums[n-1];
    }
};