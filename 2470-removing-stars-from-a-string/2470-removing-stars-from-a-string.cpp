class Solution {
public:
    string removeStars(string s) {
        string result;
        for(auto el: s){
            if(el == '*'){
                result.pop_back();
            }
            else{
                result.push_back(el);
            }
        }
        return result;
    }
};