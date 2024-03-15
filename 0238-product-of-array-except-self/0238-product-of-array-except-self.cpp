class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), leftProduct = nums[0], rightProduct = nums[n-1];
        vector<int> answer(n, 1);
        for(auto i=1; i<n; i++){
            answer[i] = leftProduct;
            leftProduct *= nums[i];
        }
        for(auto i=n-2; i>=0; i--){
            answer[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return answer;
    }
};