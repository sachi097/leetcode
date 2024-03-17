class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sortedIntervals;
        int n = intervals.size(), i=0, j=0;
        stack<vector<int>> s;
        while(i < n && j < 1){
            if(intervals[i][0] < newInterval[0] || (intervals[i][0] == newInterval[0] && intervals[i][1] < newInterval[1])){
                sortedIntervals.push_back(intervals[i]);
                i++;
            }
            else{
                sortedIntervals.push_back(newInterval);
                j++;
            }
        }
        while(i<n){
            sortedIntervals.push_back(intervals[i]);
            i++;
        }
        while(j<1){
            sortedIntervals.push_back(newInterval);
            j++;
        }
        s.push(sortedIntervals[0]);
        i = 1;
        while(i < n + 1){
            auto topInterval = s.top();
            if(sortedIntervals[i][0] <= topInterval[1]){
                s.pop();
                topInterval[1] = topInterval[1] > sortedIntervals[i][1] ? topInterval[1] : sortedIntervals[i][1];
                s.push(topInterval);
            }
            else{
               s.push(sortedIntervals[i]);
            }
            i++;
        }
        sortedIntervals.clear();
        while(!s.empty()){
            sortedIntervals.push_back(s.top());
            s.pop();
        }
        reverse(sortedIntervals.begin(), sortedIntervals.end());
        return sortedIntervals;
    }
};