class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        int n = potions.size(), low, high, mid;
        sort(potions.begin(), potions.end());
        for(auto i=0; i<spells.size(); i++){
            low = 0, high = n - 1;
            while(low<=high){
                mid = low + (high - low) / 2;
                long long ele = (long long) potions[mid] * (long long) spells[i];
                if(ele >= success){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            result.push_back(n - high - 1);
        }
        return result;
    }
};