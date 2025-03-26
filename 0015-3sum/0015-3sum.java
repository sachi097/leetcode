class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        
        HashSet<List<Integer>> set = new HashSet<>();
        for(int k=0; k<n-2; k++){
            int target = -nums[k];
            int i = k + 1, j = n - 1;
            while(i < j){
                if(nums[i] + nums[j] > target){
                    j--;
                }
                else if(nums[i] + nums[j] < target){
                    i++;
                }
                else{
                    set.add(List.of(nums[k], nums[i], nums[j]));
                    i++;
                    j--;
                }
            }
        }

        return set.stream().collect(Collectors.toList());
    }
}