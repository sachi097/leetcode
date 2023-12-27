class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, prevTime = INT_MAX;
        for(auto i=1; i<colors.size(); i++){
            if(colors[i - 1] == colors[i]){
                if(prevTime == INT_MAX){
                    ans += min(neededTime[i - 1], neededTime[i]);
                    prevTime = max(neededTime[i - 1], neededTime[i]);
                }
                else{
                    ans += min(prevTime, neededTime[i]);
                    prevTime = max(prevTime, neededTime[i]);
                }
            }
            else{
                prevTime = INT_MAX;
            }
        }
        return ans;
    }
};