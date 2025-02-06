class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length, ptr = 0;
        if(n == 0)
            return new int[0];
        ArrayDeque<Integer> deq = new ArrayDeque<>();

        int[] result = new int[nums.length - k + 1];
        
        for(int i = 0; i<nums.length; i++) {
            //remove the max elements from front which are out of window size
            while(!deq.isEmpty() && deq.peekFirst() <= i-k)
                deq.pollFirst();
            
            //we maintain the deque in descending order
            while(!deq.isEmpty() && nums[i] > nums[deq.peekLast()])
                deq.pollLast();
            
            deq.add(i);

            if(i >= k-1) //Only when the window size first gets equal or greater than k
                result[ptr++] = nums[deq.peek()]; //front will have the max element (dequeue is maintained in descending order)
        }
        return result;
    }
}