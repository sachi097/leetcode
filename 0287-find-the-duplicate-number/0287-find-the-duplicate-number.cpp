class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto i=0; i<nums.size(); i++){
            int index = abs(nums[i]);
            if(nums[index-1] < 0){
                return index;
            }
            nums[index - 1] *= -1;
        }
        return -1;
    }
};