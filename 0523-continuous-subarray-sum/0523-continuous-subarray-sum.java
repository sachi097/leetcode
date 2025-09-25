class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int answer = 0;
        Map<Integer, Integer> maduloMap = new HashMap<>();
        maduloMap.put(0, -1);
        int prefixSum = 0;
        for(int i=0; i<nums.length; i++){
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            if(maduloMap.containsKey(remainder)){
                int j = maduloMap.get(remainder);
                if(i - j >= 2){
                    return true;
                }
            }
            else{
                maduloMap.put(remainder, i);
            }
        }
        return false;
    }
}