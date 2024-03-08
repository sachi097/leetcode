class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maximumFreq = INT_MIN;
        unordered_map<int,int> hashMap;
        for(auto num: nums){
            hashMap[num]++;
            maximumFreq = max(maximumFreq, hashMap[num]);
        }
        int count = 0;
        for(auto el: hashMap){
            if(el.second == maximumFreq){
                count += el.second;
            }
        }
        return count;
    }
};