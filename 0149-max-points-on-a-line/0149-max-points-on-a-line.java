class Solution {
    public int maxPoints(int[][] points) {
        
        int n = points.length;
        int ans = 1;
        for(int i=0; i<n; i++){
            HashMap<Double, Integer> slopes = new HashMap<>();
            for(int j=0; j<n; j++){

                if(i == j){
                    continue;
                }

                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                double angle = Math.atan2(dy, dx);
                slopes.compute(angle, (k, v) -> v == null ? 1 : v + 1);
            }

            Optional<Integer> max = slopes.values().stream().max(Comparator.naturalOrder());

            ans = Math.max(ans, max.isPresent() ? max.get() + 1 : 1);
        }
        
        return ans;
    }
}