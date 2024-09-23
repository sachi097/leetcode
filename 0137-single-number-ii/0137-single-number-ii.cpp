class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int k = 0; k<=31; k++){
            int countOnes = 0;
            for(int i=0; i<nums.size(); i++){
                countOnes += (nums[i] & 1<<k) ? 1 : 0;
            }
            if(countOnes % 3 == 1){
                result = result | (1<<k);
            }
        }
        return result;
    }
};