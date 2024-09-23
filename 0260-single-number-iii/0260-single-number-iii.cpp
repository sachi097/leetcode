class Solution {
public:
    static vector<int> singleNumber(vector<int>& nums) {
        int mask = 0, groupA = 0, groupB = 0;
        long long res = 0;
        
        // find XOR of the elements
        for(auto ele: nums){
            res ^= ele;
        }

        // find mask
        mask = res & (-res);

        // divide into groups
        for(auto ele: nums){
            if(mask & ele)
                groupA ^= ele;
            else
                groupB ^= ele;
        }

        return {groupA, groupB};
    }
};