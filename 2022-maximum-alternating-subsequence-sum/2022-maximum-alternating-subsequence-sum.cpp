class Solution {
public:
    // long long dp[1000001][2];
    // long long solve(int i, bool even, vector<int> &nums){
     
    //     if(i >= nums.size()){
    //         return 0;
    //     }

    //     if(dp[i][even] != -1){
    //         return dp[i][even];
    //     }

    //     //skip
    //     long long skip = solve(i+1, even, nums);

    //     //take
    //     long long sum = 0;
    //     if(even){
    //         //evenSum
    //         sum += nums[i]; 
    //     }
    //     else{
    //         //oddSum
    //         sum -= nums[i];
    //     }

    //     long long take = sum + solve(i+1, !even, nums);

    //     return dp[i][even] = max(skip, take);

    // }


    long long maxAlternatingSum(vector<int>& nums) {
        //top-down
        // memset(dp, -1, size(dp));
        // return solve(0, 1, nums);

        //bottom up
        int n = nums.size();
        
        vector<vector<long>> t(n+1, vector<long>(2, 0));
            
        for(int i = 1; i < n+1; i++) {
            
            t[i][0] = max(t[i-1][1] - nums[i-1], t[i-1][0]);
            
            t[i][1] = max(t[i-1][0] + nums[i-1], t[i-1][1]);
            
            
        }
        
        return max(t[n][0], t[n][1]);
    }
};