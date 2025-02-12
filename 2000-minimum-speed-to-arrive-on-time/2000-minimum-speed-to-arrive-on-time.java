class Solution {
    public boolean calculateSpeed(int[] dist, int currentRate, double hour){
        double ans = 0;
        int n = dist.length;
        for(int i=0; i<n-1; i++){
            ans += Math.ceil((double) (dist[i]) / (double) (currentRate));
        }
        ans += (double) (dist[n-1]) / (double) (currentRate);
        return ans <= hour;
    }

    public int minSpeedOnTime(int[] dist, double hour) {
        int low = 1, high = (int) 1e7, mid;
        int ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(calculateSpeed(dist, mid, hour)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
}