class Solution {
public:

    void solve(int idx, vector<int> &nums, vector<vector<int>> &result){
        if(idx >= nums.size()){
            result.push_back(nums);
        }

        for(auto i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            solve(idx+1, nums, result);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(0, nums, result);
        return result;
    }
};