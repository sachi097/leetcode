class Solution {
    long findMaxPoints(int idx, int n, int[][] questions, long[] dp){
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        long take = questions[idx][0] + findMaxPoints(idx + questions[idx][1] + 1, n, questions, dp);
        long noTake = findMaxPoints(idx + 1, n, questions, dp);

        return dp[idx] = Math.max(take, noTake);
    }

    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] dp = new long[n];

        Arrays.fill(dp, -1);

        return findMaxPoints(0, n, questions, dp);
    }
}