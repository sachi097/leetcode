class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = nums[0];
        for(auto i=1; i<nums.size(); i++){
            x ^= nums[i];
        }
        cout<<x<<endl;
        for(auto i=0; i<=nums.size(); i++){
            x ^= i;
        }
        return x;
    }
};