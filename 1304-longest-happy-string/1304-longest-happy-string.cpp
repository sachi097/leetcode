class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a > 0){
            pq.push({a, 'a'});
        }

        if(b > 0){
            pq.push({b, 'b'});
        }

        if(c > 0){
            pq.push({c, 'c'});
        }

        string result = "";

        while(!pq.empty()){
            auto currTop = pq.top();
            pq.pop();
            if(result.size() > 1 && result[result.size() - 1] == currTop.second && result[result.size() - 2] == currTop.second){
                if(pq.empty()){
                    return result;
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