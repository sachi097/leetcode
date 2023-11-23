class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, mid, n = piles.size(), answer;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            mid = low + (high - low) / 2;
            long tempSum = 0;
            for(auto i=0; i<n; i++){
                tempSum += ceil((double) piles[i] / (double) mid); 
            }
            if(tempSum <= h){
                answer = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }         
        }
        return answer;
    }
};