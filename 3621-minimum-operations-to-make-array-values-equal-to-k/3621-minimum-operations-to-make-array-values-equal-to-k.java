class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> s = new HashSet<>();
        for(int i : nums){
            if(k>i) return -1;

            else if(k<i)
                s.add(i);

        }
        return s.size();
    }
}