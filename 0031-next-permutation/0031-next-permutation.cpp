class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int golaIndex = -1;
        int n = nums.size();
        for(int i=n-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                golaIndex = i-1;
                break;
            }
        }

        if(golaIndex != -1){
            int swapIndex = golaIndex;
            for(int i=n-1; i>golaIndex; i--){
                if(nums[i] > nums[golaIndex]){
                    swapIndex = i;
                    break;
                }
            }

            int temp = nums[swapIndex];
            nums[swapIndex] = nums[golaIndex];
            nums[golaIndex] = temp;
        }

        reverse(nums.begin() + golaIndex + 1, nums.end());
    }
};