class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int, int> index;
        for(auto i=0; i<n; i++){
            index[score[i]] = i;
        }
        vector<string> ans(n);
        sort(score.begin(), score.end(), greater<int>());
        string rank;
        for(auto i=0; i<n; i++){
            rank = "";
            switch(i){
                case 0: rank = "Gold Medal";
                        break;
                case 1: rank = "Silver Medal";
                        break;
                case 2: rank = "Bronze Medal";
                        break;
                default: rank = to_string(i+1);
            }
            ans[index[score[i]]] = rank;
        }
        return ans;
    }
};