class Solution {
public:
    void solve(int idx, int n, int k, vector<int> &temp, vector<vector<int>> &result){

        if(k == 0){
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<=n; i++){
            temp.push_back(i);
            solve(i+1, n, k-1, temp, result);
            temp.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(1, n, k, temp, result);
        return result;
    }
};