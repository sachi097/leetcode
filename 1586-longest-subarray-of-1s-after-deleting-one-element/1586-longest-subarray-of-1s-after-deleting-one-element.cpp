class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxOneSubarray = INT_MIN, left = 0, right = 0, countZeros = 0;
        while(right < nums.size()){
            if(nums[right] == 0){
                countZeros++;
            }
            while(countZeros > 1){
                if(nums[left] == 0){
                    countZeros--;
                }
                left++;
            }
            maxOneSubarray = max(maxOneSubarray, right - left);
            right++;
        }
        return maxOneSubarray;
    }
};