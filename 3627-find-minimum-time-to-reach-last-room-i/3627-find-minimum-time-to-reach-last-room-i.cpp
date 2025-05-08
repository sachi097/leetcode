class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto currentNode = pq.top();
            pq.pop();
            int dist = currentNode.first;
            int x = currentNode.second.first;
            int y = currentNode.second.second;

            if(x == m-1 && y == n-1){
                return dist;
            }

            for(auto &dir: dirs){
                int nextI = x + dir[0];
                int nextJ = y + dir[1];

                if(nextI >= 0 && nextJ >= 0 && nextI < m && nextJ < n){
                    int waitTime = max(moveTime[nextI][nextJ] - dist, 0);
                    int finalTime = dist + waitTime + 1;

                    if(result[nextI][nextJ] > finalTime){
                        result[nextI][nextJ] = finalTime;
                        pq.push({finalTime, {nextI, nextJ}});
                    }
                }
            }
        }

        return -1;
    }
};