class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size(), i;
        for(i=1; i<n; i++){
            nums[i]=nums[i-1]+nums[i];
        }
        int tempSum=nums[n-1];
        if(tempSum-nums[0]==0){
            return 0;
        }
        for(i=1; i<n; i++){
            if(nums[i-1]==tempSum-nums[i]){
                return i;
            }
        }
        return -1;
    }
};