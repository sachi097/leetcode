class Solution {
private:
    void fast(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        fast();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto num: intervals){
            if(res.empty() || res.back()[1] < num[0]){
                res.push_back(num);
            }
            else{
                res.back()[1]=max(res.back()[1], num[1]);
            }
        }
        return res;
    }
};