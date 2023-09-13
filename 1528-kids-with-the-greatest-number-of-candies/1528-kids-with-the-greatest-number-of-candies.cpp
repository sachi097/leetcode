class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       vector<bool> result(candies.size(), 0); 
       int max = *max_element(candies.begin(), candies.end());
       for(auto i = 0; i < candies.size(); i++){
           if(candies[i] + extraCandies >= max){
               result[i] = true;
           }
       }
       return result;
    }
};