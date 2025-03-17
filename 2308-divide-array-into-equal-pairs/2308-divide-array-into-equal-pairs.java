class Solution {
    public boolean divideArray(int[] nums) {

        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        for(Map.Entry<Integer, Integer> entrySet: mp.entrySet()){
            if(entrySet.getValue() % 2 != 0){
                return false;
            }
        }

        return true;
    }
}