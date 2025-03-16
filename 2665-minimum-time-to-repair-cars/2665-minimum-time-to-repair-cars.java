class Solution {
    boolean find(long mid, int[] ranks, int cars){
        long numberCars = 0;
        for(int i=0; i<ranks.length; i++){
            numberCars += Math.floor(Math.sqrt(mid / ranks[i]));
            if(numberCars >= cars){
               return true;
            }
        }
        return false ;
    }


    public long repairCars(int[] ranks, int cars) {
        long l = 1, h = Arrays.stream(ranks).min().getAsInt() * (long) cars * (long) cars;
        long ans = h;
        while(l<=h){
            long mid = (l + h) / 2;
            if(find(mid, ranks, cars)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
}