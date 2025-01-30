class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1, n = nums.size();
        int left = 0, right = 1;
        while(right < n){
            while(right < n && nums[right] == nums[left]){
                right++;
            }
            left++;
            if(right < n && left < n){
                k++;
                nums[left] = nums[right];
            }
        }
        return k;
    }
};