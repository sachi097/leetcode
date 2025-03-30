class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int n = heights.length;
        Stack<Integer> nextPersonStack = new Stack<>();
        int[] ans = new int[n];

        nextPersonStack.add(heights[n-1]);

        for(int i=n-2; i>=0; i--){
            int count = 0;
            while(!nextPersonStack.isEmpty() && heights[i] > nextPersonStack.peek()){
                nextPersonStack.pop();
                count++;
            }
            ans[i] = count + (nextPersonStack.isEmpty() ? 0 : 1);
            nextPersonStack.add(heights[i]);
        }

        return ans;
    }
}