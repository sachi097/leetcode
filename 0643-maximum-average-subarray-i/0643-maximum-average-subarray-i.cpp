class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = k;
        double averageSum = 0.0, nextSum = 0.0;
        for(auto m = 0; m < k; m++){
            nextSum += nums[m];
        }
        averageSum = nextSum / k;
        while(right < nums.size()){
            nextSum += nums[right] - nums[left];
            right++;
            left++;
            averageSum = max(averageSum, (nextSum / k));
        }
        return averageSum;
    }
};