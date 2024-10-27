class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result(m , vector<int>(n, INT_MAX));
        result[0][0] = 0;

        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int diff = top.first;
            auto pos = top.second;
            int i = pos.first;
            int j = pos.second;

            if(i == m-1 && j == n-1)
                return diff;

            for(auto k=0; k<4; k++){
                int nextI = i + dir[k][0];
                int nextJ = j + dir[k][1];

                if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n){
                    int nextDiff = max(diff, abs(heights[i][j] - heights[nextI][nextJ]));
                    if(nextDiff < result[nextI][nextJ]){
                        result[nextI][nextJ] = nextDiff;
                        pq.push({nextDiff, {nextI, nextJ}});
                    }
                }
            }

        }

        return result[m-1][n-1];
    }
};