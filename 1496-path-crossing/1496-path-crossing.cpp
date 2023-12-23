class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> origin = {0, 0};
        set<pair<int, int>> prevPoints;
        unordered_map<char, pair<int, int>> hash;
        hash['N'] = {0, 1};
        hash['S'] = {0, -1};
        hash['E'] = {1, 0};
        hash['W'] = {-1, 0};
        prevPoints.insert(origin);
        for(auto ch: path){
            pair nextPoint = {origin.first + hash[ch].first , origin.second + hash[ch].second};
            if(prevPoints.find(nextPoint) != prevPoints.end()){
                return true;
            }
            prevPoints.insert(nextPoint);
            origin = nextPoint;
        } 
        return false;
    }
};