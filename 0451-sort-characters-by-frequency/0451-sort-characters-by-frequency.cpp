class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hashMap;
        priority_queue<pair<int, char>> pq;
        for(auto ch: s){
            hashMap[ch]++;
        }
        for(auto item: hashMap){
            pq.push({item.second, item.first});
        }
        string ans = "";
        while(!pq.empty()){
            auto topItem = pq.top();
            while(topItem.first > 0){
                ans += topItem.second;
                topItem.first--;
            }
            pq.pop();
        }
        return ans;
    }
};