class Solution {
    public void getSubset(int[] nums, int idx, List<List<Integer>> result, List<Integer> subSet){
        if(idx >= nums.length){
            result.add(new ArrayList<>(subSet));
            return;
        }

        subSet.add(nums[idx]);
        getSubset(nums, idx+1, result, subSet);
        subSet.remove(subSet.size() - 1);

        while(idx+1<nums.length && nums[idx]==nums[idx+1]){
            idx++;
        }
            
        getSubset(nums, idx+1, result, subSet);
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        getSubset(nums, 0, result, new ArrayList<>());
        return result;
    }
}