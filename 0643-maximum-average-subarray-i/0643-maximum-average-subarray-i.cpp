class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = k;
        double averageSum = 0.0, nextSum = 0.0;
        for(auto m = 0; m < k; m++){
            nextSum += nums[m];
        }
        averageSum = nextSum / k;
        while(j < nums.size()){
            nextSum += nums[j] - nums[i];
            j++;
            i++;
            averageSum = max(averageSum, (nextSum / k));
        }
        return averageSum;
    }
};