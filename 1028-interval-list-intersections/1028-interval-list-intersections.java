class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        if(firstList.length == 0 || secondList.length == 0){
            return new int[][]{};
        }
        int p1 = 0, p2 = 0;
        List<int[]> ans = new ArrayList<>();
        while(p1 < firstList.length && p2 < secondList.length){
            int start1 = firstList[p1][0], end1 = firstList[p1][1];
            int start2 = secondList[p2][0], end2 = secondList[p2][1];

            if(start2 > end1){
                p1++;
            }
            else if(start1 > end2){
                p2++;
            }
            else {
                int start = Math.max(start1, start2);
                int end = Math.min(end1, end2);
                
                if(end2 < end1){
                    p2++;
                }
                else{
                    p1++;
                }

                ans.add(new int[]{start, end});
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}