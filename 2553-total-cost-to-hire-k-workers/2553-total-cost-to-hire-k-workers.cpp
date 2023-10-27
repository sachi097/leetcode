class Solution {
public:

    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pqL;
        priority_queue<int, vector<int>, greater<int>> pqR;
        int left = 0, right = n - 1;
        long long finalCost = 0;
        for(auto i=0; i<k; i++){
            while(pqL.size() < candidates && left <= right){
                    pqL.push(costs[left]);
                    left++;
            }
            while(pqR.size() < candidates && right >= left){
                pqR.push(costs[right]);
                right--;
            }
            int minL = !pqL.empty() ? pqL.top() : INT_MAX;
            int minR = !pqR.empty() ? pqR.top() : INT_MAX;
            int min;
            if(minL <= minR){
                pqL.pop();
                min = minL;
            }
            else{
                pqR.pop();
                min = minR;
            }
            finalCost += min;
        }

        return finalCost;
    }
};