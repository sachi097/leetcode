class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        for(auto i=0; i<prices.size(); i++){
            if(prices[i] < smallest){
                secondSmallest = smallest;
                smallest = prices[i];
            }
            else if(prices[i] < secondSmallest){
                secondSmallest = prices[i];
            }
        }
        if(money - secondSmallest - smallest >= 0){
            return money - secondSmallest - smallest;
        }
        else{
            return money;
        }
    }
};