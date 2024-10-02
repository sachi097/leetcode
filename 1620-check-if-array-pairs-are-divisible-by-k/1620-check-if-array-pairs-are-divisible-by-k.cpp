class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> countHashMap;
        for(auto element:arr){
            countHashMap[((element%k)+k)%k]++;
        }
        if(countHashMap[0]%2 != 0) return false;
        for(auto i=1; i<k; i++){
            if(countHashMap[i] != countHashMap[k-i]){
                return false;
            }
        }
        return true;
    }
};