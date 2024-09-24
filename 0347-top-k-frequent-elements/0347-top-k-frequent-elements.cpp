class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        vector<vector<int>> freq(nums.size() + 1);
        unordered_map<int, int> map;
        for(auto ele: nums){
            map[ele]++;
        }
        for(auto ele: map){
            freq[ele.second].push_back(ele.first);
        }
        int i = nums.size();
        while(k>0){
            ans.insert(ans.end(), freq[i].begin(), freq[i].end());
            k -= freq[i].size();
            i--;
        }
        return ans;
    }
};