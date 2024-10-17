class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(auto el: nums){
            ans |= el;
        }
        return (ans<<(n-1));
    }
};