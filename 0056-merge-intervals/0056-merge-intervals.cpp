class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto a, auto b){
            return a[0] < b[0];
        });

        int lastStart, lastEnd, currentStart, currentEnd;

        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        
        for(int i=1; i<intervals.size(); i++){
            auto lastInterval = ans.back();
            lastStart = lastInterval[0];
            lastEnd = lastInterval[1];

            currentStart = intervals[i][0];
            currentEnd = intervals[i][1];

            if(lastStart <= currentStart && currentEnd <= lastEnd){
                continue;
            }

            if(lastEnd < currentStart){
                ans.push_back({currentStart, currentEnd});
                continue;
            }

            if(lastStart < currentEnd && currentEnd < lastEnd){
                ans.back()[0] = currentStart;
            }
            else if(lastStart < currentStart & currentStart <= lastEnd){
                ans.back()[1] = currentEnd;
            }
            else{
                ans.back()[0] = currentStart;
                ans.back()[1] = currentEnd;
            }

        }
        return ans;
    }
};