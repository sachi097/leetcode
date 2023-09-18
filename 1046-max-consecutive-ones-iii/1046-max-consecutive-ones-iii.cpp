class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxOnes = INT_MIN, left = 0, right = 0, countZeros = 0;
        while(right < nums.size()){
            if(nums[right] == 0){
                countZeros++;
            }
            while(countZeros > k){
                if(nums[left] == 0){
                    countZeros--;
                }
                left++;
            }
            maxOnes = max(maxOnes, right - left + 1);
            right++;
        }
        return maxOnes;
    }
};