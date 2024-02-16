class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int, int> hashMap;
        for(auto el: arr){
            hashMap[el]++;            
        }
        for(auto item: hashMap){
            pq.push({item.second, item.first});
        }
        while(k > 0){
            auto top = pq.top();
            pq.pop();
            top.first--;
            if(top.first){
                pq.push(top);   
            }
            k--;
        }
        return pq.size();
    }
};