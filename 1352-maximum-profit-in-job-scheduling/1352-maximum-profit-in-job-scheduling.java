class Solution {

    int findNextId(int[][] interval, int idx, int startTime){
        int  high = interval.length - 1, low = idx, mid, result = interval.length + 1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(interval[mid][0] >= startTime){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return result;
    }

    int solve(int[][] interval, int idx, int[] dp){
        if(idx >= interval.length){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int nextIdx = findNextId(interval, idx, interval[idx][1]);
        int take = interval[idx][2] + solve(interval, nextIdx, dp);
        int notTake = solve(interval, idx + 1, dp);

        return dp[idx] = Math.max(take, notTake);
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int[] dp = new int[50001];

        Arrays.fill(dp, -1);

        int n = profit.length;
        int[][] interval = new int[n][3];

        for(int i=0; i<n; i++){
            interval[i][0] = startTime[i];
            interval[i][1] =  endTime[i];
            interval[i][2] =  profit[i];            
        }

        Arrays.sort(interval, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);

        return solve(interval, 0, dp);
    }
}