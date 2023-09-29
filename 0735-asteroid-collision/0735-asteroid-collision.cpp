class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(auto el: asteroids){
           while(!result.empty() && el < 0 && result.back() > 0){
               int diff = el + result.back();
               if(diff < 0){
                   result.pop_back();
               }
               else if(diff > 0){
                   el = 0;
               }
               else{
                   el = 0;
                   result.pop_back();
               }
           }
           if(el){
               result.push_back(el);
           }
        }
        return result;
    }
};