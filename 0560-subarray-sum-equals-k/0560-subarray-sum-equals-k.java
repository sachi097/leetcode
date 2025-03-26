class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        int ans = 0;

        int prefixSum = 0;
        for(int num: nums){
            prefixSum += num;
            if(map.containsKey(prefixSum - k)){
                ans += map.get(prefixSum - k);
            }
            map.put(prefixSum, map.getOrDefault(prefixSum, 0) + 1);
        }

        return ans;
    }
}