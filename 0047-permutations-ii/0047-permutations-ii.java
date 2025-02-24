class Solution {

    public void swap(int i, int j, int[] nums){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    public void solve(int[] nums, int idx, Set<List<Integer>> result){
        if(idx >= nums.length){
            result.add(Arrays.stream(nums)
                         .boxed()
                         .collect(Collectors.toList()));
            return;
        }

        for(int i=idx; i<nums.length; i++){
            swap(idx, i, nums);
            solve(nums, idx+1, result);
            swap(idx, i, nums);
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        Set<List<Integer>> result = new HashSet<>();
        solve(nums, 0, result);
        return result.stream().collect(Collectors.toList());
    }
}