class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());

        // using stack
        // stack<pair<int,int>> s;
        // s.push({points[0][0], points[0][1]});
        // for(auto i=1; i<n; i++){
        //     pair<int,int> curInt = {points[i][0], points[i][1]};
        //     if(curInt.first <= s.top().second){ 
        //         curInt.first = max(curInt.first, s.top().first);
        //         curInt.second = min(curInt.second, s.top().second);
        //         s.pop();
        //     }
        //     s.push(curInt);
        // }
        // return s.size();

        int count = 1;
        pair<int,int> lastInt = {points[0][0], points[0][1]};
        for(auto i=1; i<n; i++){
            pair<int,int> curInt = {points[i][0], points[i][1]};
            if(curInt.first <= lastInt.second){
                lastInt.first = max(curInt.first, lastInt.first);
                lastInt.second = min(curInt.second, lastInt.second);
            }
            else{
                count++;
                lastInt = curInt;
            }
        }
        return count;
    }
};