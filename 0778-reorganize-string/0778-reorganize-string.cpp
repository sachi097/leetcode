class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> hm;
        for(auto ch: s){
            hm[ch]++;
        }
        for(auto ele: hm){
            pq.push({ele.second, ele.first});
        }

        string result = "";

        while(!pq.empty()){
            auto currTop = pq.top();
            pq.pop();
            if(result.size() > 0 && result[result.size() - 1] == currTop.second){
                if(pq.empty()){
                    return "";
                }
                auto nextTop = pq.top();
                pq.pop();
                nextTop.first--;
                result += nextTop.second;
                if(nextTop.first){
                    pq.push(nextTop);
                }
            }
            else{
                currTop.first--;
                result += currTop.second;
            }

            if(currTop.first){
                pq.push(currTop);
            }
        }

        return result;
    }
};