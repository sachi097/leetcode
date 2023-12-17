class FoodRatings {
public:
    
    unordered_map<string, set<pair<int, string>>> cuisinesMap;
    unordered_map<string, pair<string, int>> foodMap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(auto i=0; i<n; i++){
            (cuisinesMap[cuisines[i]]).insert({-ratings[i], foods[i]});
            foodMap[foods[i]] = {cuisines[i], ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodMap[food].first;
        int oldRating = foodMap[food].second;
        (cuisinesMap[cuisine]).erase({-oldRating, food});
        foodMap[food].second = newRating;
        (cuisinesMap[cuisine]).insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*(cuisinesMap[cuisine]).begin()).second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */