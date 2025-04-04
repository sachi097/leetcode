class Solution {
    int solve(int sIdx, int pIdx, String s, String p, int[][] dp){
        if(pIdx == p.length()){
            return sIdx == s.length() ? 1 : 0;
        }

        if(dp[sIdx][pIdx] != -1){
            return dp[sIdx][pIdx];
        }

        boolean firstCharMatch = sIdx < s.length() && (s.charAt(sIdx) == p.charAt(pIdx) || p.charAt(pIdx) == '.');

        if(pIdx + 1 < p.length() && p.charAt(pIdx+1) == '*'){
            int noTake = solve(sIdx, pIdx + 2, s, p, dp);
            int take = -1;
            if(firstCharMatch){
              take = solve(sIdx + 1, pIdx, s, p, dp);
            }

            return dp[sIdx][pIdx] = noTake == 1 || take == 1 ? 1 : 0;
        }

        if(firstCharMatch){
            dp[sIdx][pIdx] = solve(sIdx + 1, pIdx + 1, s, p, dp);
        }

        return dp[sIdx][pIdx];
    }

    public boolean isMatch(String s, String p) {
        int[][] dp = new int[21][21];
        for(int i=0; i<21; i++){
            Arrays.fill(dp[i], -1);
        }
        return solve(0, 0, s, p, dp) == 1;
    }
}