class Solution {
public:
    int dp[201][1001];
    int solve(int idx, int k, vector<int> &nums){
        if(k == 0){
            return 1;
        }

        if(idx >= nums.size() || k < 0){
            return 0;
        }

        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        int result = 0;
        for(auto i=idx; i<nums.size(); i++){
            int take = solve(0, k - nums[i], nums);
            result += take;
        }

        return dp[idx][k] = result;
    }

    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(0, target, nums);
    }
};