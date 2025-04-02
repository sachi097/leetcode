class Solution {
public:
    bool canFormGroups(vector<int>& usageLimits, int groups){
        int requiredGroups = 0;
        int n = usageLimits.size();
        for(int i=0; i<n; i++){
            if(groups > 0){
                requiredGroups += groups--;
            }
            requiredGroups -= min(requiredGroups, usageLimits[n - i - 1]);
        }
        return requiredGroups == 0;
    }

    int maxIncreasingGroups(vector<int>& usageLimits) {
         int low = 1, high = usageLimits.size();
         sort(usageLimits.begin(), usageLimits.end());
         int ans = 0;
         while(low <= high){
            int mid = low + (high - low) / 2;
            if(canFormGroups(usageLimits, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
         }
         return ans;
    }
};