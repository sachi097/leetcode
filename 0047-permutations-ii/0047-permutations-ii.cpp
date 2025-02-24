class Solution {
public:
    void solve(int idx, vector<int> &nums, vector<vector<int>> &result){
        if(idx >= nums.size()){
            result.push_back(nums);
        }

        unordered_set<int> uniqueSet;
        for(int i = idx; i < nums.size(); i++) {
            if(uniqueSet.count(nums[i]) > 0) {
                continue;
            }
            uniqueSet.insert(nums[i]);
            swap(nums[i], nums[idx]);
            solve(idx+1, nums, result);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        solve(0, nums, result);
        return result;
    }
};