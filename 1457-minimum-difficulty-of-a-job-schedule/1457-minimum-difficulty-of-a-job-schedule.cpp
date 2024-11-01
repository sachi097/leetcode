class Solution {
public:
    int dp[301][11];

    int solve(int i, int d, vector<int> &nums){
        if(d == 1){
            return dp[i][d] = *max_element(nums.begin() + i, nums.end()); 
        }

        if(dp[i][d] != -1){
            return dp[i][d];
        }

        int n = nums.size();
        int maxD = INT_MIN;
        int finalResult = INT_MAX;

        for(int k=i; k <= n-d; k++){
            maxD = max(maxD, nums[k]);
            int result = maxD + solve(k+1, d-1, nums);

            finalResult = min(finalResult, result);
        }

        return dp[i][d] = finalResult;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()){
            return -1;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, d, jobDifficulty);    
    }
};