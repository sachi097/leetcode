class Solution {
public:
    int rob(vector<int>& nums) {
     if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        int *f = new int[n];
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        // House(0) is robbed
        for (int i = 2; i < n - 1; i ++) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }
        int x = f[n - 2];
        // House(0) is not robbed
        f[0] = 0;
        f[1] = nums[1];
        for (int i = 2; i < n; i ++) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }
        x = x > f[n - 1] ? x : f[n - 1];
        return x;
    }
    
};