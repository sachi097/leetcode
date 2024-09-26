class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int n = arr.size();
        int count = 0, preXor = 0;
        unordered_map<int, vector<int>> map;
        map[0].push_back(-1);
        for(int i=0; i<n; i++){
            preXor ^= arr[i];
            if(map.find(preXor) != map.end()){
                for(auto index: map[preXor]){
                    count += i - index - 1;
                }
            }
            map[preXor].push_back(i);
        }
        return count;
    }
};