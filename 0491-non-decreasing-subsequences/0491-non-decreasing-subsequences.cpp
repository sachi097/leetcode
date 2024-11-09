class Solution {
public:

    void solve(vector<int>& nums, int idx, int prev, vector<int> &seq, vector<vector<int>> &result){
        if(seq.size() >= 2){
            result.push_back(seq);
        }

        unordered_set<int> st;

        for(int i=idx; i<nums.size(); i++){
            if((prev == -1 || nums[i] >= nums[prev]) && st.find(nums[i]) == st.end()){
                seq.push_back(nums[i]); //do
                solve(nums, i+1, i, seq, result); //explore
                seq.pop_back(); //undo

                st.insert(nums[i]); //insert here for non-duplicate sequence
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> seq;
        solve(nums, 0, -1, seq, result);
        return result;
    }
};