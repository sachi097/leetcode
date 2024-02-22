class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> s;
        int candidateForJudge = 0;
        for(auto ele: trust){
            s.insert(ele[0]);
        }
        if(s.size() != n - 1)
            return -1;
        for(auto i=1; i<=n; i++){
            if(s.find(i) == s.end()){
                candidateForJudge = i;
                break;   
            }
        }
        int judgeCount = 0;
        for(auto ele: trust){
            if(candidateForJudge == ele[1])
                judgeCount++;
        }
        return judgeCount == n - 1 ? candidateForJudge : -1;
    }
};