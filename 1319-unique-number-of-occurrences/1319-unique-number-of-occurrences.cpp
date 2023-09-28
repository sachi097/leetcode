class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;
        unordered_set<int> set;
        for(auto i = 0; i < arr.size(); i++){
            hash[arr[i]] = 0;
        }
        for(auto i = 0; i < arr.size(); i++){
            hash[arr[i]]++;
        }
        for(auto el: hash){
            set.insert(el.second);
        }
        return set.size() == hash.size() ? true : false;
    }
};