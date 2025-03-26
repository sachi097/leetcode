class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        for(int k=0; k<n-2; k++){
            if(k > 0 && nums[k] == nums[k-1]){
                continue;
            }
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
                    ans.add(List.of(nums[k], nums[i], nums[j]));
                    i++;
                    
                    while(i < j && nums[i] == nums[i-1]){
                        i++;
                    }
                }
            }
        }

        return ans;
    }
}