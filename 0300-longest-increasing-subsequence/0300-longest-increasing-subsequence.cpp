class Solution {
public:
    
    // Dp memoization

    // int solveLIS(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
    //     if(i >= nums.size())
    //         return 0;

    //     if(prev != -1 && dp[i][prev] != -1)
    //         return dp[i][prev];

    //     int take = 0, skip = 0;

    //     //take
    //     if(prev == -1 || nums[prev] < nums[i]){
    //         take = 1 + solveLIS(i+1, i, nums, dp);
    //     }
        
    //     //skip always
    //     skip = solveLIS(i+1, prev, nums, dp);
        
    //     if(prev != -1) 
    //         return dp[i][prev] = max(take, skip);

    //     return max(take, skip);
    // }

    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveLIS(0, -1, nums, dp);

        // patience sorting
        
        int n = nums.size();
        vector<int> sorted;

        for(auto i=0; i<n; i++){
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if(it != sorted.end()){
                *it = nums[i];
            }
            else{
                sorted.push_back(nums[i]);
            }
        }
        return sorted.size();
    }
};