class Solution {

    public boolean checkValid(int[] candies, long k, int mid){
        long childCount = 0;
        for(int candy: candies){
            childCount += candy / mid;
            if(childCount >= k){
                return true;
            }
        }

        return false;
    }

    public int maximumCandies(int[] candies, long k) {

        int ans = 0;
        int low = 1;
        int high = Arrays.stream(candies).max().getAsInt();

        while(low<=high){
            int mid = low + (high - low) / 2;
            if(checkValid(candies, k, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
}