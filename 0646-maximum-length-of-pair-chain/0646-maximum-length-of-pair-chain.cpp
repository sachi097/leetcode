class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        vector<int> dp(n, 1);

        sort(pairs.begin(), pairs.end());

        int maxChain = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxChain = max(maxChain, dp[i]);
                }
            }
        }

        return maxChain;
    }
};