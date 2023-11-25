class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), remove = 0;
        sort(intervals.begin(), intervals.end());
        
        // using stack
        // stack<pair<int,int>> s;
        // for(auto i=0; i<n; i++){
        //     pair<int,int> curInt = {intervals[i][0], intervals[i][1]};
        //     if(!s.empty() && curInt.first < s.top().second){
        //         if(s.top().second > curInt.second){
        //             s.pop();
        //             s.push(curInt);
        //         }
        //         remove++;
        //     }
        //     else{
        //         s.push(curInt);
        //     }
        // }
        
        pair<int,int> lastInt = {intervals[0][0], intervals[0][1]};
        for(auto i=1; i<n; i++){
            pair<int,int> curInt = {intervals[i][0], intervals[i][1]};
            if(curInt.first < lastInt.second){
                if(lastInt.second > curInt.second){
                    lastInt = curInt;
                }
                remove++;
            }
            else{
                lastInt = curInt;
            }
        }
        
        return remove;
    }
};