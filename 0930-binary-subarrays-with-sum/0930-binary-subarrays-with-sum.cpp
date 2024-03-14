class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), count = 0, preSum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for(auto i=0; i<n; i++){
            preSum += nums[i];
            if(preSum - goal >= 0 && hash.find(preSum - goal) != hash.end()){
                count += hash[preSum - goal];
            }
            hash[preSum] += 1;
        }
        return count;
    }
};
