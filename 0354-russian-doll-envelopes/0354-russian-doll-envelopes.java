class Solution {

    // int findMaxEnvelopes(int idx, int n, int[][] envelopes, int[] dp){

    //     if(idx >= n){
    //         return 0;
    //     }

    //     if(dp[idx] != -1){
    //         return dp[idx];
    //     }

    //     dp[idx] = 1;

    //     for(int i=idx+1; i<n; i++){
    //         if(envelopes[idx][0] < envelopes[i][0] && envelopes[idx][1] < envelopes[i][1]){
    //             dp[idx] = Math.max(dp[idx], 1 + findMaxEnvelopes(i, n, envelopes, dp));
    //         }
    //     }

    //     return dp[idx];

    // }

    int lowerBound(ArrayList<Integer> dp, int target){
        int low = 0, high = dp.size() - 1, idx = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(dp.get(mid) >= target){
                idx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return idx;
    }

    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> (a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]));
        int n = envelopes.length;
        ArrayList<Integer> dp = new ArrayList<>();

        for(int i=0; i<n; i++){
            int idx = lowerBound(dp, envelopes[i][1]);
            if(idx != -1){
                dp.set(idx, envelopes[i][1]);
            }
            else{
                dp.add(envelopes[i][1]);
            }
        }

        return dp.size();


        // dp solution
        // Arrays.sort(envelopes, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        // Arrays.fill(dp, -1);
        // dp[n - 1] = 1;
        // return Math.max(1, findMaxEnvelopes(0, n, envelopes, dp));
    }
}