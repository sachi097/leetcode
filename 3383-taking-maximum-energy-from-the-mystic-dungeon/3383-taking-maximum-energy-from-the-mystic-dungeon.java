class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length;
        int[] dp = Arrays.copyOfRange(energy, 0, n);
        for(int i=n-k-1; i>=0; i--){
            dp[i] = dp[i] + dp[i+k];
        }
        int maxEnergy = Arrays.stream(dp).max().getAsInt();
        return maxEnergy;
    }
}