class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, pair<int, queue<int>>> map;
        int left = 0, right = 0, n = nums.size(), maxLen = INT_MIN;
        while(right < n){
            map[nums[right]].first++;
            map[nums[right]].second.push(right);
            if(map[nums[right]].first > k){
                map[nums[right]].first--;
                left = max(left, map[nums[right]].second.front() + 1);
                map[nums[right]].second.pop();
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};