class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), remove = 0;
        sort(intervals.begin(), intervals.end());
        stack<pair<int,int>> s;
        for(auto i=0; i<n; i++){
            pair<int,int> curInt = {intervals[i][0], intervals[i][1]};
            if(!s.empty() && curInt.first < s.top().second){
                if(s.top().second > curInt.second){
                    s.pop();
                    s.push(curInt);
                }
                remove++;
            }
            else{
                s.push(curInt);
            }
        }
        return remove;
    }
};