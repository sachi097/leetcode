class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefixSum = 0, largestAltitude = 0;
        for(auto i=0; i<gain.size(); i++){
            prefixSum += gain[i];
            largestAltitude = max(largestAltitude, prefixSum);
        }
        return largestAltitude;
    }
};