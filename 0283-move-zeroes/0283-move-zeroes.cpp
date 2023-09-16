class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0 , j;
        for(j = 0; j < nums.size(); j++){
            if(nums[i] != 0){
                i++;
            }
            if(i < nums.size() && i < j && nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};