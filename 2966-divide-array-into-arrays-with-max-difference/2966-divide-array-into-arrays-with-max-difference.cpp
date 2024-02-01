class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(auto i=0; i<nums.size(); i=i+3){
            vector<int> temp;
            if(nums[i+1] - nums[i] > k || nums[i+2] - nums[i+1] > k || nums[i+2] - nums[i] > k ){
                return {};
            }
            temp.assign(nums.begin()+i, nums.begin()+(i+3));
            ans.push_back(temp);
        }
        return ans;
    }
};