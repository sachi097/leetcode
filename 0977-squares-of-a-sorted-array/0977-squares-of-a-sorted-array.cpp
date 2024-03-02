class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n -1;
        vector<int> ans(n);
        for(auto j=r; j>=0; j--){
         if(abs(nums[l]) > abs(nums[r])){
            ans[j] = nums[l] * nums[l++];
         }
         else
         {
            ans[j] = nums[r] * nums[r--];   
         }
        }
        return ans;
    }
};