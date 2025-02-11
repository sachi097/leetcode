class Solution {

    public long calculateTripsForCurrentTime(int[] time, long currentTime){
        long ans = 0;
        for(int i=0; i<time.length; i++){
            ans += (currentTime / time[i]);
        }
        return ans;
    }

    public long minimumTime(int[] time, int totalTrips) {
        long min = Arrays.stream(time).min().getAsInt();
        long low = 1, high = totalTrips * min, mid;
        long ans = high, currentTrips;
        while(low <= high){
            mid = low + (high - low) / 2;
            currentTrips = calculateTripsForCurrentTime(time, mid);
            if(currentTrips >= totalTrips){
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