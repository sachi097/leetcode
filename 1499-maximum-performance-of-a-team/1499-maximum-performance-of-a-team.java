class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int[][] combinedArray = new int[n][2];
        for(int i=0; i<n; i++){
            combinedArray[i][0] = efficiency[i];
            combinedArray[i][1] = speed[i];
        }

        Arrays.sort(combinedArray, (a , b) -> b[0] - a[0]);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sum = 0, ans = 0;
        int module = (int) 1e9 + 7;

        for(int i=0; i<n; i++){
            sum += combinedArray[i][1];
            pq.add(combinedArray[i][1]);
            if(pq.size() > k){
                sum -= pq.poll();
            }
            ans = Math.max(ans, (sum * combinedArray[i][0]));
        }

        return (int) (ans % module);
    }
}